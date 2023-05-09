#include <stdio.h>

int main() {
    int x, z;
    double sr = 1;
    char y;
    printf("Podaj z ilu liczb mam obliczyc srednia: ");
    scanf("%d", &x);
    printf("Wybierz czy srednia ma byc: \nA - arytmetyczna\nG - geometryczna\n");
    scanf(" %c", &y);
    for(int i = 0; i < x; i++) {
        if(y == 'A' || y == 'a'){
            printf("Podaj %d. liczbe: ", i+1);
            scanf("%d", &z);
            sr+=z;
        }
        if(y == 'G' || y == 'g'){
            printf("Podaj %d. liczbe: ", i+1);
            scanf("%d", &z);
            sr=sr*z;
        }
    }
    printf("Srednia wynosi = %.2f", sr/x);
    return 0;
}
