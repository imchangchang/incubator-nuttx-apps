#include <nuttx/nuttx.h>
#include <fcntl.h>

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define USART_DEV "/dev/ttyS1"
#define BUF_SIZE (512)
#define PACK_PAYLOAD ()

struct sensor_output
{
    sem_t sem;
    float data[10];
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
        printf(">");
        for (int i = 0; i< PACK_LEN; i++)
        {
            printf("%02x ", buf[i]);
        }
        printf("\n");
        fflush(stdout);

    }
    return find_pack;
}

static char buf[BUF_SIZE];
static size_t len = 0;

static int last_head_pos = -1;

static int protocol_task(int argc, char *argv[])
{
    int fd = open(USART_DEV, O_RDONLY);
    while (1)
    {
        size_t read_len = read(fd, buf + len, BUF_SIZE - len);

        int header_pos = 0;
        for (int i = 0; i < read_len + len; i++)
        {
            if (buf[i] == 0xaa)
            {
                if ((i + PACK_LEN) < (read_len+len))
                {
                    bool ret = check_buf(buf+i);
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
        else{
            memmove(buf, buf+last_head_pos, (read_len+len)- last_head_pos);
            len = (read_len+len)-last_head_pos;
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