//
//  main.c
//  Fib
//
//  Created by Mateusz Migdał on 07/11/2022.
//

#include <stdio.h>

long long int Fibonacci(int n){
    int a1 = 0;
    int a2 = 1;
    int temp1;
    if(n == 0){
        return a1;
    }
    else if(n == 1){
        return a2;
    }
    for(int i = 1; i < n;i++){
        temp1 = a2 + a1;
        a1 = a2;
        a2 = temp1;
    }
    return a2;
}
int main(int argc, const char * argv[]) {
    int a;
    scanf("%d",&a);
    printf("%lld\n",Fibonacci(a));
}
