#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

srand(time(NULL));

// codigo a completar
#define N 20
    int i;
    double vt[N];
    double *puntero = &vt[0]; // Apunta al primer elemento del array
    for (i = 0; i < N; i++)
    {
        *(puntero + i) = 1 + rand() % 100;
        printf("%.2lf \n", *(puntero + i));

    }

    return 0;
}