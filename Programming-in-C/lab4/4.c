#include <stdio.h>
#include <math.h>

int main()
{
    int liczba;
    printf("Podaj liczbe, ktora mam sprawdzic czy jest palindromem: ");
    scanf("%d", &liczba);
    int dlugosc = log10(liczba)+1;
    int tab[dlugosc-1];
    for(int i = 0; i<dlugosc; i++){
        tab[i]=liczba%10;
        liczba=(liczba-tab[i])/10;
    }
    for(int i = 0; i<dlugosc; i++){
        if(tab[i]==tab[dlugosc-1-i]){
            if(i==dlugosc-i-(dlugosc%2)){
                printf("Liczba jest palindromem!");
                return 0;
            }
        } else {
            printf("Liczba nie jest palindromem!");
            return 0;
        }
    }
    return 0;
}
