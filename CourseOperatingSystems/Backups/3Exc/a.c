#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

// Autor: Mateusz Migdał
// Data: 2023-04-06
// Opis: Program w zależności od argumentów wywołania wykonuje różne akcje na procesie w zależności od sygnału i opcji wywołaniaoper

#define _POSIX_C_SOURCE 200112L
#define _XOPEN_SOURCE 500
#define _GNU_SOURCE

// Obsluga sygnalu
void default_handler(int sig)
{
    printf("Odebrano sygnał: %d\n", sig);
}

void ignore_handler(int sig)
{
    printf("Sygnał %d zignorowany\n", sig);
}

void custom_handler(int sig)
{
    printf("Odebrano sygnał: %d - wlasne polecenie\n", sig);
    sleep(3);
}

int main(int argc, char *argv[])
{
    // Obsluga blednych argumentow
    if (argc < 2)
    {
        printf("Użycie: %s [1|2|3] [numer sygnału]\n", argv[0]);
        return 1;
    }

    // Konwersja argumentow na liczby
    int option = atoi(argv[1]);
    int signal_num = atoi(argv[2]);

    // Wyświetlenie PID procesu
    pid_t pid = getpid();
    printf("PID: %d\n", pid);

    // Obsluga sygnalu
    switch (option)
    {
    case 1:
        signal(signal_num, SIG_DFL);
        printf("Obsługa domyślna sygnału %d\n", signal_num);
        break;
    case 2:
        signal(signal_num, SIG_IGN);
        printf("Sygnał %d zignorowany\n", signal_num);
        break;
    case 3:
        signal(signal_num, custom_handler);
        printf("Obsługa własna sygnału %d\n", signal_num);
        break;
    default:
        printf("Nieprawidłowa opcja\n");
        return 1;
    }

    if (pause() == -1)
    {
        printf("Błąd funkcji pause()\n");
        perror("pause");
        exit(EXIT_FAILURE);
    }

    return 0;
}
