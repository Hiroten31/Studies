#include <stdio.h>
#include <math.h>

int main() {
    int liczba;
    double ilosc = 0;
    int wynik = 1;
    double srednia;
    printf("Podaj liczbe z zakresu od 10 do 999:  ");
    scanf("%d", &liczba);
    while(liczba > 9 && liczba < 1000) {
        wynik*=liczba;
        ilosc++;
        printf("Podaj nastepna liczbe: ");
        scanf("%d", &liczba);
    }
    if(ilosc == 0){
        printf("Podales liczbe spoza zakresu = koniec.\nSrednia geometryczna wynosi: 0");
        return 0;
    }
    srednia = pow(wynik, (1/ilosc));
    printf("Podales liczbe spoza zakresu = koniec.\nSrednia geometryczna wynosi: %lf", srednia);
}