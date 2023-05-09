#include <stdio.h>
int main(){
	printf("Podaj dwie liczby rzeczywiste:\n");
	float i;
	float j;
	scanf("%f", &i);
	scanf("%f", &j);
	printf("Iloczyn tych liczb to: %f\n", i*j);
	printf("Iloraz pierwszej przez druga to: %f\n", i/j);
	printf("Iloraz drugiej przez pierwsza to: %f\n", j/i);
}


