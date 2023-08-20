#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

// Autor: Mateusz Migdał
// Data: 2023-04-06
// Opis: Program wielokrotnie wywoluje funkcje fork(tyle ile podane w argumentach), gdzie na kazdym dziecku zostaje poswationy program a.x z argumentami podanymi w argumentach

void handler(int sig)
{
    // printf("\n123\n");
}

int main(int argc, char *argv[])
{
    // arg[1] = ilosc powtorzen; arg[2] = co zrobic z sygnalem; arg[3] = sygnal
    if (argc != 4)
    {
        printf("Brak argumentow");
    }
    // main process will ignore signal. For work reasons i will set him as SIGINT but it can be anything
    if (signal(SIGINT, handler) == SIG_ERR)
    {
        perror("signal error");
        exit(EXIT_FAILURE);
    }

    int howMany = atoi(argv[1]);
    pid_t wpid;
    int status;
    .

        setpgid(0, 0);
    // 321 -> 132; 132 -> 213
    for (int i = 0; i < howMany; i++)
    {
        pid_t pid = fork();
        switch (pid)
        {
        case -1:
            perror("fork error");
            exit(EXIT_FAILURE);
        case 0:
            // proces potomny
            if (signal(SIGINT, SIG_DFL) == SIG_ERR)
            {
                perror("signal error");
                exit(EXIT_FAILURE);
            }

            execlp("./a.x", "a.x", argv[2], argv[3], (char *)NULL);
            perror("execlp error");
            exit(EXIT_FAILURE);
        default:
            // sleep(1);
            //  przywrocenie dzialania sygnalu
            if (signal(SIGINT, handler) == SIG_ERR)

            {
                perror("signal error");
                exit(EXIT_FAILURE);
            }

            break;
        }
    }

    while ((wpid = wait(&status)) != -1)
    {

        if (WIFEXITED(status))
        {
            printf("Proces %d zakończył się poprawnie. Kod powrotu: %d\n", wpid, WEXITSTATUS(status));
            exit(EXIT_SUCCESS);
        }
        else if (WIFSIGNALED(status))
        {
            printf("Proces %d zakończył się sygnałem %d\n", wpid, WTERMSIG(status));
            exit(EXIT_SUCCESS);
        }
    }

    if (wpid == -1 && errno != ECHILD)
    {
        // printf("%d\n", wpid = wait(&status));
        perror("waitpid error");
        exit(EXIT_FAILURE);
    }

    return 0;
}
