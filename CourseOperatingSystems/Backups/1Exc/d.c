#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

// print the process ids
void print_ids(int generation)
{
    printf("Generation %d, UID = %d, GID = %d, PID = %d, PPID = %d, PGID = %d\n",
           generation, getuid(), getgid(), getpid(), getppid(), getpgrp());
}

int main()
{
    printf("\n\n");
    print_ids(0);       // main process
    int generation = 1; // we start with one, beacuse we already have one process that is main
    for (int i = 0; i < 3; i++)
    {
        switch (fork())
        {
        case -1:
            perror("Fork_Error");
            exit(1);
        case 0:
            print_ids(generation);
            sleep(generation++); // increase delay for each child process; Using ++ statement here is important but its not really a good idea to use it inside of an argument (cuse if I can easliy forget about it). But hey, it works!
            break;
        default:
            break;
        }
    }
    /*
    while (1)
    {
        sleep(1);
    } // <- debugging and copping pstree results
    */
    sleep(4);
    return 0;
}
