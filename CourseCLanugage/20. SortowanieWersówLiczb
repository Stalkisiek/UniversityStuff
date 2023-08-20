#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N_MAX 100


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


//Błąd jest prawie napewno tutaj.
int compare(const void *a, const void *b) {
    char *ia = *(char **)a;
    char *ib = *(char **)b;
    return strcmp(ia, ib);
}

int main() {
    printf("Czy rosnaco? 1 -> tak / 0 -> nie\n");
    int tempxy;
    scanf("%i",&tempxy);
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
    for(int j = 0; j < i - 1;){
        double a = atoi(Tekst[j]);
        double b = atoi(Tekst[j+1]);
        if(tempxy == 1){
            if(a > b){
                char *temp = Tekst[j];
                Tekst[j] = Tekst[j + 1];
                Tekst[j + 1] = temp;
                j = 0;
                continue;
            }
            j++;
        }
        else if(tempxy == 0){
            if(a < b){
                char *temp = Tekst[j];
                Tekst[j] = Tekst[j + 1];
                Tekst[j + 1] = temp;
                j = 0;
                continue;
            }
            j++;
        }
        
    }

        for (int j = 0; j < i; j++)
            printf("%s", Tekst[j]);

        for (int j = 0; j < i; j++)
            free(Tekst[j]);

}

