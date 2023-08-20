#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char text[100];
    printf("Wpisz slowo: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0'; //nie lubiem, że to trzeba robić <- nieintuicyjne

    int length = strlen(text);
    for (int i = 0, j = length - 1; i < j; i++, j--) //AAA MOŻNA ZAPISYWAĆ PO DWIE RZECZY W ARGUMENTACH FOR'A
    {
        while (!isalpha(text[i]) && i < j) {
            i++;
        }
        while (!isalpha(text[j]) && i < j) {
            j--;
        }

        if (text[i] != text[j]) //można użyć tolower
        {
            printf("Slowo nie jest palindromem\n");
            return 0;
        }
    }

    printf("Slowo jest palindromem\n");
    return 0;
}
