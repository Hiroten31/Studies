#include <stdio.h>
int main(){
	printf("Podaj 3 dlugosci dla prostopadloscianu:\n");
	int i,j,k;
	scanf("%d", &i);
	scanf("%d", &j);
	scanf("%d", &k);
	printf("Objetosc jest rowna: %d\n", i*j*k);
	printf("Pole calkowite jest rowne: %d\n", 2*(i*j+j*k+i*k));
}
