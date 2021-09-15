#include <stdio.h>

typedef void Exitfunc(void);

int atexit(Exitfunc *f);
