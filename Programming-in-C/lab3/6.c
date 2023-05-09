#include <stdio.h>

int main() {
    int x, y, z;
    while(x!=0) {
        y=0;
        z=1;
        printf("Podaj liczbe do ktorej mam obliczyc ciag Fibonacciego.\n");
        scanf("%d", &x);
        for(int i = 0; i < x-1; i++){
            z+=y;
            y=z-y;
        }
        printf("Podana liczba ciagu Fibonacciego to %d\n", z); 
    }
    return 0;
}
