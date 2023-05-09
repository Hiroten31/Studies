#include <stdio.h>
int main(){
	printf("Podaj dwie liczby\n");
	int i;
	int j;
	scanf("%d",&i);
	scanf("%d",&j);
	printf("Suma: %d\n", i+j);
	printf("Roznica: %d\nLub: %d\n", i-j, j-i);
	printf("Iloczyn: %d\n", i*j);
	printf("Modulo: %d\nLub: %d\n", i%j, j%i);
} 
