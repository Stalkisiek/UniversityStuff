#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

// print the process ids
void print_ids()
{
    printf("UID = %d, GID = %d, PID = %d, PPID = %d, PGID = %d\n", getuid(), getgid(), getpid(), getppid(), getpgrp());
    return;
}

int main()
{
    print_ids(); // wypisanie informacji o aktualnym procesie
    return 0;
}