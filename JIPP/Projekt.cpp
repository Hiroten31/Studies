#include <iostream>
#include <fstream>

#include "JippVector.h"
#include "Game.h"

using namespace std;

int main() {
    /* Zbuduj aplikacjê do zarz¹dzania danymi (przyk³adowo pracownicy), która bêdzie wykorzystywaæ wczeœniej stworzony kontener. Musi ona posiadaæ nastêpuj¹ce funkcjonalnoœci:

    Na ocenê 3.0:
    klasa do przechowywania danych musi siê sk³adaæ z co najmniej 4 elementów - zrobione (title, releaseYear, rate, price)
    obs³ugê z poziomu konsoli (jakieœ menu) - zrobione
    mo¿liwoœæ dodawania elementów do kontenera - zrobione (1.)
    mo¿liwoœæ usuwania elementów z kontenera - zrobione (2.)
    mo¿liwoœæ edycji elementów z kontenera - zrobione (3.)
    mo¿liwoœæ wyœwietlania liczby elementów w kontenerze - zrobione (4.)
    mo¿liwoœæ wyœwietlania wszystkich elementów z kontenera - zrobione (5.)
    dzia³aj¹cy poprawnie zapis i wczytanie z pliku (6.)

    Na ocenê 4.0:
    poprawny zapis i odczyt z pliku binarnego - zrobione
    wyœwietlanie elementów z zakresu (podawane bêdzie od indeksu do indeksu) - zrobione (7.)
    wstawianie elementu pod podanym indeksem - zrobione (8.)

    Na ocenê 5.0:
    funkcje na kontenerze, przyk³adowo zliczanie pensji dla pracowników z przedzia³u indeksów, albo, których nazwisko zaczyna siê na jakiœ ci¹g znaków
    wyszukiwanie informacji w kontenerze (mo¿e byæ jedna metoda do jednego pola i nie musi byæ dla wszystkich pól) */

    JippVector<Game> vector;
        
    ifstream file("games.bin", ios::binary);
    if (!file) {
        cout << "\nOtwarcie pliku do odczytu nie powiodlo sie lub plik nie istnieje!";
    } else {
        cout << "Dane z pliku zostaly pomyslnie odczytane";
    }
    while (file) {
        size_t titleLength;
        int releaseYear;
        float rate, price;

        if (!file.read(reinterpret_cast<char*>(&titleLength), sizeof(titleLength))) {
            break;
        }

        string name(titleLength, '\0');
        if (!file.read(&name[0], titleLength)) {
            break;
        }
        if (!file.read(reinterpret_cast<char*>(&releaseYear), sizeof(releaseYear))) {
            break;
        }
        if (!file.read(reinterpret_cast<char*>(&rate), sizeof(rate))) {
            break;
        }
        if (!file.read(reinterpret_cast<char*>(&price), sizeof(price))) {
            break;
        }
        vector.pushBack(Game(name, releaseYear, rate, price));
    }
    file.close();

    bool wyjdz = true;
    char wybor;
    while (wyjdz) {
        cout << "\n\n\n----- MENU -----\n";
        cout << "1. Dodaj element do kontenera\n";
        cout << "2. Usun element z kontenera\n";
        cout << "3. Edytuj element w kontenerze\n";
        cout << "4. Ilosc elementow w kontenerze\n";
        cout << "5. Wyswietl elementy kontenera\n";
        cout << "6. Zapisz i wyjdz\n";
        cout << "7. Wyswietl elementy z zakresu\n";
        cout << "8. Wstaw element pod podany index\n";
        cout << "Wybierz opcje: \n";
        cin >> wybor;
        cin.get();
        switch (wybor) {
        case '1': {
            try {
                string title;
                int releaseYear;
                float rate, price;
                cout << "> Dodawanie elementu do kontenera <";
                cout << "\nPodaj tytul: ";
                getline(cin, title);
                cout << "Podaj rok wydania: ";
                cin >> releaseYear;
                cout << "Podaj ocene: ";
                cin >> rate;
                cout << "Podaj cene: ";
                cin >> price;
                vector.pushBack(Game(title, releaseYear, rate, price));
                cout << "Gra zostala dodana do kontenera";
            } catch (const exception& e) {
                cout << "\nBlad: " << e.what();
            }
            break;
        }
        case '2': {
            try {
                int index;
                cout << "> Usuwanie elementu z kontenera <";
                cout << "\nPodaj index elementu, ktory mam usunac: ";
                cin >> index;
                if (index < 0 || index > vector.size()) {
                    throw out_of_range("Zostal podany index spoza zakresu! < XXX\n");
                }
                cout << "Usuwasz element o wartosciach: ";
                vector[index].displayGame();
                vector.erase(index);
                cout << "Element zostal poprawnie usuniety!\n";
                break;
            } catch (const exception& e) {
                cout << "\nBlad: " << e.what();
            }
            break;
        }
        case '3': {
            try {
                int index;
                cout << "> Edytowanie elementu z kontenera <";
                cout << "\nPodaj index elementu, ktory chcesz edytowac: ";
                cin >> index;
                if (index < 0 || index >= vector.size()) {
                    throw out_of_range("Zostal podany index spoza zakresu! < XXX\n");
                }
                bool wyjdzZmiany = true;
                char wyborZmiany;
                while (wyjdzZmiany) {
                    cout << "\n------- Edycja elementu -------\n";
                    vector[index].displayGame();
                    cout << "1. Tytul\n";
                    cout << "2. Rok wydania\n";
                    cout << "3. Ocene\n";
                    cout << "4. Cene\n";
                    cout << "5. Wyjdz\n";
                    cout << "Wybierz opcje: \n";
                    cin >> wyborZmiany;
                    cin.get();
                    switch (wyborZmiany) {
                    case '1': {
                        string title;
                        cout << "\nNowy tytul: ";
                        cin >> title;
                        int releaseYear = vector[index].getReleaseYear();
                        float rate = vector[index].getRate();
                        float price = vector[index].getPrice();
                        vector.erase(index);
                        vector.insert(index, Game(title, releaseYear, rate, price));
                        break;
                    }
                    case '2': {
                        int releaseYear;
                        cout << "\nNowy rok wydania: ";
                        cin >> releaseYear;
                        string title = vector[index].getTitle();
                        float rate = vector[index].getRate();
                        float price = vector[index].getPrice();
                        vector.erase(index);
                        vector.insert(index, Game(title, releaseYear, rate, price));
                        break;
                    }
                    case '3': {
                        float rate;
                        cout << "\nNowa ocena: ";
                        cin >> rate;
                        string title = vector[index].getTitle();
                        int releaseYear = vector[index].getReleaseYear();
                        float price = vector[index].getPrice();
                        vector.erase(index);
                        vector.insert(index, Game(title, releaseYear, rate, price));
                        break;
                    }
                    case '4': {
                        float price;
                        cout << "Nowa cena: ";
                        cin >> price;
                        string title = vector[index].getTitle();
                        int releaseYear = vector[index].getReleaseYear();
                        float rate = vector[index].getRate();
                        vector.erase(index);
                        vector.insert(index, Game(title, releaseYear, rate, price));
                        break;
                    }
                    case '5': {
                        cout << "Wychodze z edycji elementu!\n";
                        wyjdzZmiany = false;
                        break;
                    }
                    default: {
                        cout << "Podales wartosc spoza zakresu!\n";
                        break;
                    }
                    }
                }
            } catch (const exception& e) {
                cout << "\nBlad: " << e.what();
            }
            break;
        }
        case '4': {
            try {
                cout << "> Ilosc elementow w kontenerze <\n";
                cout << "Ilosc: " << vector.size() << "\n";
                cout << "Capacity: " << vector.capacity() << "\n";
            } catch (const exception& e) {
                cout << "\nBlad: " << e.what();
            }
            break;
        }
        case '5': {
            try {
                cout << "> Wyswietlanie elementow kontenera <";
                for (int i = 0; i < vector.size(); i++) {
                    vector[i].displayGame();
                }
            } catch (const exception& e) {
                cout << "\nBlad: " << e.what();
            }
            break;
        }
        case '6': {
            try {
                ofstream file("games.bin", ios::binary);
                if (!file) {
                    cout << "\nOtwarcie pliku do zapisu nie powiodlo sie.";
                    return 0;
                }
                for (int i = 0; i < vector.size(); ++i) {
                    size_t titleLength = vector[i].getTitle().length();
                    file.write(reinterpret_cast<const char*>(&titleLength), sizeof(titleLength));
                    file.write(vector[i].getTitle().c_str(), titleLength);
                    int releaseYear = vector[i].getReleaseYear();
                    float rate = vector[i].getRate();
                    float price = vector[i].getPrice();
                    file.write(reinterpret_cast<const char*>(&releaseYear), sizeof(releaseYear));
                    file.write(reinterpret_cast<const char*>(&rate), sizeof(rate));
                    file.write(reinterpret_cast<const char*>(&price), sizeof(price));
                }
                file.close();
                cout << "\nPoprawnie zapisalem dane!";
            } catch (const exception& e) {
                cout << "\nBlad: " << e.what();
            }
            cout << "\nWychodze z programu!";
            wyjdz = false;
            break;
        }
        case '7': {
            try {
                int indexStart, indexEnd;
                cout << "> Wyswietlanie elementow kontenera z zakresu <";
                cout << "\nPodaj index elementu od ktorego mam zaczac wyswietlanie: ";
                cin >> indexStart;
                if (indexStart < 0 || indexStart >= vector.size()) {
                    throw out_of_range("Zostal podany index spoza zakresu! < XXX\n");
                }
                cout << "Podaj index elementu do ktorego mam wyswietlac: ";
                cin >> indexEnd;
                if (indexEnd < 0 || indexEnd >= vector.capacity() || indexStart > indexEnd) {
                    throw out_of_range("Zostal podany index spoza zakresu! < XXX\n");
                }
                for (int i = indexStart; i <= indexEnd; i++) {
                    vector[i].displayGame();
                }
            } catch (const exception& e) {
                cout << "\nBlad: " << e.what();
            }
            break;
        }
        case '8': {
            try {
                int index;
                cout << "> Wstawianie elementu pod podany index <";
                cout << "\nPodaj index pod jakim chcesz wstawic element: ";
                cin >> index;
                if (index < 0 || index >= vector.size()) {
                    throw out_of_range("Zostal podany index spoza zakresu! < XXX\n");
                }
                cin.get();
                string title;
                int releaseYear;
                float rate, price;
                cout << "> Dodawanie elementu do kontenera pod podany index <";
                cout << "\nPodaj tytul: ";
                getline(cin, title);
                cout << "Podaj rok wydania: ";
                cin >> releaseYear;
                cout << "Podaj ocene: ";
                cin >> rate;
                cout << "Podaj cene: ";
                cin >> price;
                if (index == vector.size()) {
                    vector.pushBack(Game(title, releaseYear, rate, price));
                    cout << "Gra zostala dodana na koniec kontenera";
                } else if (index == 0) {
                    vector.pushFront(Game(title, releaseYear, rate, price));
                    cout << "Gra zostala dodana na poczatek kontenera";
                } else {
                    vector.insert(index, Game(title, releaseYear, rate, price));
                    cout << "Gra zostala dodana do kontenera pod index: " << index;
                }
            } catch (const exception& e) {
                cout << "\nBlad: " << e.what();
            }
            break;
        }
        default: {
            cout << "Podaj liczbe z zakresu od 1 do 8!\n";
            break;
        }
        }
    }
    return 0;
}