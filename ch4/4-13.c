#include "apue.h"
#include <fcntl.h>
#include <sys/time.h>
#include <time.h>


int main(int argc, char *argv[])
{
    int i, fd;
    struct stat statbuf;
    struct timeval times[2];

    argv[1] = "4-13-tst";

    if (stat(argv[1], &statbuf) < 0) {
        err_sys("%s: stat error", argv[1]);
    }

    if ((fd = open(argv[1], O_RDWR | O_TRUNC)) < 0) {
        err_sys("%s: open error", argv[1]);
    }


    // 访问时间
    times[0].tv_sec = statbuf.st_atim.tv_sec;
    times[0].tv_usec = statbuf.st_atim.tv_nsec / 1000;

    // 修改时间
    time_t current = time(NULL);
    times[1].tv_sec = current;
    times[1].tv_usec = 0;

    if (utimes(argv[1], times) < 0) {
        err_sys("utimes error");
    }

    close(fd);
    exit(EXIT_SUCCESS);
}