package org.example;

public class MainBinarny {

    static int search(int[] numbers, int indexStart, int target, int indexEnd) {
        int middle;

        //Sprawdzenie czy liczba nie jest mniejsza od najmniejszej, albo większa od największej. Czyli czy znajduję się w tablicy.
        if(target < numbers[indexStart] || target > numbers[indexEnd]){
            return -1;
        }

        //Określenie środkowego indeksu.
        middle = (indexStart + indexEnd)/2;

        //Jeśli długość tablicy jest parzysta, nie ma elementu środkowego, są 'dwa'.
        if(middle%2 == 0) {

            //Sprawdzenie 'mniejszego' środka, ponieważ typ [int] ucina liczby po przecinku, np. 23/2 = 11.5, więc sprawdzamy indeks 11.
            if(numbers[middle] == target) {
                return middle;
            }
            //Sprawdzenie 'wiekszego' środka, ponieważ typ [int] ucina liczby po przecinku, np. 23/2 = 11.5, więc sprawdzamy indeks 12 (11+1).
            else if (numbers[middle+1] == target) {
                return middle+1;
            }

        }
        //Jeśli długość tablicy jest nieparzysta, jest jeden element środkowy.
        else {
            //Sprawdzenie czy środkowy element jest szukanym.
            if(numbers[middle] == target)
                return middle;
        }

        //Teraz sprawdzamy w której połówce znajduje się nasza szukana liczba.
        if(target > numbers[middle]) {
            //Jeśli większa od środkowej liczby, to szukamy od środkowa do końca.
            return search(numbers, middle+1, target, indexEnd);
        } else {
            //Jeśli mniejsza od środkowej liczby, to szukamy od początku do środka.
            return search(numbers, indexStart, target, middle-1);
        }
    }
    public static void main(String[] args) {
        int[] liczbyPierwsze = {2, 3, 5, 7, 11, 13, 17, 19, 23, 27, 29, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
        int liczbaSzukana = 23;
        int index = search(liczbyPierwsze, 0, liczbaSzukana, liczbyPierwsze.length - 1);

        System.out.println("Szukam liczby: " + liczbaSzukana);
        if(index == -1){
            System.out.println("Tablica nie zawiera podanej liczby!");
        } else {
            System.out.println("Liczba ma indeks: " + index);
        }
    }
}
