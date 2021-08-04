#include "apue.h"
#include <fcntl.h>

#define RWRWRW (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)

int main(void)
{
    // 如果已经存在foo,bar。 则会重置文件
    umask(0);
    if (creat("foo", RWRWRW) < 0) {
        err_sys("creat error for foo");
    }

    umask(S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);

    if (creat("bar", RWRWRW) < 0) {
        err_sys("creat error for bar");
        exit(0);
    }
}