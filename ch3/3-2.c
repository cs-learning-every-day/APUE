#include "apue.h"
#include <fcntl.h>
#include <unistd.h>

int my_dup2(int fd, int fd2);

int main(int argc, char *argv[])
{
    int fd = my_dup2(STDOUT_FILENO, 13);
    char *str = "Kevin\n";
    printf("%ld\n", strlen(str));
    write(13, str, strlen(str));
    return 0;
}

int my_dup2(int fd, int fd2)
{
    if (fd == fd2)
    {
        return fd2;
    }

    close(fd2);

    // dup返回当前可用fd的最小值
    int begin_fd = dup(fd);
    if (begin_fd == -1)
    {
        err_sys("dup error\n");
    }

    // 遍历创建直到等于fd2
    int cur_fd = begin_fd;
    while (cur_fd != fd2)
    {
        cur_fd = dup(fd);
        if (cur_fd == -1)
        {
            err_sys("dup error\n");
        }
    }
    // 中间有已经有创建过的fd的话，未处理，可以在此区间加一个在使用中的数组
    for (cur_fd = begin_fd; cur_fd < fd2; ++cur_fd)
    {

        if (close(cur_fd) == -1)
        {
            err_sys("close fd % error\n", cur_fd);
        }
    }
    return fd2;
}