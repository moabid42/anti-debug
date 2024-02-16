#include "main.h"

void    new(long long unsigned int n)
{
    char    c;

    if (n > 9)
        new(n / 10);
    c = n % 10 + '0';
    write(&c, 1, 1);
}

extern ssize_t __libc_write(int fd, char* buf, size_t len);
#include <unistd.h>
#include <sys/syscall.h>
void
tracer(pid_t child_pid)
{
    int                     status;
    struct user_regs_struct regs;

    waitpid(child_pid, &status, 0);
    if (!WIFSTOPPED(status))
    {
        write("Incorrect state.\n", 2, 17);
        return;
    }
    ptrace(PTRACE_SETOPTIONS, child_pid, 0, PTRACE_KILL);
    while (WIFSTOPPED(status))
    {
        ptrace(PTRACE_SYSCALL, child_pid, 0, 0);
        waitpid(child_pid, &status, 0);
        ptrace(12, child_pid, 0, &regs); // PTRACE_GETREGS
        if (regs.orig_rax == SYS_CUSTOM_write)
        {
            regs.orig_rax = 1;
            // syscall(1, "I am inside the write in libc\n", 31);
            const void *buffer = "hello world\n";
            regs.rsi = (long long unsigned int)buffer;
            regs.rdx = 12;
            ptrace(13, child_pid, 0, &regs); // PTRACE_SETREGS
        }
    }
}
