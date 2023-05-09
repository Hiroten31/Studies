#include <stdio.h>

int main() {
    double a1, a2, c1, c2, b1, b2, x, y, w , wx, wy;
    printf("Podaj a1: ");
    scanf("%lf", &a1);
    printf("Podaj a2: ");
    scanf("%lf", &a2);
    printf("Podaj b1: ");
    scanf("%lf", &b1);
    printf("Podaj a2: ");
    scanf("%lf", &b2);
    printf("Podaj c1: ");
    scanf("%lf", &c1);
    printf("Podaj a2: ");
    scanf("%lf", &c2);
    w = a1*b2 - a2*b1;
    wx = c1*b2 - c2*b1;
    wy = a1*c2 - a2*c1;
    x = wx/w;
    y = wy/w;
    if(w != 0)
        printf("\nx: %.2f\ny: %.2f", x, y);
    if(w == 0 && wx == 0 && wy == 0)
        printf("\nUklad posiada nieskonczenie wiele rozwiazan!");
    if((w == 0 && wx != 0) || (w == 0 && wy != 0))
        printf("\nUklad nie posiada rozwiazan!");
    return 0;
}
