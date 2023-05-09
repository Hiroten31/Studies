#include <stdio.h>

int main()
{
    int tab[] = {13, 4, 37, 1, 59, 80, 70, 21, 98, 68};
    printf("Przed sortowaniem.\n");
    for(int i = 0; i<10; i++){
        printf("%d. element: %d\n", i, tab[i]);
    }
    int pomocnicza, minimalna, miejsce;
    for(int i = 0; i<10; i++){
        minimalna = tab[9];
        for(int j = 9; j>=i; j--){
            if(minimalna>=tab[j]){
                minimalna=tab[j];
                miejsce=j;
            }
        }
        pomocnicza=tab[i];
        tab[i]=minimalna;
        tab[miejsce]=pomocnicza;
        /*printf("\nPo %d podmianie.\n", i);
        for(int k = 0; k<10; k++){
            printf("%d. element: %d\n", k, tab[k]);
        }*/
    }
    printf("\nPo sortowaniu.\n");
    for(int i = 0; i<10; i++){
        printf("%d. element: %d\n", i, tab[i]);
    }
    return 0;
}
