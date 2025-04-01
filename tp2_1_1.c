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
    for (i = 0; i < N; i++)
    {
        vt[i] = 1 + rand() % 100;
        printf("%lf \n", vt[i]);

    }

    return 0;
}
