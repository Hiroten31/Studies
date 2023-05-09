#include <stdio.h>

int main(){
        printf("Podaj mi dwie liczby:\n");
        int i, j;
        scanf("%d", &i);
        scanf("%d", &j);
        printf("Wpisz S jesli mam jest zsumowac albo R jest odjac.\n");
        char k;
        scanf(" %c", &k);
        if(k=='S' || k=='s')
            printf("Suma podanych liczb to: %d\n", i+j);
        else if(k=='R' || k=='r')
            printf("Roznica podanych liczb to: %d\n", i-j);
        else
            printf("Nie podales ani S, ani R.");
}
