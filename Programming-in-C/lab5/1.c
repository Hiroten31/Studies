#include <stdio.h>

int main()
{
    float tab[3][3] = {{1, 2, 3},
                  {3, 1, 2},
                  {2, 3, 1}};
    
    float wyznacznik = (tab[0][0]*tab[1][1]*tab[2][2])+(tab[0][1]*tab[1][2]*tab[2][0])+(tab[0][2]*tab[1][0]*tab[2][1]);
    wyznacznik = wyznacznik - (tab[2][0]*tab[1][1]*tab[0][2])-(tab[2][1]*tab[1][2]*tab[0][0])-(tab[2][2]*tab[1][0]*tab[0][1]);
    if(wyznacznik==0){
        printf("Nie mozna odwrocic macierzy, poniewaz wyznacznik jest rowny 0!");
        return 0;
    }
    float tabodw[3][3];
    tabodw[0][0] = ((tab[1][1]*tab[2][2]) - (tab[2][1]*tab[1][2])) / wyznacznik;
    tabodw[0][1] = ((-1)*((tab[1][0]*tab[2][2]) - (tab[2][0]*tab[1][2]))) / wyznacznik;
    tabodw[0][2] = ((tab[1][0]*tab[2][1]) - (tab[2][0]*tab[1][1])) / wyznacznik;
    tabodw[1][0] = ((-1)*((tab[0][1]*tab[2][2]) - (tab[2][1]*tab[0][2]))) / wyznacznik;
    tabodw[1][1] = ((tab[0][0]*tab[2][2]) - (tab[2][0]*tab[0][2])) / wyznacznik;
    tabodw[1][2] = ((-1)*((tab[0][0]*tab[2][1]) - (tab[2][0]*tab[0][1]))) / wyznacznik;
    tabodw[2][0] = ((tab[0][1]*tab[1][2]) - (tab[1][1]*tab[0][2])) / wyznacznik;
    tabodw[2][1] = ((-1)*((tab[0][0]*tab[1][2]) - (tab[1][0]*tab[0][2]))) / wyznacznik;
    tabodw[2][2] = ((tab[0][0]*tab[1][1]) - (tab[1][0]*tab[0][1])) / wyznacznik;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf("%f ", tabodw[j][i]);
        }
        printf("\n");
    }
    printf("\n%f", wyznacznik);

    return 0;
}
