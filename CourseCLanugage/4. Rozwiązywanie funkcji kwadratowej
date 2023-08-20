//
//  main.c
//  Rozwiązywanie funkcji kwadratowej
//
//  Created by Mateusz Migdał on 25/10/2022.
//

#include <stdio.h>
#include <math.h>

float delta(int a, int b, int c){
    float d;
    d = pow(b,2) - 4*a*c;
    return d;
    
}

void rozwiazanie(int a, int b, float delta){
    float x1 = (-b + sqrt(delta))/2*a;
    float x2 = (-b - sqrt(delta))/2*a;
    printf("x1: %.3f",x1);
    printf(" x2: %.3f",x2);
    printf("\n");
    
}

int main(int argc, const char * argv[]) {
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    rozwiazanie(a, b, delta(a, b, c));
    return 0;
}
