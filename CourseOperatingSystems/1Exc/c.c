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
    printf("\n\n"); // for better readability
    print_ids();    // print the main process ids
    for (int i = 0; i < 3; i++)
    {
        switch (fork())
        {
        case -1:
            perror("Fork_Error");
            exit(1); // 1 = unsuccessfull exit
        case 0:
            sleep(1); // <- child gest init as a parent cuse it lives longer and program doesnt want it to become a "zombie"
            print_ids();
            break;
        default:
            // sleep(10); // <- if sleep was there parent would wait for child to finish and then child wouldn't become a "zombie"
            break;
        }
    }

    return 0;
}
