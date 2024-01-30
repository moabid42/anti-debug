#include "main.h"

void
tracee(void)
{
    ptrace(PTRACE_TRACEME, 0, 0, 0);
    raise(SIGCONT);
    printf("I am a standart printf\n");
    myPrintf("I'm your printf\n");
}
