#include "apue.h"
#include <fcntl.h>

static const char *kDirectoryName = "test";
static long path_max;
static long file_name_max;

static void test_10_times(char *buf);
static void test_dead_cycle(char *buf);

int main(int argc, char *argv[])
{
    path_max = pathconf(".", _PC_PATH_MAX);
    file_name_max = pathconf(".", _PC_NAME_MAX);
    printf("PATH_MAX = %ld\n", path_max);
    printf("FILE_NAME_MAX = %ld\n", file_name_max);

    // char buf[path_max];
    // test_10_times(buf);

    char buf[path_max*2];
    test_dead_cycle(buf);

    exit(EXIT_SUCCESS);
}

static void test_10_times(char *buf)
{
    int i = 0;
    while (i < 10)
    {
        if (mkdir(kDirectoryName, 0777) < 0)
        {
            err_sys("mkdir error");
        }
        chdir(kDirectoryName);
        char *cur_path = getcwd(buf, path_max);
        printf("current path %s\n", cur_path);
        i++;
    }
}


/*
Result:
    PATH_MAX = 4096
    FILE_NAME_MAX = 255
    current path length 8188
    getcwd error: Numerical result out of range

生成的test文件夹,没有权限的文件 git提交不了，

表明getcwd可以正常工作，即使路径已经超出PATH_MAX。
tar -czvf test.tar.gz test 能正常工作
*/

static void test_dead_cycle(char *buf)
{
    int len = 0;
    while (1)
    {
        if (mkdir(kDirectoryName, 0777) < 0)
        {
            err_sys("mkdir error");
        }
        chdir(kDirectoryName);
        char *cur_path = getcwd(buf, path_max*2);
        if (cur_path == NULL) {
            printf("current path length %d\n", len);
            err_sys("getcwd error");
        } else {
            len = strlen(cur_path);
        }
    }
}