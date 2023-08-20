#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/*
  Autor: Mateusz Migdal
  Data: 15-06-23

  Program demonstruje wzajemne wykluczanie przy użyciu muteksów. Każdy wątek wykonuje swoją prywatną sekcję, a następnie aktualizuje licznik globalny w sekcji krytycznej. Liczba sekcji prywatnych dla każdego wątku jest przekazywana jako argument wywołania programu.

  Działanie programu:
  - Każdy wątek wykonuje swoją sekcję prywatną, zwiększając swoje prywatne liczniki.
  - Następnie, w sekcji krytycznej, wątek blokuje dostęp do licznika globalnego za pomocą muteksu, zwiększa jego wartość o wartość prywatnego licznika, a następnie odblokowuje muteks.
  - Każdy wątek może powtarzać ten cykl wielokrotnie.
  - Po zakończeniu działania wszystkich wątków, program wypisuje ostateczną wartość licznika globalnego.

  Uwagi:
  - Liczbę wątków oraz liczbę sekcji krytycznych/prywatnych wątku przekazywać przez argumenty wywołania programu.
  - Wątek główny tworzy muteks i go inicjalizuje, uruchamia wątki realizujące wzajemne wykluczanie, a następnie czeka na ich zakończenie.
  - Na początku program wypisuje adres utworzonego muteksu oraz numery i identyfikatory wątków.
  - W trakcie działania wątków program wypisuje numer wątku i numer kolejny jego sekcji prywatnej (po lewej stronie ekranu) oraz jego sekcji krytycznej (po prawej stronie ekranu); można też wypisywać aktualną wartość licznika globalnego.
  - Po prawej stronie ekranu powinien być widoczny tylko jeden wątek w swojej sekcji krytycznej, a po lewej stronie pozostałe wątki w swoich sekcjach prywatnych.
  - Wstawiono funkcję sleep() z losowym czasem uśpienia między pobraniem wartości licznika globalnego a jego uaktualnieniem.
  - Losowe uśpienie wątku wstawiono również w sekcji prywatnej.
  - Po zakończeniu działania wątków usuwany jest muteks, a program wypisuje wartość licznika globalnego oraz jego wartość oczekiwaną dla poprawnej synchronizacji.
*/

pthread_mutex_t mutex;
int counter = 0;

void *threadFunction(void *arg)
{
    int privateCounter = 0;
    int numSections = *((int *)arg);

    for (int i = 0; i < numSections; i++)
    {
        // Sekcja prywatna
        privateCounter++;
        printf("Thread %ld private section: Counter = %d\n", pthread_self(), privateCounter);

        // Sekcja krytyczna
        pthread_mutex_lock(&mutex);
        counter++;
        printf("\t\tThread %ld critical section: Counter = %d\n", pthread_self(), counter);
        pthread_mutex_unlock(&mutex);

        // Losowe uśpienie wątku w sekcji prywatnej
        unsigned int sleepTime = rand() % 2;
        sleep(sleepTime);
    }

    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s <numSections>\n", argv[0]);
        return 1;
    }

    int numThreads = argc - 1;
    int *numSections = malloc(numThreads * sizeof(int));

    for (int i = 0; i < numThreads; i++)
    {
        numSections[i] = atoi(argv[i + 1]);
    }

    pthread_t *threads = malloc(numThreads * sizeof(pthread_t));

    pthread_mutex_init(&mutex, NULL);

    printf("Mutex address: %p\n", &mutex);
    printf("Threads:\n");

    for (int i = 0; i < numThreads; i++)
    {
        pthread_create(&threads[i], NULL, threadFunction, &numSections[i]);
        printf("Thread %ld created\n", threads[i]);
    }

    for (int i = 0; i < numThreads; i++)
    {
        pthread_join(threads[i], NULL);
        printf("Thread %ld finished\n", threads[i]);
    }

    pthread_mutex_destroy(&mutex);

    printf("Final counter value: Counter = %d\n", counter);
    printf("Expected counter value: Counter = %d\n", numThreads * numSections[0]);

    free(numSections);
    free(threads);

    return 0;
}
