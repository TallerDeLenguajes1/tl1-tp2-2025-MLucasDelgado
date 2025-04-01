#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    #define N 5
    #define M 7

    int i, j;
    int mt[N][M];
    int *puntero = &mt[0][0]; // Puntero al primer elemento de la matriz

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            // *(puntero + i * M + j) Calcula la direccion correcta dentro de la memoria
            // *(puntero + i * M + j) Con * obtenemos el contenido de esa direccion
            // *(puntero + i * M + j) Es lo mismo que mt[i][j]

            *(puntero + i * M + j) = 1 + rand() % 100; 
            printf("%d ", *(puntero + i * M + j));
        }

        // i * m nos mueve i filas completas (cada fila tiene M elementos)
        // j nos mueve j posiciones dentro de la fila

        printf("\n");
    }

    return 0;
}
