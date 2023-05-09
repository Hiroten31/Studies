#include <stdio.h>
#include <math.h>

int main() {
    int liczba;
    printf("Podaj do ktorej liczby mam szukac liczb pierwszych: ");
    scanf("%d", &liczba);
    int tab[liczba];
    for(int i=0; i<liczba-1; i++){
        tab[i]=i+2;
    }
    for(int i=0; i<sqrt(liczba); i++){
        if(tab[i]!=0){
            for(int j=i+1; j<liczba-1; j++){
                if(tab[j]%tab[i]==0)
                    tab[j]=0;
            }
        }
    }
    printf("Liczby pierwsze w przedziale od 0 do %d: ", liczba);
    for(int i=0; i<liczba-1; i++){
        if(tab[i]!=0){
            printf("%d, ", tab[i]);
        }
    }
    return 0;
}