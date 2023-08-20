#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <errno.h>

// Autor: Mateusz Migdał
// Data: 2023-04-06
// Opis:

#define _POSIX_C_SOURCE 200112L
#define _XOPEN_SOURCE 500
#define _GNU_SOURCE

int main(int argc, char *argv[])
{
    // arg[1] = ilosc powtorzen; arg[2] = co zrobic z sygnalem; arg[3] = sygnal
    // Poprawne uzycie!!! 1 - obsluga sygnalu 2 - id sygnalu 3 - ilosc powtorzen
    if (argc != 4)
    {
        printf("Brak argumentow");
    }
    pid_t pid = fork();
    pid_t wpid;
    int status;
    switch (pid)
    {
    case -1:
        perror("fork error");
        exit(EXIT_FAILURE);
    case 0:
        // proces potomny

        if (setpgid(0, 0) == -1)
        {
            perror("setpgid error");
            exit(EXIT_FAILURE);
        }
        printf("PID %d\n", getpid());
        // break;
        execlp("./help1.x", "help1.x", argv[1], argv[2], argv[3], (char *)NULL);
        // sleep(3);
        error("execlp error");
        exit(EXIT_FAILURE);
    default:
        sleep(1);
        // pid_t temp = getpgid(pid);
        // printf("PID: %d\n", temp);
        kill(-pid, SIGINT);
        sleep(4);
        if (wait(&status) == -1)
        {
            perror("wait error");
            exit(EXIT_FAILURE);
        }
        if (WIFEXITED(status))
        {
            printf("Child process %d exited normally with status %d\n", pid, WEXITSTATUS(status));
        }
        else if (WIFSIGNALED(status))
        {
            printf("Child process %d terminated by signal %d (%s)\n", pid, WTERMSIG(status), strsignal(WTERMSIG(status)));
        }

        sleep(15);
        return 0;
    }
}
