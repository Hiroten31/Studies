#include <stdio.h>
#define MAX 150

int main()
{
    char wyrazy[MAX];
    int wybor;
    printf("Podaj wyraz do zaszyfrowania: ");
    fgets(wyrazy, sizeof(wyrazy), stdin);
    printf("Mam rozszyfrowac czy zaszyfrowac?\n1 - rozszyfrowac\n2 - zaszyfrowac\n");
    scanf("%d", &wybor);
    if(wybor==1){
        printf("\nZaszyfrowany: ");
        for(int i = 0; wyrazy[i+1] != '\0'; i++){
            if((wyrazy[i] >= 65 && wyrazy[i] <= 90) || (wyrazy[i] >= 97 && wyrazy[i] <= 122)){
                if(wyrazy[i] == 'Z' || wyrazy[i] == 'z' || wyrazy[i]+1 == 'Z' || wyrazy[i]+1 == 'z' || wyrazy[i]+2 == 'Z' || wyrazy[i]+2 == 'z'){
                    printf("%c", wyrazy[i]-23);
                } else {
                    printf("%c", wyrazy[i]+3);
                }
            } else {
                printf("%c", wyrazy[i]);
            }
        }
    } else if(wybor==2){
        printf("\nRozszyfrowany: ");
        for(int i = 0; wyrazy[i+1] != '\0'; i++){
            if((wyrazy[i] >= 65 && wyrazy[i] <= 90) || (wyrazy[i] >= 97 && wyrazy[i] <= 122)){
                if(wyrazy[i] == 'A' || wyrazy[i] == 'a' || wyrazy[i]-1 == 'A' || wyrazy[i]-1 == 'a' || wyrazy[i]-2 == 'A' || wyrazy[i]-2 == 'a'){
                    printf("%c", wyrazy[i]+23);
                } else {
                    printf("%c", wyrazy[i]-3);
                }
            } else {
                printf("%c", wyrazy[i]);
            }
        }
    } else {
        printf("Nie wybrales ani 1, ani 2.");
    }
    return 0;
}