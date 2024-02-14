#include "main.h"

extern ssize_t __libc_write_internal(int fd, char* buf, size_t len);

void
tracee(void)
{
    ptrace(PTRACE_TRACEME, 0, 0, 0);
    raise(SIGCONT);
    write(1, "I am dependent on my Parent!\n", 30);
    printf("I am dependent on my Parent as well!\n");
}
