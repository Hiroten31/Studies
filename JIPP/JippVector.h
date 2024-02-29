#pragma once

#include <algorithm>
#include <stdexcept>

using namespace std;

// Obs�uga wyj�tk�w
class VectorException : public exception {
public:
	const char* what() const noexcept override {
		return " Blad alokacji wektora! < XXX\n";
	}
};

class OutOfRangeException : public VectorException {
public:
	const char* what() const noexcept override {
		return " Zostal podany index spoza zakresu! < XXX\n";
	}
};

// Mo�liwo�� przechowywania warto�ci dowolnego typu
template <typename T> class JippVector {
private:
	T* array;
	int arraySize;
	int arrayCapacity;
public:
	// Konstruktor bezparametryczny (tworzy kontener o wielko�ci 0)
	JippVector() {
		try {
			array = new T[0];
			arraySize = 0;
			arrayCapacity = 0;
		} catch (const exception &e){
			throw VectorException();
		}
	};

	// Konstruktor parametryczny (przyjmuje int) - rezerwuje pami�� dla podanej liczby element�w
	JippVector(const int memory) {
		try {
			array = new T[memory];
			arraySize = 0;
			arrayCapacity = memory;
		} catch (const exception& e) {
			throw VectorException();
		}
	};

	// Mo�liwo�� kopiowania
	JippVector(const JippVector &vector) {
		try {
			arraySize = vector.arraySize();
			arrayCapacity = vector.arrayCapacity();
			array = new T[arrayCapacity];
			for (int i = 0; i < arraySize; i++) {
				array = vector.array[i];
			}
		} catch (const bad_alloc& e) {
			throw VectorException();
		}
	}

	// Usuwanie operatora przypisania
	JippVector &operator=(const JippVector &rhs) = delete;

	// Rezerwuje pami�� dla podanej liczby element�w, je�eli kontener jest ju� wi�kszy, to nic nie robi
	void reserve(const int newCapacity) {
		try {
			if (arrayCapacity == 0) {
				array = new T[1];
				arrayCapacity = 1;
			} else if (arrayCapacity < newCapacity) {
				// Tworz� now� tablic� do przechowania warto�ci.
				T* tempArray = new T[arraySize];
				// Przepisuj� j� do tablicy tymczasowej
				for (int i = 0; i < arraySize; i++) {
					tempArray[i] = array[i];
				}
				delete[] array;
				array = new T[newCapacity];
				for (int i = 0; i < arraySize; i++) {
					array[i] = tempArray[i];
				}
				// Zwolnienie pami�ci tablicy tymczasowej
				delete[] tempArray;
				// Zmieniam capacity kontenera
				arrayCapacity = newCapacity;
			} else {
				// Kontener jest juz wiekszy albo taki sam, nie robie nic.
			}
		} catch (const bad_alloc&) {
			throw VectorException();
		}
	};

	// Wype�nia ca�y kontener podan� warto�ci�
	void fill(const T value) {
		try {
			for (int i = 0; i < arrayCapacity; i++) {
				array[i] = value;
			}
			arraySize = arrayCapacity;
		} catch (const bad_alloc& e) {
			throw VectorException();
		}
	};

	// Wype�nia wektor od elementu pod indeksem (wraz z nim) oraz len kolejnych element�w, przekazan� warto�ci�
	void fill(const int start, const int len, const T value) {
		// Fill u�yty pomi�dzy dwoma istniej�cymi ju� warto�ciami
		if (start >=0 && start < arraySize) {
			T* tempArray = new T[arrayCapacity];
			for (int i = 0; i < arraySize; i++) {
				tempArray[i] = array[i];
			}
			// Przesuwam wartosci do start o len dbajac o arrayCapacity
			for (int i = start; i < arraySize; i++) {
				if ((i + len) >= arrayCapacity) {
					reserve(2 * arrayCapacity);
				}
				array[i + len] = tempArray[i];
			}
			// Zwolnienie pamieci tablicy tymczasowej
			delete[] tempArray;
			// Nadpisuje wartosci od start do start+len
			for (int i = start; i < start + len; i++) {
				array[i] = value;
				arraySize++;
			}
		} else if (start == arraySize || start == arraySize + 1) { 
			// Fill od ostatniego indexu, nadpisanie go
			// NIE WIEM CZY TAK POWINNO DZIALAC, WZORUJE SIE PRZYK�ADEM ZE STRONY: 
			// https://cplusplus.com/reference/algorithm/fill/

			// Nadpisuje wartosci od indexu i dbam o arrayCapacity
			for (int i = start; i < start + len; i++) {
				if (arraySize == arrayCapacity) {
					reserve(2 * arrayCapacity);
				}
				array[i] = value;
				arraySize++;
			}
		} else {
			throw OutOfRangeException();
		}
	};

	// Pobieranie warto�ci pod wskazanym indexem oraz ustawianie warto�ci pod nim
	T operator [] (const int index) {
		if (index >= 0 && index < arrayCapacity) {
			return array[index];
		} else {
			throw OutOfRangeException();
		}
	};

	// Wstawianie elementu na koniec kontenera
	void pushBack(const T& value) {
		try {
			if (arraySize == arrayCapacity) {
				reserve(2 * arrayCapacity);
			}
			array[arraySize] = value;
			arraySize++;
		} catch (const VectorException&) {
			throw;
		}
	};

	// Wstawianie elementu na pocz�tek kontenera
	void pushFront(const T& value) {
		try {
			if (arraySize == arrayCapacity) {
				reserve(2 * arrayCapacity);
			}
			// Tworzymy tymczasowa tablice pomocnicza
			T* tempArray = new T[arraySize];
			for (int i = 0; i < arraySize; i++) {
				tempArray[i] = array[i];
			}
			// Przesuwamy cala tablice o 1 od miejsca 0
			for (int i = 0; i < arraySize; i++) {
				array[i + 1] = tempArray[i];
			}
			// Zwolnienie pamieci tablicy tymczasowej
			delete[] tempArray;
			// Na poczatku dodajemy element
			array[0] = value;
			arraySize++;
		} catch (const VectorException&) {
			throw;
		}
	};

	// Wstawia przekazany element pod wskazany index
	void insert(const int index, const T& value) {
		if (index >= 0 && index < arrayCapacity) {
			if (arraySize == arrayCapacity) {
				reserve(2 * arrayCapacity);
			}
			T* tempArray = new T[arraySize];
			for (int i = 0; i < arraySize; i++) {
				tempArray[i] = array[i];
			}
			// Przesuwamy cala tablice o 1 od miejsca index
			for (int i = index; i < arraySize; i++) {
				array[i + 1] = tempArray[i];
			}
			// Zwolnienie pamieci tablicy tymczasowej
			delete[] tempArray;
			array[index] = value;
			arraySize++;
		} else {
			throw OutOfRangeException();
		}
	};

	// Usuwanie elementu pod wskazanym indeksem
	void erase(const int index) {
		if (index >= 0 && index < arraySize) {
			T* tempArray = new T[arrayCapacity];
			// Uzupelniamy tablice do indexu
			for (int i = 0; i < index; i++) {
				tempArray[i] = array[i];
			}
			// Uzupelniamy tablice od indexu, omijajac index
			for (int i = index + 1; i < arraySize; i++) {
				tempArray[i - 1] = array[i];
			}
			array = new T[arrayCapacity];
			for (int i = 0; i < arraySize; i++) {
				array[i] = tempArray[i];
			}
			// Zwolnienie pamieci tablicy tymczasowej
			delete[] tempArray;
			arraySize--;
			// shrinkToFit();
		} else {
			throw OutOfRangeException();
		}
	};

	// Usuwanie len elementu od wskazanego indeksu (index, wraz z nim)
	void erase(const int index, const int len) {
		if (index >= 0 && index < arraySize) {
			T* tempArray = new T[arrayCapacity];
			// Uzupelniamy tablice pomocnicza
			for (int i = 0; i < arraySize; i++) {
				tempArray[i] = array[i];
			}
			// Usuwamy stara tablice
			delete[] array;
			// I tworzymy nowa, poniewaz jesli arraySize == arrayCapacity, to wtedy 
			// ostatni element bedzie zduplikowany, zamiast pusty.
			array = new T[arrayCapacity];
			// Uzupelniamy tablice do indexu
			for (int i = 0; i < index; i++) {
				array[i] = tempArray[i];
			}
			// Uzupelniamy tablice od indexu, omijajac index
			for (int i = index + len; i < arraySize; i++) {
				array[i - len] = tempArray[i];
			}
			// Zwolnienie pamieci tablicy tymczasowej
			delete[] tempArray;
			arraySize = arraySize - len;
			// shrinkToFit();
		} else {
			throw OutOfRangeException;
		}
	};

	// Zwracanie wielko�ci kontenera (ile element�w jest w nim przechowywane)
	int size() {
		return arraySize;
	};

	// Zwraca liczb� element�w, dla kt�rych zosta�a zarezerwowana pami��
	int capacity() {
		return arrayCapacity;
	};

	// Zwracanie informacji, czy kontener jest pusty
	bool isEmpty() {
		return arraySize == 0;
	};

	// Dostosowywanie wielko�ci tablicy do liczby element�w w kontenerze
	void shrinkToFit() {
		try {
			T* tempArray = new T[arraySize];
			for (int i = 0; i < arraySize; i++) {
				tempArray[i] = array[i];
			}
			delete[] array;
			array = new T[arraySize];
			for (int i = 0; i < arraySize; i++) {
				array[i] = tempArray[i];
			}
			delete[] tempArray;
			arrayCapacity = arraySize;
		} catch (const bad_alloc&) {
			throw VectorException();
		}
	};
};