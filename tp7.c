#include <stdio.h>
#include <stdlib.h> 
//Repositorio: https://github.com/ludmifeldmann21/imc.c/blob/main/tp7.c
int main() {
    int *codigos;
    float *precios;
    int tam, i;
    int pos_mayor = 0, pos_menor = 0;
    printf("Ingrese la cantidad de productos a gestionar: ");
    scanf("%d", &tam);
    codigos = (int *) malloc(tam * sizeof(int));
    precios = (float *) malloc(tam * sizeof(float)); 
    if (codigos == NULL || precios == NULL) {
        printf("Error: No hay memoria suficiente.\n");
        return 1;
    }
    printf("Ingrese %d productos, se solicitará el código y precio:\n", tam);

    for (i = 0; i < tam; i++) {
        do {
            printf("Ingrese el código de barras (1-999999999): ");
            scanf("%d", &codigos[i]);
            if (codigos[i] < 1 || codigos[i] > 999999999) {
                printf("Error, el código de barras debe estar entre 1 y 999999999\n");
            }
        } while (codigos[i] < 1 || codigos[i] > 999999999);
        do {
            printf("Ingrese el precio: ");
            scanf("%f", &precios[i]);
            
            if (precios[i] < 0) {
                printf("Error, el precio no puede ser negativo.\n");
            }
        } while (precios[i] < 0);
    }
    printf("\nCódigo\t Precio\n");
    for (i = 0; i < tam; i++) {
        printf("%8d %10.2f\n", codigos[i], precios[i]);
    }
    for (i = 1; i < tam; i++) {
        if (precios[i] > precios[pos_mayor]) {
            pos_mayor = i;
        }
        if (precios[i] < precios[pos_menor]) {
            pos_menor = i;
        }
    }
    printf("\nMás caro: [%d] %.2f\n", codigos[pos_mayor], precios[pos_mayor]);
    printf("Más barato: [%d] %.2f\n", codigos[pos_menor], precios[pos_menor]);
 
    free(codigos);
    free(precios);

    return 0;
}
