#include <time.h>
#include <stdio.h>

int main() {
    // typedef long time_t 不同系统不一样
    time_t t;
    // 1970 + 2^64 / (365 * 24 * 60 * 60)
    // 超出会溢出，时间变负
    return 0;
}