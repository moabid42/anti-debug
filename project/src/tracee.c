#include "main.h"

void
tracee(void)
{
    ptrace(PTRACE_TRACEME, 0, 0, 0);
    raise(SIGCONT);
    printf("I am dependent on my Parent!\n");
    // myPrintf("I'm your printf\n");
}
