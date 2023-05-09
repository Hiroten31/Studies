#include <stdio.h>

int main() {
    int x, y, z;
    printf("Podaj liczbe ktora mam podzielic.\n");
    scanf("%d", &x);
    printf("Podaj liczbe przez ktora mam dzielic.\n");
    scanf("%d", &y);
    while(x!=0) {
        z=x%y;
        x=y%z;
    }
    printf("NWD = %d", z);
    return 0;
}
