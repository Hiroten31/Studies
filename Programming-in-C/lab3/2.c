#include <stdio.h>

int main()
{
    printf("Liczby calkowite podzielne przez 13 z przedzialu 1-200\n");
    for(int i = 0; i <= 200; i++){
        if(i%13==0)
            printf("%d\n", i);
    }
    return 0;
}
