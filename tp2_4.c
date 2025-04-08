#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct compu {
    int velocidad; // Velocidad de procesamiento en GHz (valor entre 1 y 3)
    int anio; // Año de fabricación (valor entre 2015 y 2024)
    int cantidad_nucleos; // Cantidad de núcleos (valor entre 1 y 8)
    char *tipo_cpu; // Tipo de procesador (apuntador a cadena de caracteres)
};

void listarPCs(struct compu pcs[], int cantidad) {
    // Mostrar los datos generados
    for (int i = 0; i < cantidad; i++) {
        printf("PC %d:\n", i + 1);
        printf("  Velocidad: %d GHz\n", pcs[i].velocidad);
        printf("  Anio: %d\n", pcs[i].anio);
        printf("  Nucleos: %d\n", pcs[i].cantidad_nucleos);
        printf("  Tipo CPU: %s\n\n", pcs[i].tipo_cpu);
        printf("--------------------------------------\n");
    }
}

void mostrarMasVieja(struct compu pcs[], int cantidad) {
    int vieja = 3000;
    int indice_pc_vieja = 0;

    for (int i = 0; i < cantidad; i++) {
        if(vieja > pcs[i].anio) {
            vieja = pcs[i].anio; 
            indice_pc_vieja = i;
        } 
    }
    printf("Caracteristicas de la PC mas vieja: PC %d\n", indice_pc_vieja + 1);
    printf("  Velocidad: %d GHz\n", pcs[indice_pc_vieja].velocidad);
    printf("  Anio: %d\n", pcs[indice_pc_vieja].anio);
    printf("  Nucleos: %d\n", pcs[indice_pc_vieja].cantidad_nucleos);
    printf("  Tipo CPU: %s\n\n", pcs[indice_pc_vieja].tipo_cpu);
    printf("  La computadora mas vieja es del anio: %d \n\n", vieja);
    printf("--------------------------------------\n");         
}

void mostrarMasVeloz(struct compu pcs[], int cantidad) {
    int mas_rapida = 0;
    int indice_pc_rapida = 0;

    for (int i = 0; i < cantidad; i++)
    {
        if (mas_rapida < pcs[i].velocidad) {
            mas_rapida = pcs[i].velocidad;
            indice_pc_rapida = i;
        }
    }
    printf("Caracteristicas de la PC mas rapida: PC %d\n", indice_pc_rapida + 1);
    printf("  Velocidad: %d GHz\n", pcs[indice_pc_rapida].velocidad);
    printf("  Anio: %d\n", pcs[indice_pc_rapida].anio);
    printf("  Nucleos: %d\n", pcs[indice_pc_rapida].cantidad_nucleos);
    printf("  Tipo CPU: %s\n\n", pcs[indice_pc_rapida].tipo_cpu);
    printf("  La computadora mas rapida tiene de velociad: %dGHz \n", mas_rapida); 
}

int main () {
    srand(time(NULL));

    char tipos[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"}; // Esto es un arreglo de 6 strings, y cada string puede tener hasta 9 caracteres
    struct compu pcs[5]; // Arreglo de 5 computadoras

    for (int i = 0; i < 5; i++) {
        pcs[i].velocidad = 1 + rand() % 3;               // entre 1 y 3
        pcs[i].anio = 2015 + rand() % (2024 - 2015 + 1); // entre 2015 y 2024
        pcs[i].cantidad_nucleos = 1 + rand() % 8;        // entre 1 y 8
        pcs[i].tipo_cpu = tipos[rand() % 6];             //rand() % 6: genera un numero aleatorio entre 0 y 5 (porque % 6 da 6 posibles valores).
    }

    listarPCs(pcs, 5);
    mostrarMasVieja(pcs, 5);
    mostrarMasVeloz(pcs, 5);

    return 0;
}