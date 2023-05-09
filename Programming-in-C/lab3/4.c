#include <stdio.h>

int main()
{
    printf("Podaj liczbe, ktora mam sprawdzic, czy jest pierwsza: \n");
    int x;
    scanf("%d", &x);
    for(int i = 2; i < x; i++){
        if(x%i==0){
            printf("Liczba nie jest pierwsza");
            return 0;
        }
    }
    printf("Liczba jest pierwsza");
    return 0;
}
