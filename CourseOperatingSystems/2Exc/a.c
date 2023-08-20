#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

// Autor: Mateusz Migdał
// Data: 2023-03-29
// Opis: Program wykonuje 3 procesy potomne, które wykonują program podany jako pierwszy argument wywołania programu.
// Problematyka: Dla przykladowego 3 krotnego uruchomienia petli for() dostajemy tylko 3 wywolania b.x. Spowodowane jest to dzialaniem funkcji execl, ktora nadpisuje PID procesu potomnego i na jego miejsce tworzy b.x.
/*
Przykladowe drzewo procesow:
make(10698)───a.x(10699)─┬─b.x(10700)
                         ├─b.x(10701)
                         └─b.x(10702)
*/

int main(int argc, char *argv[])
{

    sleep(1);     // for better readability
    if (argc < 2) // if there is no argument
    {
        printf("No argument!\n");
        exit(1);
    }
    printf("\n\n"); // for better readability

    for (int i = 0; i < 3; i++)
    {
        // printf("%i iteration:\n", i + 1); <- debugging
        switch (fork())
        {
        case -1:
            perror("Fork_Error");
            exit(1);
        case 0:
            execl(argv[1], argv[1], (char *)NULL);
            // system("./b.x"); <- u can use this for not swapping PID
            perror("execl_Error");
            exit(2);
        default:
            break;
            // pid_t pid = getpid(); <- debugging
            // printf("PID: %d\n", pid); <- debugging
        }
    }
    /* debugging
    while (1)
    {
        sleep(1);
    }
    */
    sleep(2); // czeka na powloke
    return 0;
}