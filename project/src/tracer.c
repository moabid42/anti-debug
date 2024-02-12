#include "main.h"

void
tracer(pid_t child_pid)
{
    int                     status;
    struct user_regs_struct regs;

    waitpid(child_pid, &status, 0);
    if (!WIFSTOPPED(status))
    {
        printf("Incorrect state.\n");
        return;
    }
    ptrace(PTRACE_SETOPTIONS, child_pid, 0, PTRACE_KILL);
    while (WIFSTOPPED(status))
    {
        ptrace(PTRACE_SYSCALL, child_pid, 0, 0);
        waitpid(child_pid, &status, 0);
        ptrace(12, child_pid, 0, &regs);
        if (regs.orig_rax == SYS_CUSTOM_write)
        {
            regs.orig_rax = 1;
            ptrace(13, child_pid, 0, &regs);
        }
    }
}
