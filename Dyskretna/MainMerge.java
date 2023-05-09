package org.example;

public class MainMerge {

    static void sort(int[] numbers, int start, int end)  {
        //Jeśli start == koniec, znaczy to, że w tablicy został tylko jeden element i sortowanie się zatrzymuje.
        if(start < end) {
            //Określenie środka tablicy.
            int middle = (start + end)/2;
            //Sortowanie lewej połowy tablicy.
            sort(numbers, start, middle);
            //Sortowanie prawej połowy tablicy.
            sort(numbers, middle+1, end);
            //Wywołanie metody scalającej posortowane połówki.
            merge(numbers, start, middle, end);
        }
    }

    static void merge(int[] numbers, int start, int middle, int end) {
        //Utworzenie tymczasowej tablicy i skopiowanie do niej elementów głównej tablicy.
        int[] temp = new int[numbers.length];
        for(int i = start; i <= end; i++) {
            temp[i] = numbers[i];
        }

        //Zmienne wskazujące na pierwsze elementy scalonych połówek oraz na początek tablicy tymczasowej.
        int x = start, y = middle+1, z = start;

        //Porównywanie elementów obydwu połówek.
        //Mniejsze elementy są pokolei umieszczane w tablicy od lewej strony.
        while(x <= middle && y <= end) {
            //Porównywanie pokolei elementów połówek od lewej strony.
            if(temp[x] <= temp[y]) {
                numbers[z] = temp[x];
                //Element na miejscu zmiennej X był mniejszy, więc po podstawieniu go do orginalnej tablicy, jest brany kolejne element, większy od wstawionego.
                x++;
            } else {
                numbers[z] = temp[y];
                //Element na miejscu zmiennej Y był mniejszy, więc po podstawieniu go do orginalnej tablicy, jest brany kolejne element, większy od wstawionego.
                y++;
            }
            //Przesunięcie miejsca w które wstawiane są mniejsze elementy.
            z++;
        }

        //Wstawienie pozostałych elementów z lewej połowy do głownej tablicy, aż do napotkania połowy tablicy.
        while(x <= middle) {
            numbers[z] = temp[x];
            z++;
            x++;
        }

        //Wstawienie pozostałych elementów z prawej połowy do głownej tablicy, aż do napotkania końca tablicy.
        while(y <= end) {
            numbers[z] = temp[y];
            z++;
            y++;
        }
    }
    public static void main(String[] args) {
        int[] liczbyPierwsze = {13, 53, 27, 2, 67, 89, 17, 73, 97, 41, 29, 61, 7, 11, 47, 3, 59, 37, 43, 71, 19, 79, 5, 89};
        System.out.println("Przed sortowaniem:");
        for(int i : liczbyPierwsze){
            System.out.print(i + ", ");
        }
        sort(liczbyPierwsze, 0, liczbyPierwsze.length - 1);
        System.out.println("\n\nPo sortowaniu:");
        for(int i : liczbyPierwsze){
            System.out.print(i + ", ");
        }
    }
}