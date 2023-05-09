#include <stdio.h>

int main()
{
    int powtorka;
    char tekst[1000];
    FILE *plik;
    if((plik = fopen("tekst.txt", "r")) == NULL){
        printf("Blad, plik nie istnieje!");
        return 0;
    }
    fscanf(plik, "%[^\n]", tekst);
    char litery[sizeof(tekst)];
    for(int i = 0; tekst[i]!='\0'; i++){
        fseek(plik, i, 0);
        powtorka = 1;
        for(int j = i+1; tekst[j]!='\0'; j++){
            if(tekst[j]!=' ' && tekst[i]==tekst[j]){
                powtorka++;
                tekst[j]=' ';
            }
        }
        if(powtorka>1)
            printf("Litera %c powtarza sie: %d\n", fgetc(plik), powtorka);
    }
    fclose(plik);
    return 0;
}
