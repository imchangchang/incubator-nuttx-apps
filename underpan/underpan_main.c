#include <nuttx/config.h>
#include <stdio.h>
#include <fcntl.h>
#include "mavlink/underpan/mavlink.h"
#include <string.h>
#include <poll.h>
#include <errno.h>
#include <sys/boardctl.h>

mavlink_system_t mavlink_system =
{
    .sysid = 123,
    .compid = 0
};

enum motor_status_e
{
    MOTOR_STOP, //no output
    MOTOR_BREAK,
    MOTOR_PWM,
    MOTOR_PID, //in pid control
};
static int fd_motor[4];
static int fd_uart;
static mavlink_underpan_control_t g_control_cmd;

static void pub_motor_status(void)
{
    mavlink_underpan_status_t status = {0};
    float spd[4] = {0};

    for (int i = 0; i < 4; i++)
    {
        uint8_t read_buf[5] = {0};
        uint8_t locked = 0;

        read(fd_motor[i], read_buf, 5);

        memcpy(&spd[i], read_buf, sizeof(spd[i]));
        locked = read_buf[4];
        status.under_status |= locked;
    }
    status.speed1 = spd[0];
    status.speed2 = spd[1];
    status.speed3 = spd[2];
    status.speed4 = spd[3];
    printf("send:%d %d %d %d\n", status.speed1, status.speed2, status.speed3, status.speed4);
    // printf("send:%.1f %.1f %.1f %.1f %d\n", spd[0], spd[1],spd[2], spd[3], status.under_status);

    mavlink_message_t msg = {0};
    mavlink_msg_underpan_status_encode(mavlink_system.sysid, mavlink_system.compid, &msg, (const mavlink_underpan_status_t *)&status);

    uint8_t send_buf[512];
    size_t msg_len = mavlink_msg_to_send_buffer(send_buf, &msg);

    write(fd_uart, send_buf, msg_len);
}
static void mavlink_decode_payload(const mavlink_message_t *msg)
{
    mavlink_underpan_control_t control;
    switch(msg->msgid)
    {
    case MAVLINK_MSG_ID_UNDERPAN_CONTROL:
        mavlink_msg_underpan_control_decode(msg, &control);
        if (control.control_command != g_control_cmd.control_command)
        {
            printf("Change control command:%d->%d\n", g_control_cmd.control_command, control.control_command);
            for (int i = 0; i < 4; i++)
            {
                ioctl(fd_motor[i], control.control_command);
            }
        }
        g_control_cmd = control;
        if (g_control_cmd.control_command == MOTOR_CMD_PWM ||
                g_control_cmd.control_command == MOTOR_CMD_SPEED)
        {

            write(fd_motor[0], &g_control_cmd.cmd1, sizeof(int32_t));
            write(fd_motor[1], &g_control_cmd.cmd2, sizeof(int32_t));
            write(fd_motor[2], &g_control_cmd.cmd3, sizeof(int32_t));
            write(fd_motor[3], &g_control_cmd.cmd4, sizeof(int32_t));
        }
        break;
    default:
        break;
    }
}
static void mavlink_parse(void)
{
    static uint8_t buf[512] = {0};
    static size_t  len = 0;
    struct pollfd pfds = {0};

    pfds.fd = fd_uart;
    pfds.events = POLLIN;
    pfds.events = 0;

    if (poll(&pfds, 1, 0) > 0 && (pfds.events & POLLIN))
    {
        size_t read_len = read(fd_uart, buf+len, 512-len);
        size_t last_pack_index = 0;

        mavlink_message_t r_msg = {0};
        mavlink_status_t r_mavlink_status = {0};

        for (int i = 0; i < read_len+len; i++)
        {
            if (mavlink_parse_char(MAVLINK_COMM_0, buf[i], &r_msg, &r_mavlink_status) == 1)
            {
                last_pack_index = i;
                mavlink_decode_payload((const mavlink_message_t *)&r_msg);
            }
        }
        len = read_len+len-last_pack_index;
        if (len > 0)
            memmove(buf, buf+last_pack_index, len);
    }
}

static int motor_task(int argc, char * argv[])
{
    fd_uart = open("/dev/ttyS1", O_RDWR);

    for (int i = 0; i < 4; i++)
    {
        char dev[20] = {0};
        snprintf(dev, 20, "/dev/motor%d", i);
        fd_motor[i] = open(dev, O_RDWR);
        printf("Open motor:%s %d ->%d\n", dev, errno, fd_motor[i]);

        ioctl(fd_motor[i], MOTOR_STOP, NULL);
    }


    while (1)
    {
        mavlink_parse();
        pub_motor_status();
        usleep(20*1000);
    }

    for (int i = 0; i < 4; i++)
    {
        close(fd_motor[i]);
    }
    return 0;
}


int main(int argc, char * argv[])
{
    boardctl(BOARDIOC_INIT, 0);
    task_create("MotorTask", 120,4096, motor_task, NULL);
    return 0;
}
