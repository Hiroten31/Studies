#include <stdio.h>
#include <math.h>
int main(){
	printf("Podaj wartosc x, mi i sigma parametrow:\n");
	int x, m, s;
	scanf("%d", &x);
	scanf("%d", &m);
	scanf("%d", &s);
	printf("Wartosc gestosci rozkladu normalnego to: %f\n", (1./(s*sqrt(2*M_PI)))*exp((-1.)*pow(x-m,2)/(2*pow(s,2))));
}
