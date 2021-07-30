#include "apue.h"
#include <errno.h>
#include <limits.h>
#include <unistd.h>
#include <sys/resource.h>

#ifdef OPEN_MAX
static long openmax = OPEN_MAX;
#else
static long openmax = 0;
#endif

long open_max(void);
long resource_max(void);

long open_max(void)
{
    if (openmax == 0)
    {
        errno = 0;

        if ((openmax = sysconf(_SC_OPEN_MAX)) < 0)
        {
            if (errno == 0)
            {
                // 不确定值

                // 获取资源限制的值
                openmax = resource_max();
            }
            else
            {
                err_sys("sysconf error for _SC_OPEN_MAX");
            }
        }
        else
        {
            printf("get _SC_OPEN_MAX\n");
        }
    }
    return openmax;
}

long resource_max(void)
{
    printf("get _RLIMIT_NOFILE\n");
    struct rlimit rlim = {};
    if (getrlimit(RLIMIT_NOFILE, &rlim) == 0)
    {
        return rlim.rlim_max;
    }
    else
    {
        err_sys("getrlimit error for RLIMIT_NOFILE");
    }
}

int main()
{
    printf("%ld\n", open_max());
    printf("%ld\n", resource_max());
    return 0;
}