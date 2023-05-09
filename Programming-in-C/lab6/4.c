#include <stdio.h>

int main()
{
    char tekst[1000];
    int n = -1;
    FILE *plik;
    if((plik = fopen("tekst.txt", "r")) == NULL){
        printf("Blad, plik nie istnieje!");
        return 0;
    }
    fscanf(plik, "%[^\n]", tekst);
    fseek(plik, n, 0);
    ftell(plik);
    printf("%ld", ftell(plik));
    fclose(plik);
    return 0;
}

