#include <stdio.h>

int main()
{
    int tab1[] = {72, 31, 13, 27, 4, 2, 5, 48, 20, 50};
    int tab2[10];
    printf("Pierwsza tablica:\n");
    for(int i = 0; i<10; i++){
        printf("%d. Tab1: %d\n", i, tab1[i]);
        tab2[i]=tab1[i];
    }
    printf("\nDruga tablica:\n");
    for(int i = 0; i<10; i++){
        printf("%d. Tab2: %d\n", i, tab1[i]);
    }
    return 0;
}
