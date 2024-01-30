#include "main.h"

void
myPrintf(char* str)
{
    syscall(SYS_CUSTOM_write, 1, str, strlen(str));
}
