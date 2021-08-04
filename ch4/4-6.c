#include "apue.h"
#include <fcntl.h>


int main(int argc, char *argv[])
{
    // if (argc != 3) {
    //     err_quit("Usage: %s <source> <target>", argv[0]);
    // }
    argv[1] = "file.hole";
    argv[2] = "file.nohole";
    
    int source_fd, target_fd;
    if ((source_fd = open(argv[1], O_RDONLY)) < 0) {
        err_sys("open %s error", argv[1]);
    }

    if ((target_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0666)) < 0) {
        err_sys("open %s error", argv[2]);
    }

    int		n;
	char    buf = '\0';

    while ((n = read(source_fd, &buf, 1)) > 0) {
        if (buf != '\0') {
            if (write(target_fd, &buf, 1) != 1) {
                err_sys("write error");
            }
        } else { // skip hole
            if (lseek(source_fd, 1, SEEK_CUR) == -1) {
                err_sys("lseek error");
            }
        }
    }

    if (n < 0) {
        err_sys("read error");
    }
    
    exit(EXIT_SUCCESS);
}