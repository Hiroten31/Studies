#include <stdio.h>

int main()
{
    printf("Ile liczb naturalnych mam zsumowac?\n");
    int x;
    int wynik = 0;
    scanf("%d", &x);
    for(int i = 0; i <= x; i++){
        wynik+=i;
    }
    printf("Wynik: %d", wynik);
    return 0;
}
