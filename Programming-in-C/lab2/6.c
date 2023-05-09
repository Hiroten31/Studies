#include <stdio.h>
int main(){
	printf("Podaj liczbe, sprawdze czy jest parzysta albo nieparzysta\n");
	int x;
	scanf("%d", &x);
	if(x%2==1)
		printf("Liczba jest nieparzysta\n");
	else
		printf("Liczba jest parzysta\n");
}
