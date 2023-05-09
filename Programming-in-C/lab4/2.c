#include <stdio.h>

int main()
{
    int tab[10];
    for(int i = 0; i<10; i++){
        printf("Podaj %d. element tablicy: ", i);
        scanf("%d", &tab[i]);
    }
    for(int i = 0; i<10; i++){
        for(int j = i+1; j<10; j++){
            if(tab[i]==tab[j]){
                printf("%d element tablicy powtorzyl sie w %d miejscu. Jest to liczba %d.\n", i, j, tab[i]);
            }
        }
    }
    return 0; 
}
