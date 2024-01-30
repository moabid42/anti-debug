#include "main.h"

void
tracer(pid_t child_pid)
{
    int                     status;
    struct user_regs_struct regs;

    waitpid(child_pid, &status, 0);
    if (!WIFSTOPPED(status))
    {
        dprintf(2, "Incorrect state.\n");
        return;
    }
    ptrace(PTRACE_SETOPTIONS, child_pid, 0, PTRACE_O_EXITKILL);
    while (WIFSTOPPED(status))
    {
        ptrace(PTRACE_SYSCALL, child_pid, 0, 0);
        waitpid(child_pid, &status, 0);
        ptrace(PTRACE_GETREGS, child_pid, 0, &regs);
        if (regs.orig_rax == SYS_CUSTOM_write)
        {
            regs.orig_rax = SYS_write;
            ptrace(PTRACE_SETREGS, child_pid, 0, &regs);
        }
    }
}
