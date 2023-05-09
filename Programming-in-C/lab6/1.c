#include <stdio.h>

int main()
{
    int liczba;
    char tekst[15];
    FILE *plik;
    plik = fopen("plik.txt", "w");
    for(int i = 0; i<5; i++){
        printf("Podaj liczbe: ");
        scanf("%d", &liczba);
        fprintf(plik, "%d, ", liczba);
    }
    fclose(plik);
    if((plik = fopen("plik.txt", "r")) == NULL){
        printf("Blad, plik nie istnieje!");
        return 0;
    }
    fscanf(plik, "%[^\n]", tekst);
    printf("%s", tekst);
    fclose(plik);
    return 0;
}
