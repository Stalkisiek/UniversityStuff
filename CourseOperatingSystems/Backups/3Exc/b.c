#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

// Autor: Mateusz Migdał
// Data: 2023-04-06
// Opis: Program tworzy proces potomny, na ktorym zostaje postawiony program a.x, a nastepnie program potomny wysyla sygnal do procesu a.x uprzednio sprawdzajac jego istnienie

#define _POSIX_C_SOURCE 200112L
#define _XOPEN_SOURCE 500
#define _GNU_SOURCE

int main(int argc, char *argv[])
{

    pid_t pid;
    int status;

    pid = fork();

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
        execlp("./a.x", "a.x", argv[1], argv[2], (char *)NULL);
        perror("execlp error");
        exit(EXIT_FAILURE);
    default:
        // proces macierzysty
        sleep(3);
        pid_t childPid = pid;             // it became a.x
        if (kill(childPid, SIGINT) == -1) // for example im sending SIGINT to a.x. You can change it to SIGKILL or SIGSTOP or any other signal
        {
            perror("kill error");
            exit(EXIT_FAILURE);
        }
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
        break;
    }

    return 0;
}
