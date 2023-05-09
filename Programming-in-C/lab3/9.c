#include <stdio.h>

int main()
{
    int a, h;
    printf("Podaj dlugosci a i h prostokatu.\na = ");
    scanf("%d", &a);
    printf("b = ");
    scanf("%d", &h);
    if(a <= 1 || h <= 1){
        printf("Dlugosc nie moze byc mniejsza badz rowna od 1!");
        return 0;
    }
    for(int x = 0; x < a; x++){
        printf("*");
    }
    for(int i = 0; i < h-2; i++){
        printf("\n*");
        for(int j = 0; j < a-2; j++){
            printf(" ");
        }
        printf("*");
    }
    printf("\n");
    for(int x = 0; x < a; x++){
        printf("*");
    }
    return 0;
}
