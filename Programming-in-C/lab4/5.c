#include <stdio.h>

int main()
{
    int tab[] = {13, 4, 37, 1, 59, 80, 70, 21, 98, 68};
    printf("Przed sortowaniem.\n");
    for(int i = 0; i<10; i++){
        printf("%d. element: %d\n", i, tab[i]);
    }
    int pomocnicza;
    for(int i = 10; i>0; i--){
        for(int j = 0; j<i-1; j++){
            if(tab[j]>tab[j+1]){
                pomocnicza=tab[j];
                tab[j]=tab[j+1];
                tab[j+1]=pomocnicza;
            }
            //Sprawdzenie (zrobilem je z przykladowymi liczbami z wikipedii)
            /*printf("\nPo %d.%d podmianie.\n", i-1, j+1);
            for(int k = 0; k<5; k++){
                printf("%d. element: %d\n", k, tab[k]);
            }*/
        }
    }
    printf("\nPo sortowaniu.\n");
    for(int i = 0; i<10; i++){
        printf("%d. element: %d\n", i, tab[i]);
    }
    return 0;
}

