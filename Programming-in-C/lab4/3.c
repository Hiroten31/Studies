#include <stdio.h>
#include <math.h>

int main()
{
    long long int liczba = pow(9, 9);
    int dlugosc = log10(liczba) + 1;
    int tab[dlugosc];
    printf("W liczbie %lld powtarzaja sie: ", liczba);
    for(int i = 0; i<dlugosc; i++){
        tab[i]=liczba%10;
        liczba=(liczba-tab[i])/10;
    }
    for(int i = 0; i<dlugosc; i++){
        for(int j = i+1; j<dlugosc; j++){
            if(tab[i]==tab[j]){
                printf("%d, ", tab[i]);
            }
        }
    }
    return 0;
}
