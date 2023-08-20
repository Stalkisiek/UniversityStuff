#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Niepoprawna liczba argumentow. Uzycie: %s <plik>\n", argv[0]);
        return 1;
    }
    char haslo[100];
    printf("Podaj haslo: ");
    scanf("%s", haslo);
    int dlugosc_hasla = strlen(haslo);

    FILE *file1, *file2;
    if (NULL == (file1 = fopen(argv[1], "rb"))) {
        printf("Nie mozna otworzyc pliku %s", argv[1]);
        return 1;
    }

    char Tymczasowy[L_tmpnam];
    tmpnam(Tymczasowy);
    if (NULL == (file2 = fopen(Tymczasowy, "wb"))) {
        printf("Nie mozna otworzyc pliku tymczasowego");
        return 1;
    }

    int j = 0;
    char znak;
    while ((znak = getc(file1)) != EOF) {
        znak ^= haslo[j % dlugosc_hasla];
        putc(znak, file2);
        j++;
    }

    fclose(file1);
    fclose(file2);
    unlink(argv[1]);
    rename(Tymczasowy, argv[1]);

    return 0;
}
