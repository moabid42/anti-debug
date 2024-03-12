#include "main.h"

void
tracee(void)
{
    ptrace(PTRACE_TRACEME, 0, 0, 0);
    raise(SIGCONT);
    write("ccccccc\n", 1, 9);
}
