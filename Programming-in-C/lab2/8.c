#include <stdio.h>
#include <math.h>

int main() {
    printf("Podaj dwie liczby: \n");
    double a, b;
    printf("a: ");
    scanf("%lf", &a);
    printf("b: ");
    scanf("%lf", &b);
    if(fabs(a) > fabs(b) && a != 0) {
        printf("Liczba b stanowi %.2f%% liczby a.", (b/a)*100);
        return 0;
    } if(fabs(a) < fabs(b) && b !=0) {
        printf("Liczba a stanowi %.2f%% liczby b.", (a/b)*100);
        return 0;
    } else {
        printf("Nie mozna dzielic przez 0!");
        return 0;
    }
}
