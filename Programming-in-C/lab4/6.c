#include <stdio.h>

int main()
{
    int tab[] = {13, 4, 37, 1, 59, 80, 70, 21, 98, 68};
    printf("Przed sortowaniem.\n");
    for(int i = 0; i<10; i++){
        printf("%d. element: %d\n", i, tab[i]);
    }
    int pomocnicza;
    for(int i = 0; i<10; i++){
        pomocnicza=tab[i];
        for(int j = 1; j<=i; j++){
            if(tab[i+1-j]<tab[i-j]){
                tab[i+1-j]=tab[i-j];
                tab[i-j]=pomocnicza;
            }
            /*printf("\nPo %d.%d podmianie.\n", i, j);
            for(int k = 0; k<10; k++){
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
