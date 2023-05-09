#include <stdio.h>

int main() {
    int W, K, liczba;
    printf("Podaj liczbe wierszy: ");
    scanf("%d", &W);
    printf("Podaj liczbe kolumn: ");
    scanf("%d", &K);
    int A[W][K], B[K][W], C[W][W];
    for(int i=0; i<W; i++){
        for(int j=0; j<K; j++){
            printf("Podaj liczbe dla %d wiersza i %d kolumny tablicy A: ", i+1, j+1);
            scanf("%d", &liczba);
            A[i][j] = liczba;
        }
    }
    for(int i=0; i<K; i++){
        for(int j=0; j<W; j++){
            printf("Podaj liczbe dla %d wiersza i %d kolumny tablicy B: ", i+1, j+1);
            scanf("%d", &liczba);
            B[i][j] = liczba;
        }
    }
    
    printf("\nTablica A:\n");
    for(int i=0; i<W; i++){
        for(int j=0; j<K; j++){
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    
    printf("\nTablica B:\n");
    for(int i=0; i<K; i++){
        for(int j=0; j<W; j++){
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }
    
    printf("\nWynik mnozenia AB:\n");
    for(int i=0; i<W; i++){
        for(int j=0; j<W; j++){
            C[i][j] = 0;
            for(int l=0; l<K; l++)
                C[i][j]+=A[i][l]*B[l][j];
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
}