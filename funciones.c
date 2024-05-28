#include <stdio.h>
#include <string.h>

void ingresarAlimentos(char alimentos[][3][30], float precios[], int cantidades[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Ingrese el nombre del alimento %d: ", i + 1);
        scanf("%s", alimentos[i][0]);
        printf("Ingrese el precio del alimento %d: ", i + 1);
        scanf("%f", &precios[i]);
        printf("Ingrese la cantidad del alimento %d: ", i + 1);
        scanf("%d", &cantidades[i]);
    }
}

void imprimirAlimentos(char alimentos[][3][30], float precios[], int cantidades[], int n) {
    printf("Nombre\t\t\tPrecio\t\tCantidad\n");
    for (int i = 0; i < n; i++) {
        printf("%-30s\t%.2f\t\t%d\n", alimentos[i][0], precios[i], cantidades[i]);
    }
}

void imprimiradvertencia() {
    printf("\nTiempo aproximado de descomposición de la carne (en dias):\n");
    printf("Carne cruda refrigerada: Pollo/pavo (1-2 dias), Res/cerdo (3-5 dias)\n");
    printf("Carne cocida refrigerada: Pollo/pavo (3-4 dias), Res/cerdo (3-4 dias)\n");
    printf("Carne congelada: Hasta varios meses\n");
    printf("Condiciones ambiente: Comienza a descomponerse rapidamente\n");
}

int BuscarAlimento(char alimentos[][3][30], char nombreAlimento[], int n) {
    for (int i = 0; i < n; i++) {
        if (strcmp(alimentos[i][0], nombreAlimento) == 0) {
            return i;
        }
    }
    return -1;
}

void imprimirAlimentoIndex(char alimentos[][3][30], float precios[], int cantidades[], int index) {
    if (index != -1) {
        printf("Los datos del alimento son:\n");
        printf("Nombre: %s\n", alimentos[index][0]);
        printf("Precio: %.2f\n", precios[index]);
        printf("Cantidad: %d\n", cantidades[index]);
    } else {
        printf("No existe el alimento en el inventario.\n");
    }
}

void editarAlimento(char alimentos[][3][30], float precios[], int cantidades[], int n) {
    char nombreAlimento[30];
    printf("Ingrese el nombre del alimento que desea editar: ");
    scanf("%s", nombreAlimento);
    int index = BuscarAlimento(alimentos, nombreAlimento, n);
    if (index != -1) {
        printf("Ingrese el nuevo nombre del alimento: ");
        scanf("%s", alimentos[index][0]);
        printf("Ingrese el nuevo precio del alimento: ");
        scanf("%f", &precios[index]);
        printf("Ingrese la nueva cantidad del alimento: ");
        scanf("%d", &cantidades[index]);
        printf("Alimento actualizado.\n");
    } else {
        printf("No existe el alimento %s en el inventario.\n", nombreAlimento);
    }
}

void eliminarAlimento(char alimentos[][3][30], float precios[], int cantidades[], int *n) {
    char nombreAlimento[30];
    printf("Ingrese el nombre del alimento que desea eliminar: ");
    scanf("%s", nombreAlimento);
    int index = BuscarAlimento(alimentos, nombreAlimento, *n);
    if (index != -1) {
        for (int i = index; i < *n - 1; i++) {
            strcpy(alimentos[i][0], alimentos[i + 1][0]);
            precios[i] = precios[i + 1];
            cantidades[i] = cantidades[i + 1];
        }
        (*n)--;
        printf("Alimento eliminado.\n");
    } else {
        printf("No existe el alimento %s en el inventario.\n", nombreAlimento);
    }
}