# JiPP - project :book:
A simple project to pass the JiPP class done correctly with given instructions:

## Zbuduj własny vector :construction:
Zbuduj własną klasę realizującą podobne funkcjonalności, co kontener vector w bibliotece standardowej.
Klasa będzie się nazywać JippVector. Będzie musiała posiadać następujące właściwości:
- możliwość przechowywania wartości dowolnego typu
- nie będzie używać w sobie żadnych kontenerów, tylko sama dynamicznie alokować pamięć
- możliwość kopiowania
- obsługę wyjątków

## Klasa będzie posiadać następujące metody :white_check_mark:	
- konstruktor bezparametryczny (tworzy kontener o wielkości 0)
- konstruktor parametryczny (przyjmuje int) - rezerwuje pamięć dla podanej liczby elementów
- reserve(int) - rezerwuje pamięć dla podanej liczby elementów, jeżeli kontener jest już większy, to nic nie robi
- fill(type) - wypełnia cały kontener podaną wartością
- fill(int start, int len, type) - wypełnia wektor od elementu pod indeksem start (wraz z nim) oraz len kolejnych elementów, przekazaną wartością
- operator[int] = pobieranie wartości pod wskazanym indeksem oraz ustawianie wartości pod nim
- pushBack(type) - wstawianie elementu na koniec kontenera
- pushFront(type) - wstawianie elementu na początek kontenera
- insert(int index, type) - wstawia przekazany element pod wskazany index (na ocenę 4.0, jeżeli na niższą, to implementacja powinna zostać pusta)
- erase(int) - usuwanie elementu pod wskazanym indeksem
- erase(int index, int len) - usuwanie len elementu od wskazanego indeksu (index, wraz z nim)
- size() - zwracanie wielkości kontenera (ile elementów jest w nim przechowywane)
- capacity() - zwraca liczbę elementów, dla których została zarezerwowana pamięć
- bool isEmpty() - zwracanie informacji, czy kontener jest pusty
- shrinkToFit() - dostosowywanie wielkości tablicy do liczby elementów w kontenerze
Wyjątki rzucane przez kontener muszą być możliwe do złapania przy pomocy std::exception.

## Aplikacja :hash:
Zbuduj aplikację do zarządzania danymi (przykładowo pracownicy), która będzie wykorzystywać wcześniej stworzony kontener. Musi ona posiadać następujące funkcjonalności:
- klasa do przechowywania danych musi się składać z co najmniej 4 elementów
- obsługę z poziomu konsoli (jakieś menu)
- możliwość dodawania elementów do kontenera
- możliwość usuwania elementów z kontenera
- możliwość edycji elementów z kontenera
- możliwość wyświetlania liczby elementów w kontenerze
- możliwość wyświetlania wszystkich elementów z kontenera
- działający poprawnie zapis i wczytanie z pliku
- poprawny zapis i odczyt z pliku binarnego
- wyświetlanie elementów z zakresu (podawane będzie od indeksu do indeksu)
- wstawianie elementu pod podanym indeksem

## Podsumowanie :pencil:
Kontener musi zostać zaimplementowany w plikach JippVector.h i JippVector.cpp, które zostaną wgrane w wyznaczone miejsce na delcie. 
Poprawność działania kontenera może zostać sprawdzona za pomocą testów jednostkowych. 
Jeżeli w kontenerze zostaną stwierdzone poważne błędy, będzie się to wiązało z koniecznością poprawy projektu.

Projekt będzie należało przyjść i obronić.
