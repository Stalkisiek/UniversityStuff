#include <stdio.h>
#include <string.h>

// Alredy did all of this in C. So just copied my backuped code

char *arabicToRoman(int n)
{
    static char *romanDigits[] = {
        "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    static int arabicDigits[] = {
        1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

    static char result[16];
    result[0] = '\0';

    for (int i = 0; n > 0; i++)
    {
        while (n >= arabicDigits[i])
        {
            strcat(result, romanDigits[i]);
            n -= arabicDigits[i];
        }
    }

    return result;
}

int romanToArabic(char *roman)
{
    static char *romanDigits[] = {
        "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    static int arabicDigits[] = {
        1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    // CMCDCCLV
    int result = 0;
    int length = strlen(roman);

    /*
     *  Najpierw pobrać jeden znak (a może 2?)
     *  o wiem
     *  porównać znaki z digits
     *
     */
    int j = 0;
    for (int i = 0; i < length; i++)
    {

        for (int j = 0; j < 13; j++)
        {
            if (strncmp(&roman[i], romanDigits[j], strlen(romanDigits[j])) == 0) // nie wiem do końca w sumie jak działa ta funkcja. Ale dokumentacja +/- na coś takiego mi wskazywała no i jakby działa xD
            {
                result += arabicDigits[j];
                i += strlen(romanDigits[j]) - 1;
                break;
            }
        }
    }

    return result;
}

int main()
{
    while (true)
    {
        printf("Wpisz liczbe arabska: ");
        int x = 0;
        scanf("%d", &x);
        printf("%d na liczby rzymskie to: %s\n", x, arabicToRoman(x));
        printf("%s na liczby arabskie to %d\n", arabicToRoman(x), romanToArabic(arabicToRoman(x)));
    }
}