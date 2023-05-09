#include <stdio.h>

int main() {
    int m, n, liczba;
    printf("Podaj ilosc wierszy (m): ");
    scanf("%d", &m);
    printf("Podaj ilosc kolumn (n): ");
    scanf("%d", &n);
    int A[m][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            printf("%d wiersz, %d kolumna: ", j, i);
            scanf("%d", &liczba);
            A[j][i]=liczba;
        }
    }
    printf("\nTablica A:\n");
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    int B[m], k, l;
    printf("Podaj liczbe od ktorej mam liczyc ilosc wiekszych elementow (k): ");
    scanf("%d", &k);
    for(int i=0; i<m; i++){
        l=0;
        for(int j=0; j<n; j++){
            if(A[i][j]>k)
                l++;
        }
        B[i]=l;
    }
    printf("\nUtworzony wektor: ");
    for(int i = 0; i<m; i++)
        printf("%d, ", B[i]);
    return 0;
}