#include <stdio.h>
#define MAX 150

int main()
{
    char wyrazy[MAX];
    char pomocnicza;
    int miejscespacji = -1;
    printf("Podaj wyrazy.\n");
    fgets(wyrazy, sizeof(wyrazy), stdin);
    for(int i = 0; wyrazy[i+1] != '\0'; i++){
        if(wyrazy[i+1] == ' ' || wyrazy[i+2] == '\0'){
            for(int j = 0; j<(i-miejscespacji-((i-miejscespacji)%2))/2; j++){
                pomocnicza=wyrazy[miejscespacji+1+j];
                wyrazy[miejscespacji+1+j]=wyrazy[i-j];
                wyrazy[i-j]=pomocnicza;
            }
            miejscespacji=i+1;
        }
    }
    printf("\nPo:\n");
    for(int i = 0; wyrazy[i] != '\0'; i++){
        printf("%c", wyrazy[i]);
    }
    return 0;
}
