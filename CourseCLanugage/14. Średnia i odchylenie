#include <stdio.h>
#include <math.h>



int main()
{
    int Nmax = 1000;
    double numbers[Nmax];
    int n = 0;

    while (scanf("%lf", &numbers[n]) == 1)
    {
        n++;
    }

    double sum = 0.0;
    for (int i = 0; i < n; i++)
    {
        sum += numbers[i];
    }

    double srednia = sum / n;
    double odchylenie = 0.0;
    for (int i = 0; i < n; i++)
    {
        odchylenie += (numbers[i] - srednia) * (numbers[i] - srednia);
    }

    odchylenie = sqrt(odchylenie / n);

    printf("Srednia arytmetyczna: %lf\n", srednia);
    printf("Odchylenie standardowe: %lf\n", odchylenie);

    return 0;
}
