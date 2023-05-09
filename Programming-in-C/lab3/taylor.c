#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define li 100

double szereg(double x) {
    double gora = 1.0;
    double dol = 1.0;
    double znak, px;
    double wynik = 1.0;
    for(int i = 1; i<=li; i++) {
        gora=gora*(1+(3*(i-1)));
        dol=dol*(3*i);
        px=pow(x, i);
        znak=pow((-1), i);
        wynik=wynik+(znak*(gora/dol)*px);
    }
    return wynik;
}

int main() {
    double a, b, krok, x;
    int lp;
    printf("Podaj konce przedzialow z zakresu i liczbe podprzedzialow.\nZakres -1 < x < 1\n");
    printf("Poczatek przedzialu: ");
    scanf("%lf", &a);
    printf("Koniec przedzialu: ");
    scanf("%lf", &b);
    printf("Liczba podprzedzialow: ");
    scanf("%d", &lp);
    krok=(b-a)/lp;
    printf("Jeden krok wynosi: %lf\n", krok);
    printf("\n=================================");
    printf("\nx     szereg(x)     funckja(x)");
    printf("\n=================================");
    for(x=a; x<=b; x+=krok)
        printf("\n%.2lf %7.4lf %7.4lf", x, szereg((-1)*x), 1/(pow((1-x), (1/3.0))));
    printf("\n=================================");
    return 0;
}