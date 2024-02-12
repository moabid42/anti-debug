#include "main.h"

bool
program_start(void)
{
    pid_t child_pid = fork();

    if (child_pid < 0)
    {
        printf("Fork failed.\n");
        return (true);
    }
    if (child_pid == 0)
        tracee();
    else
        tracer(child_pid);
    return (false);
}

int
main(void)
{
    printf("Anti-debug Playground ~ \n");
    if (program_start() == true)
        return (1);
    return 0;
}
