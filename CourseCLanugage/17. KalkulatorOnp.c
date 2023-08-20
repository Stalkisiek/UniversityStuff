#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define MAX 100

double stack[MAX] = {0};
int count = 0;

double pop();
void push(double a);

void onp(char text[]) {
    
    char c;
    char temp[MAX];
    double score, x, y;
    

    for (int i = 0; i < strlen(text); i++) {
        c = text[i];
        if (isdigit(c)) {
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
            if (c == '.') {
                printf("Wynik: %.1f\n", stack[0]);
                count = 0;
                break;
            }
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
            if (c == '/') {
                y = pop();
                x = pop();
                push(x / y);
            }
            if (c == '*') {
                x = pop();
                y = pop();
                push(x * y);
            }

        }
    }
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
    char text[MAX];
    printf("Poprawna formula zapisywania: {liczba} {liczba} {znak}{kropka}    np -> 4 7 +. Operacje to +,-,/,*\n");
    while(scanf("%s", text)){
        onp(text);
    }
    return 0;
}
