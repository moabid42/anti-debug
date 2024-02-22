#include "main.h"

// extern ssize_t __libc_write_internal(int fd, char* buf, size_t len);

void
tracee(void)
{
    ptrace(PTRACE_TRACEME, 0, 0, 0);
    raise(SIGCONT);
    // write("I am dependent on my Parent, but NOT scrambled, so I won't work!\n", 65, 1);
    // write("I am dependent on my Parent, scrambled, so I will work!\n", 1, 56);
    write("ccccccc\n", 1, 9);
}
