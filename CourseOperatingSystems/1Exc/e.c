#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

// print the process ids
void print_ids()
{
    printf("UID = %d, GID = %d, PID = %d, PPID = %d, PGID = %d\n", getuid(), getgid(), getpid(), getppid(), getpgrp());
    return;
}

int main()
{
    printf("\n\n");        // for better readability
    switch (setpgid(0, 0)) // sets the process group id to the process id
    {
    case -1: // if -1 than no good
        perror("Error_Setting_Pgid");
        exit(1); // exit the program if its unsuccessful

    default:
        break; // if its successful than continue
    }

    print_ids(); // print the main process ids

    for (int i = 0; i < 3; i++)
    {
        // printf("%i iteration:\n", i + 1); <- debugging
        switch (fork())
        {
        case -1:
            perror("Fork_Error");
            exit(1);
        case 0:
            switch (setpgid(0, 0)) // sets the process group id to the process id
            {
            case -1: // if -1 than no good
                perror("Error_Setting_Pgid");
                exit(2); // exit the program if its unsuccessful
            default:
                break; // if its successful than continue
            }
            print_ids();
            break;
        default:
            if (wait(NULL) == -1)
            {
                perror("Wait_Error");
                exit(3);
            } // wait for the child process to finish
        }
    }
    return 0;
}