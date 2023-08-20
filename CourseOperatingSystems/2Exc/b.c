#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// Autor: Mateusz Migdał
// Data: 2023-03-29
// Opis: Program wypisuje identyfikatory procesu, grupy procesu, użytkownika i grupy użytkownika. Jest on programem pomocniczym dla programu a.c

// print the process ids
void print_ids()
{
    printf("UID = %d, GID = %d, PID = %d, PPID = %d, PGID = %d\n", getuid(), getgid(), getpid(), getppid(), getpgrp());
    return;
}

int main()
{
    print_ids();
    return 0;
}