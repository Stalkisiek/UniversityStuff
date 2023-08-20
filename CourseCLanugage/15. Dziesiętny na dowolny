#include <stdio.h>
#include <math.h>

void konw(int n,int s){ // n <- liczba, s <- system
    //ustalić max pot
    int max =0;

    for(int i = 0;;i++) {
        if(pow(s,i) > n){
            break;
        }
        max = i; //db
    }
    //printf("%lf",pow(s,max));
    int nT = n;
    while(nT>0){
        for(int i = s - 1; i >= 0;i--){
            if(pow(s,max) * i <= nT){
                printf("%d",i);
                nT -= pow(s,max) * i;
                //printf("\n%0.0lf\n",pow(s,max)) * i;
                break;
            }
        }
        max--;
    }

}

int main() {
    printf("Wypisz liczbe do skonwertowania: ");
    int n;
    scanf("%d",&n);
    printf("Wypisz do jakiego systemu: ");
    int sys;
    scanf("%d",&sys);
    konw(n,sys);
    return 0;
}
