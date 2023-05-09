#include <stdio.h>

int main()
{
    printf("Co zapisac w pliku?\n");
    char tekst[1000];
    FILE *plik = fopen("plik.txt", "w");
    scanf("%[^\n]", tekst);
    fprintf(plik, "%s", tekst);
    fclose(plik);
    return 0;
}

