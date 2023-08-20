#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <stdbool.h>

// Autor: Mateusz Migdał
// Data: 2023-04-06
// Opis: Program sprawdzający opisy sygnałów

bool check(int i)
{
    char *signal_descitpion = strsignal(i);
    if (signal_descitpion != NULL || signal_descitpion != "unknown signal")
    {
        printf("Signal: %d, Description: %s\n", i, signal_descitpion);
        return true;
    }
    else
    {
        return false;
    }
}

int main(int argc, char *argv[])
{
    for (int i = 1; i < 65; i++)
    {

        if (check(i) == false)
        {
            break;
        }
    }
    return 0;
}
