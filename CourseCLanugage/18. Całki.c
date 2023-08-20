#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define MAX_LEN 100

double stack[MAX_LEN] = {0};
int count = 0;

double pop();
void push(double a);

double calka(char text[], double x1, double x2, double dx) {
    double x, y, score, solution;
    char c;
    //printf("%lf\n",x1);
    for (double k = x1;k <= x2;k+=dx)
    {
        //printf("%lf\n",k);
        for (int i = 0; i < strlen(text); i++) {
            c = text[i];
            if (c == 'x') {
                push(k);
            }
            if (isdigit(c)) {
                char temp[MAX_LEN];
                int j = 0;
                while (isdigit(c)) {
                    temp[j]=c;
                    j++;
                    i++;
                    c = text[i];
                }
                score = (double)(strtol(temp, NULL , 10));
                push(score);
            }
            else {
                if (c == '+') {
                    x = pop();
                    y = pop();
                    push(x + y);
                }
                if (c == '-') {
                    y = pop();
                    x = pop();
                    push(x - y);
                }
                if (c == '*') {
                    x = pop();
                    y = pop();
                    push(x * y);
                }
                if (c == '/') {
                    y = pop();
                    x = pop();
                    push(x/y);
                }
                if (c == '^') {
                    y = pop();
                    x = pop();
                    push(pow(x,y));
                }
            }
        }
        //printf("%lf  %lf \n",k,stack[0]);
        solution += stack[0];
        count = 0;
    }
    return solution * dx;
}

double pop(){
    double a;
    a = stack[count-1];
    stack[count-1] = 0; // no null here
    count--;
    return a;
}

void push(double a) {
    stack[count] = a;
    count++;
}

int main()
{
    char text[MAX_LEN];
    double x1, x2, dx, result;

    printf("Mozliwe operacje to + - / * ^, kazda musi byc oddzielona spacja np. 2 3 4 + -\n");
    while(scanf("%[^\n]%*c", text)) {
        printf("Zasieg. Napisz x1 (mniejsza): ");
        scanf("%lf", &x1);
        printf("Napisz x2 (wieksza): ");
        scanf("%lf", &x2);
        printf("Napisz szczegolowosc < 1 && > 0(im mniejsza tym dokladniejsza np. 0.0001): ");
        scanf("%lf", &dx);

        //printf("%lf",x1);
        result = calka(text, x1, x2, dx);
        printf("%0.1lf", result);
    }

    return 0;
}
