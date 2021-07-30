#include "apue.h"
#include <unistd.h>
#include <fcntl.h>

#define FILE_NAME "xxx.txt"
const int kOpenFlag = O_RDWR | O_APPEND;

int main(void)
{
    int fd;
    fd = open(FILE_NAME, kOpenFlag);
    if (fd == -1)
    {
        err_sys("open %s error\n", FILE_NAME);
    }

    // 读 在open模式下 可以设置当前偏移
    int res;
    if ((res = lseek(fd, 3, SEEK_SET)) == -1)
    {
        err_sys("lseek error\n");
    }

    char buffer[BUFSIZ];
    // kevin
    read(fd, buffer, 5);
    printf("%s\n", buffer);

    // 写 在open模式下 当前偏移会在末尾
    // 否则 内容应该是 000KevinSun000
    write(fd, "Sun", 3);

    return 0;
}