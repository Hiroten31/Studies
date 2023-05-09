#include <stdio.h>
#include <math.h>

int main() {
    printf("Jakiej figury mam obliczyc pole?\nO - kola\nT - trojkata\nK - kwadratu\n");
    char w;
    scanf(" %c", &w);
    if(w=='O' || w=='o' || w=='0') {
        double r;
        printf("Podaj dlugosc promienia kola: ");
        scanf("%lf", &r);
        if(r > 0){
            printf("Pole kola wynosi: %.2f", (pow(r,2)*M_PI));
            return 0;
        }
        printf("Dlugosci nie moga byc mniejsze od 0!");
    } if(w=='T' || w=='t') {
        double a, h;
        printf("Podaj dlugosci podstawy i wysokosci trojkata.\na: ");
        scanf("%lf", &a);
        printf("h: ");
        scanf("%lf", &h);
        if(a > 0 && h > 0) {
            printf("Pole trojkata jest rowne: %.2f", ((a*h)/2));
            return 0;
        }
        printf("Dlugosci nie moga byc mniejsze od 0!");
    } if(w=='K' || w=='k') {
        double a, b;
        printf("Podaj dlugosci a i b.\na: ");
        scanf("%lf", &a);
        printf("b: ");
        scanf("%lf", &b);
        if(a > 0 && b > 0) {
            printf("Pole kwadratu jest rowne: %.2f", a*b);
            return 0;
        }
        printf("Dlugosci nie moga byc mniejsze od 0!");
    }
}
