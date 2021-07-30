#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define FILE_NAME "dup_test_file"

int main(void)
{

    //先调用dup将标准输出拷贝一份，指向真正的标准输出
    int stdout_copy_fd = dup(STDOUT_FILENO); //此时stdout_copy_fd也指向标准输出
    int file_fd = open(FILE_NAME, O_RDWR);   //file_fd是文件"dup_test_file"的文件描述符

    //让标准输出指向文件
    dup2(file_fd, STDOUT_FILENO); //首先关闭1所指向的文件，然后再使文件描述符1指向file_fd
    printf("hello");              //使用stdout输出"hello"，此时stdout已经被重定向到file_fd，相当于把其输出到文件中

    fflush(stdout); //刷新缓冲区 输出到stdout

    //恢复标准输出
    dup2(stdout_copy_fd, STDOUT_FILENO);
    printf("world\n");
    return 0;
}