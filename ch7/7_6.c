#include <stdio.h>
#include <stdlib.h>

int main() {
    long** p = calloc(3, sizeof(long*));
    if (p[0] == NULL &&
        p[1] == NULL &&
        p[2] == NULL) {
        printf("yes\n");
        exit(0);
    }
    printf("no\n");
    exit(0);
}