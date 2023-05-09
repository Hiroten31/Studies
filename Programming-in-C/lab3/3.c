#include <stdio.h>

int main()
{
    printf("Podaj liczbe calkowita, ktorej dzielniki mam wypisac: \n");
    int x;
    scanf("%d", &x);
    for(int i = 1; i <= x/2; i++){
        if(x%i==0)
            printf("\n%d", i);
    }
    printf("\n%d", x);
    return 0;
}
