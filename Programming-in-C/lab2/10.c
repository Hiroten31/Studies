#include <stdio.h>
#include <math.h>

int main() {
    double x, y;
    printf("Podaj wspolrzedne x i y.\nx: ");
    scanf("%lf", &x);
    printf("y: ");
    scanf("%lf", &y);
    double funkcja1, funkcja2, funkcja3;
    funkcja1 = log10(x) + 10;
    funkcja2 = pow(1.5, x);
    funkcja3 = exp(x);
    if((funkcja1 > y || x < 0) && funkcja2 < y && funkcja3 > y) {
        printf("Wspolrzedne x = %.2lf i y = %.2lf znajduja sie miedzy funkcjami.", x, y);
    } else {
        printf("Wspolrzedne x = %.2lf i y = %.2lf nie znajduja sie miedzy funkcjami.", x, y);
    }
}
