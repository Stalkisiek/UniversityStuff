#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N_MAX 100 // teoretycznie można rozdzielic na max długość wersów i ilość  

//Nie działało mi w Clion na macu, ani windowsie. Ale z jakiegoś powodu xcode w linux mi wszedł. Chodziło o różnicę w odbiorze EOF

/*
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
*/

//Błąd jest prawie napewno tutaj.
int compare(const void *a, const void *b) {
    char *ia = *(char **)a;
    char *ib = *(char **)b;
    return strcmp(ia, ib);
}

int main() {
    char *Tekst[N_MAX];
    int i = 0;

    char wiersz[N_MAX];

    while (fgets(wiersz, N_MAX, stdin) != NULL&&i < N_MAX) {

        if (wiersz[0] == '\n')
            continue;

        Tekst[i] = malloc(strlen(wiersz) + 1);
        strcpy(Tekst[i], wiersz);

        i++;
    }

// sortowanie tablicy wierszy
    int j, k;
    for (j = 0; j < i - 1; j++) {
        for (k = 0; k < i - j - 1; k++) {
            if (strcmp(Tekst[k], Tekst[k + 1]) > 0) {
                char *temp = Tekst[k];
                Tekst[k] = Tekst[k + 1];
                Tekst[k + 1] = temp;
            }
        }
    }

    for (int j = 0; j < i; j++)
        printf("%s", Tekst[j]);

    for (int j = 0; j < i; j++)
        free(Tekst[j]);

}
