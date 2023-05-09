#include <stdio.h>

int main()
{
    char tekst[1000];
    FILE *plik, *plik2;
    if((plik = fopen("tekst.txt", "r")) == NULL){
        printf("Blad, plik nie istnieje!");
        return 0;
    }
    fscanf(plik, "%[^\n]", tekst);
    plik2 = fopen("tekst2.txt", "w");
    for (int i = 0; tekst[i]!='\0'; i++)
        fputc(tekst[i], plik2);
    printf("%s", tekst);
    fclose(plik);
    fclose(plik2);
    return 0;
}
