#include <nuttx/nuttx.h>
#include <nuttx/semaphore.h>
#include <fcntl.h>

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define USART_DEV "/dev/ttyS1"
#define BUF_SIZE (512)
#define SENSOR_NDATA (10)
#define SENSOR_DEBUG (1)

struct sensor_output
{
    sem_t sem;
    uint32_t data[SENSOR_NDATA];
} g_sensor;

#define PACK_LEN (58)
//buf[58]
static bool check_buf(char *buf)
{
    bool find_pack = false;
    if (buf[14] == 0x10 && buf[15] == 0x01)
    {
        find_pack = true;
    }

    if (find_pack)
    {
        #if SENSOR_DEBUG
        printf(">");
        #endif
        char tmp_buf[sizeof(uint32_t) * SENSOR_NDATA];
        for (int i = 0; i < sizeof(uint32_t) * SENSOR_NDATA; i++)
        {
            tmp_buf[i] = buf[16 + i] ^ (buf[6] & 0xff);
        }
        int ret = 0;
        ret = sem_wait(&g_sensor.sem);
        memcpy((void *)g_sensor.data, &tmp_buf[0], sizeof(uint32_t) * SENSOR_NDATA);
        ret = sem_post(&g_sensor.sem);
        #if SENSOR_DEBUG
        uint32_t sum = 0;
        int32_t avr = 0;
        for (int i = 0; i < SENSOR_NDATA; i++)
        {
        //    printf(" (%04d) ", g_sensor.data[i]);
           sum += g_sensor.data[i];
        }
        avr = sum/SENSOR_NDATA;

        // printf("->%d\n", avr);
        float avg_err= 0;
        for (int i = 0; i < SENSOR_NDATA; i++)
        {
            float err = (float)g_sensor.data[i] - avr;
            avg_err = err*err;
        }
        avg_err /= SENSOR_NDATA;
        avg_err = sqrt(avg_err);
        float avr_2_7 = (float)(g_sensor.data[2] + g_sensor.data[7])/2.0f;
        printf("%d %d %d\n", (int)(g_sensor.data[2] - avr_2_7), 
                             (int)(g_sensor.data[7]-avr_2_7), 
                             (int)(g_sensor.data[2]-g_sensor.data[7]));

        fflush(stdout);
        #endif
    }
    return find_pack;
}

static char buf[BUF_SIZE];
static size_t len = 0;

static int last_head_pos = -1;

static int protocol_task(int argc, char *argv[])
{
    int fd = open(USART_DEV, O_RDONLY);
    sem_init(&g_sensor.sem,0,1);
    while (1)
    {
        size_t read_len = read(fd, buf + len, BUF_SIZE - len);

        int header_pos = 0;
        for (int i = 0; i < read_len + len; i++)
        {
            if (buf[i] == 0xaa)
            {
                if ((i + PACK_LEN) < (read_len + len))
                {
                    bool ret = check_buf(buf + i);
                    if (ret)
                    {
                        i += PACK_LEN;
                        last_head_pos = -1;
                    }
                    else
                    {
                        last_head_pos = i;
                    }
                }
                else
                {
                    last_head_pos = i;
                }
            }
        }
        if (last_head_pos == -1)
        {
            len = 0;
        }
        else
        {
            memmove(buf, buf + last_head_pos, (read_len + len) - last_head_pos);
            len = (read_len + len) - last_head_pos;
        }

        usleep(20 * 1000);
    }
    return OK;
}

int main(int argc, FAR char *argv[])
{
    printf("This is protocols_main:\n");
    for (int i = 0; i < argc; i++)
    {
        printf("[%d]%s\n", i, argv[i]);
    }

    int ret = task_create("Protocol task", 120, 2048, protocol_task, NULL);
    return OK;
}