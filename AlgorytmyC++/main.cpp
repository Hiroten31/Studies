#define _CRT_SECURE_NO_DEPRECATE
#include <cstdlib>
#include <iostream>
#include "algorytmy.hpp"

using namespace std;

int main() {
    //Inicjacja pliku z danymi
    FILE* plik;
    if (plik = fopen("dane.txt", "r")) {
        cout << "Plik istnieje!" << endl;
        //Prawda jesli plik istnieje, czyli nie nadpisuj -> nic nie rob
    } else {
        cout << "Plik nie istnieje! Tworze nowy..." << endl;
        plik = fopen("dane.txt", "w");
        //Nadpisanie ziarna losowych liczb, aby powstawaly inne za kazdym razem
        srand(time(0));
        //Stworzenie pliku posiadajacego 500 tysiecy liczb od -100 do 100
        for (int i = 0; i < 500000; i++) {
            fprintf(plik, "%d\n", rand() % 201 - 100);
        }
        fclose(plik);
    }

    plik = fopen("dane.txt", "r");

    //Zapytanie o wielkosc tablicy do 300 000, u mnie liczy ok. 15 minut.
    int n = 300001;
    while (n > 300000) {
        cout << "\nPodaj wartosc n mniejsza od 300 000: ";
        cin >> n;
    }

    //Zapisanie n-liczb z pliku dane.txt do tablicy o wielkosci n
    int* tab = new int[n];
    for (int i = 0; i <= n; i++) {
        fscanf(plik, "%d", &tab[i]);
    }

    /*cout << "Przed sortowaniem" << endl;
    for (int i = 0; i < n; i++)
        cout << i << ". " << tab[i] << "\n";*/
    cout << "\nTEST 1:\n";
    //TEST 1 - tablica z liczbami wybranymi losowo
    wstawianie(tab, n);
    selekcja(tab, n);
    babel(tab, n);
    quicksort(tab, n, 0, n - 1);
    shellsort(tab, n);
    heapsort(tab, n);
    
    //Wywolanie quicksortu, aby posortowac oryginalna tablice
    quicksorting(tab, n, 0, n - 1);

    /*cout << endl << "Po sortowaniu" << endl;
    for (int i = 0; i < n; i++)
        cout << i << ". " << tab[i] << "\n";*/

    
    //Petla do odwrocenia kolejnosci tablicy, tak, aby byla kolejnosc malejaca do drugiego testu
    for (int i = 0; i < n-i-1; i++) {
        swap(tab[i], tab[n - i-1]);
        /*cout << "Zmieniam: " << i << ". " << tab[i] << " z: " << n-i-1 << ". " << tab[n - i - 1] << endl;*/
    }

    /*cout << endl << "Po odwroceniu" << endl;
    for (int i = 0; i < n; i++)
        cout << i << ". " << tab[i] << "\n";*/

    cout << "\nTEST 2:\n";
    //TEST 2 - tablica z liczbami wybranymi od końca
    wstawianie(tab, n);
    selekcja(tab, n);
    babel(tab, n);
    quicksort(tab, n, 0, n - 1);
    shellsort(tab, n);
    heapsort(tab, n);
    //Wywolanie quicksortu, aby posortowac oryginalna tablice
    quicksorting(tab, n, 0, n - 1);

    cout << "\nTEST 3:\n";
    //TEST 3 - tablica z liczbami wybranymi od początku
    wstawianie(tab, n);
    selekcja(tab, n);
    babel(tab, n);
    quicksort(tab, n, 0, n - 1);
    shellsort(tab, n);
    heapsort(tab, n);
    
    //Zamknięcie pliku
    fclose(plik);
    
}
