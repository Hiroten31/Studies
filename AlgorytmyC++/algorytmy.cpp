#include "algorytmy.hpp"
#include <cstdlib>
#include <iostream>
#include <chrono>

void wstawianie(int tab[], int n) {
	//Stworzenie tablicy na ktorej zostanie wykonane sortowanie by wyznaczyc czas
	int* tabzapasowa = new int[n];
	for (int i = 0; i < n; i++) {
		tabzapasowa[i] = tab[i];
	}

	clock_t begin = clock();
	int pomocnicza, j;
	for (int i = 1; i < n; i++) {
		pomocnicza = tabzapasowa[i];
		j = i - 1;
		while (j >= 0 && tabzapasowa[j] > pomocnicza) {
			tabzapasowa[j + 1] = tabzapasowa[j];
			--j;
		}
		tabzapasowa[j + 1] = pomocnicza;
	}
	clock_t end = clock();

	double time = double(end - begin) / (double)CLOCKS_PER_SEC;
	std::cout << "Sortowanie przez wstawianie zajelo: " << time << " sekund.\n";

	/*std::cout << "\nPo sortowaniu przez wstawianie:\n";
	for (int i = 0; i < n; i++)
		std::cout << i << ". " << tabzapasowa[i] << "\n";*/

	delete[] tabzapasowa;
}

void selekcja(int tab[], int n) {
	//Stworzenie tablicy na ktorej zostanie wykonane sortowanie by wyznaczyc czas
	int* tabzapasowa = new int[n];
	for (int i = 0; i < n; i++) {
		tabzapasowa[i] = tab[i];
	}

	clock_t begin = clock();
	for (int i = 0; i < n - 1; i++) {
		int pomocnicza = i;
		for (int j = i + 1; j < n; j++) {
			if (tabzapasowa[j] < tabzapasowa[pomocnicza]) {
				pomocnicza = j;
			}
		}
		std::swap(tabzapasowa[i], tabzapasowa[pomocnicza]);
	}
	clock_t end = clock();

	double time = double(end - begin) / (double)CLOCKS_PER_SEC;
	std::cout << "Sortowanie przez selekcje zajelo: " << time << " sekund.\n";

	/*std::cout << "\nPo sortowaniu przez selekcje:\n";
	for (int i = 0; i < n; i++)
		std::cout << i << ". " << tabzapasowa[i] << "\n";*/

	delete[] tabzapasowa;
}

void babel(int tab[], int n) {
	//Stworzenie tablicy na ktorej zostanie wykonane sortowanie by wyznaczyc czas
	int* tabzapasowa = new int[n];
	for (int i = 0; i < n; i++) {
		tabzapasowa[i] = tab[i];
	}

	clock_t begin = clock();
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (tabzapasowa[j] > tabzapasowa[j + 1]) {
				std::swap(tabzapasowa[j], tabzapasowa[j + 1]);
			}
		}
	}
	clock_t end = clock();

	double time = double(end - begin) / (double)CLOCKS_PER_SEC;
	std::cout << "Sortowanie babelkowe zajelo: " << time << " sekund.\n";

	/*std::cout << "\nPo sortowaniu babelkowym:\n";
	for (int i = 0; i < n; i++)
		std::cout << i << ". " << tabzapasowa[i] << "\n";*/

	delete[] tabzapasowa;
}

void quicksort(int* tab, int n, int lewo, int prawo) {
	//Stworzenie tablicy na ktorej zostanie wykonane sortowanie by wyznaczyc czas
	int* tabzapasowa = new int[n];
	for (int i = 0; i < n; i++) {
		tabzapasowa[i] = tab[i];
	}

	clock_t begin = clock();
	//Wywolanie funkcji, ktora posortuje funkcje zapasowa, nie oryginalna
	quicksorting(tabzapasowa, n, lewo, prawo);
	clock_t end = clock();

	double time = double(end - begin) / (double)CLOCKS_PER_SEC;
	std::cout << "Sortowanie przez quicksort zajelo: " << time << " sekund.\n";

	/*std::cout << "\nPo sortowaniu przez quicksort:\n";
	for (int i = 0; i < n; i++)
		std::cout << i << ". " << tabzapasowa[i] << "\n";*/

	delete[] tabzapasowa;
}

void quicksorting(int* tab, int n, int lewo, int prawo) {
	if (prawo <= lewo) {
		return;
	}

	int i = lewo - 1;
	int j = prawo + 1;
	int srodek = tab[(lewo + prawo) / 2];
	while (1) {
		while (srodek > tab[++i]);
		while (srodek < tab[--j]);
		if (i <= j) {
			std::swap(tab[i], tab[j]);
		} else {
			break;
		}
	}

	if (j > lewo) {
		quicksorting(tab, n, lewo, j);
	}

	if (i < prawo) {
		quicksorting(tab, n, i, prawo);
	}
	
}

void shellsort(int* tab, int n) {
	//Stworzenie tablicy na ktorej zostanie wykonane sortowanie by wyznaczyc czas
	int* tabzapasowa = new int[n];
	for (int i = 0; i < n; i++) {
		tabzapasowa[i] = tab[i];
	}
	
	clock_t begin = clock();
	for (int i = n / 2; i > 0; i /= 2) {
		for (int j = i; j < n; j++) {
			int pomocnicza = tabzapasowa[j];
			int k;
			for (k = j; k >= i && tabzapasowa[k - i] > pomocnicza; k -= i) {
				tabzapasowa[k] = tabzapasowa[k - i];
			}
			tabzapasowa[k] = pomocnicza;
		}
	}
	clock_t end = clock();

	double time = double(end - begin) / (double)CLOCKS_PER_SEC;
	std::cout << "Sortowanie przez shellsort zajelo: " << time << " sekund.\n";
	
	/*std::cout << "\nPo sortowaniu przez shellsort:\n";
	for (int i = 0; i < n; i++)
		std::cout << i << ". " << tabzapasowa[i] << "\n";*/

	delete[] tabzapasowa;
}

void heapsort(int* tab, int n) {
	//Stworzenie tablicy na ktorej zostanie wykonane sortowanie by wyznaczyc czas
	int* tabzapasowa = new int[n];
	for (int i = 0; i < n; i++) {
		tabzapasowa[i] = tab[i];
	}

	clock_t begin = clock();
	for (int i = n / 2 - 1; i >= 0; i--) {
		heapify(tabzapasowa, n, i);
	}
		
	for (int i = n - 1; i > 0; i--) {
		std::swap(tabzapasowa[0], tabzapasowa[i]);
		heapify(tabzapasowa, i, 0);
	}
	clock_t end = clock();

	double time = double(end - begin) / (double)CLOCKS_PER_SEC;
	std::cout << "Sortowanie przez heapsort zajelo: " << time << " sekund.\n";

	/*std::cout << "\nPo sortowaniu przez heapsort:\n";
	for (int i = 0; i < n; i++)
		std::cout << i << ". " << tabzapasowa[i] << "\n";*/

	delete[] tabzapasowa;
}

void heapify(int* tab, int n, int i) {
	int pomocnicza = i;
	int lewo = 2 * i + 1;
	int prawo = 2 * i + 2;

	if (lewo < n && tab[lewo] > tab[pomocnicza]) {
		pomocnicza = lewo;
	}

	if (prawo < n && tab[prawo] > tab[pomocnicza]) {
		pomocnicza = prawo;
	}

	if (pomocnicza != i) {
		std::swap(tab[i], tab[pomocnicza]);
		heapify(tab, n, pomocnicza);
	}

}

