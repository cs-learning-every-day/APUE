#include "apue.h"

#define NEW_MAXLINE 4

int main() {
    // 缓存区大小不影响 
    char buf[MAXLINE];

    int count = 0;
    while (fgets(buf, NEW_MAXLINE, stdin) != NULL) {
        if (fputs(buf, stdout) == EOF)
            perror("output error");
    }
        
    if (ferror(stdin))
        perror("input error");
    exit(0);
}