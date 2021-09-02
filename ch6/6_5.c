#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // ./6_5
    // Thu Sep 02 13:47:25 CST 2021

    // TZ=Japan ./6_5
    // Thu Sep 02 14:47:39 JST 2021

    time_t t;
    struct tm *tmp;

    time(&t);
    tmp = localtime(&t);

    char buf[64];
    if (strftime(buf, 64, "%a %b %d %T %Z %Y", tmp) == 0)
        printf("buffer length 64 is too small\n");
    printf("%s\n", buf);
    return 0;
}