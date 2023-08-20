#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    pid_t pid = fork();
    switch (pid)
    {
    case -1:
        perror("fork error");
        exit(EXIT_FAILURE);
    case 0:
        // proces potomny
        break;
    default:
        // proces macierzysty
        printf("PID procesu macierzystego: %d, PID procesu potomnego: %d\n", getpid(), pid);
        break;
    }
}