#include "apue.h"
#include <fcntl.h>

int main(int argc, char *argv[]) {
    int fd;
    //  /dev 目录关闭了其他用户的写权限
    if (unlink(argv[1]) == -1) {
        err_sys("unlink error");
    }
    if ((fd = creat(argv[1], FILE_MODE)) < 0) {
        err_sys("create error");
    }
    return 0;
}