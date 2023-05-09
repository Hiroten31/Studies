#include <stdio.h>

int main() {
    int x, y;
    while(x!=0) {
        y = 1;
        printf("Podaj liczbe ktorej silnie mam obliczyc.\n");
        scanf("%d", &x);
        if(x==0) return 0;
        for(int i = 1; i <= x; i++){
            y=y*i;
        }
        printf("Silnia tej liczby = %d\n", y); 
    }
    return 0;
}
