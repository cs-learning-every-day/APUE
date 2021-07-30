#include <stdio.h>

int main(void)
{
    /* 
    1:标准输出
    2:标准错误
    2>&1 将标准错误重定向到标准输出
    ./3-5 > outfile 2>&1  相当于dup2(filefd, stdout); dup2(stdout, stderr);
    ./3-5 2>&1 > outfile  相当于dup2(stdout, stderr); dup2(filefd, stdout);
    */
    fprintf(stdout, "stdout\n");
    fprintf(stderr, "stderr\n");
}