#include <stdio.h>
#include <string.h>

void ingresarAlimentos(char alimentos[][30], float precios[], int cantidades[], int numeroitem, int nuevosAlimentos) {
    for (int i = numeroitem; i < numeroitem + nuevosAlimentos; i++) {
        printf("Ingrese el nombre del alimento %d: ", i + 1);
        scanf("%s", alimentos[i]);
        printf("Ingrese el precio del alimento %d: ", i + 1);
        scanf("%f", &precios[i]);
        printf("Ingrese la cantidad del alimento %d: ", i + 1);
        scanf("%d", &cantidades[i]);
    }
}

void imprimirAlimentos(char alimentos[][30], float precios[], int cantidades[], int n) {
    printf("Nombre\t\t\tPrecio\t\tCantidad\n");
    for (int i = 0; i < n; i++) {
        printf("%-20s\t%.2f\t\t%d\n", alimentos[i], precios[i], cantidades[i]);
    }
}

void imprimiradvertencia() {
    printf("\nTiempo aproximado de descomposición de la carne (en dias):\n");
    printf("Carne cruda refrigerada: Pollo/pavo (1-2 dias), Res/cerdo (3-5 dias)\n");
    printf("Carne cocida refrigerada: Pollo/pavo (3-4 dias), Res/cerdo (3-4 dias)\n");
    printf("Carne congelada: Hasta varios meses\n");
    printf("Condiciones ambiente: Comienza a descomponerse rapidamente\n");
}

int BuscarAlimento(char alimentos[][30], char nombreAlimento[], int n) {
    for (int i = 0; i < n; i++) {
        if (strcmp(alimentos[i], nombreAlimento) == 0) {
            return i;
        }
    }
    return -1;
}

void imprimirAlimentoIndex(char alimentos[][30], float precios[], int cantidades[], int index) {
    if (index != -1) {
        printf("Los datos del alimento son:\n");
        printf("Nombre: %s\n", alimentos[index]);
        printf("Precio: %.2f\n", precios[index]);
        printf("Cantidad: %d\n", cantidades[index]);
        imprimiradvertencia();
    } else {
        printf("No existe el alimento en el inventario.\n");
    }
}

void editarAlimento(char alimentos[][30], float precios[], int cantidades[], int n) {
    char nombreAlimento[30];
    printf("Ingrese el nombre del alimento que desea editar: ");
    scanf("%s", nombreAlimento);
    int index = BuscarAlimento(alimentos, nombreAlimento, n);
    if (index != -1) {
        printf("Ingrese el nuevo nombre del alimento: ");
        scanf("%s", alimentos[index]);
        printf("Ingrese el nuevo precio del alimento: ");
        scanf("%f", &precios[index]);
        printf("Ingrese la nueva cantidad del alimento: ");
        scanf("%d", &cantidades[index]);
        printf("Alimento actualizado.\n");
    } else {
        printf("No existe el alimento %s en el inventario.\n", nombreAlimento);
    }
}

void eliminarAlimento(char alimentos[][30], float precios[], int cantidades[], int *n) {
    char nombreAlimento[30];
    printf("Ingrese el nombre del alimento que desea eliminar: ");
    scanf("%s", nombreAlimento);
    int index = BuscarAlimento(alimentos, nombreAlimento, *n);
    if (index != -1) {
        for (int i = index; i < *n - 1; i++) {
            strcpy(alimentos[i], alimentos[i + 1]);
            precios[i] = precios[i + 1];
            cantidades[i] = cantidades[i + 1];
        }
        (*n)--;
        printf("Alimento eliminado.\n");
    } else {
        printf("No existe el alimento %s en el inventario.\n", nombreAlimento);
    }
}
void opcionIngresarAlimentos(char alimentos[][30], float precios[], int cantidades[], int *numeroitem, int maximoinventario) {
    int nuevosAlimentos;
    printf("¿Cuantos alimentos desea ingresar? ");
    scanf("%d", &nuevosAlimentos);
    if (*numeroitem + nuevosAlimentos > maximoinventario) {
        printf("El numero maximo es %d\n", maximoinventario - *numeroitem);
        nuevosAlimentos = maximoinventario - *numeroitem;
    }
    ingresarAlimentos(alimentos, precios, cantidades, *numeroitem, nuevosAlimentos);
    *numeroitem += nuevosAlimentos;
}

void opcionBuscarAlimento(char alimentos[][30], float precios[], int cantidades[], int numeroitem) {
    printf("Ingrese el nombre del alimento que desea ver: ");
    char nombre[30];
    scanf("%s", nombre);
    int index = BuscarAlimento(alimentos, nombre, numeroitem);
    imprimirAlimentoIndex(alimentos, precios, cantidades, index);
}

void leeralimentos(char alimentos[][30], char *alimentodoc) {
    FILE *file = fopen("D:/Documentos/alimentos.txt", "r");
    if (!file) {
        printf("No se pudo abrir el archivo %s\n", alimentodoc);
        FILE *file = fopen("D:/Documentos/alimentos.txt", "w");
        return;
    }
    for (int i = 0; i < 10; i++) {
        if (fscanf(file, "%s", alimentos[i]) != 1) {
            break;
        }
    }
    fclose(file);
}

void leerprecios(float precios[], char *preciosdoc) {
    FILE *file = fopen("D:/Documentos/precios.txt", "r");
    if (!file) {
        printf("No se pudo abrir el archivo %s\n", preciosdoc);
        FILE *file = fopen("D:/Documentos/precios.txt", "w");
        return;
    }
    for (int i = 0; i < 10; i++) {
        if (fscanf(file, "%f", &precios[i]) != 1) {
            break;
        }
    }
    
    fclose(file);
}

void leercantidades(int cantidades[], char *cantidadesdoc) {
    FILE *file = fopen("D:/Documentos/cantidades.txt", "r");
    if (!file) {
        printf("No se pudo abrir el archivo %s\n", cantidadesdoc);
        FILE *file = fopen("D:/Documentos/cantidades.txt", "w");
        return;
    }
    for (int i = 0; i < 10; i++) {
        if (fscanf(file, "%d", &cantidades[i]) != 1) {
            break;
        }
    }
    
    fclose(file);
}

void guardaralimentos(char alimentos[][30], char *alimentodoc) {
    FILE *file = fopen("D:/Documentos/alimentos.txt", "w");
    if (!file) {
        printf("No se pudo abrir el archivo %s\n", alimentodoc);
        return;
    }
    for (int i = 0; i < 10; i++) {
        if (alimentos[i][0] != '\0') {
            fprintf(file, "%s\n", alimentos[i]);
        }
    }
    fclose(file);
}

void guardarprecios(float precios[], char *preciosdoc) {
    FILE *file = fopen("D:/Documentos/precios.txt", "w");
    if (!file) {
        printf("No se pudo abrir el archivo %s\n", preciosdoc);
        return;
    }
    for (int i = 0; i < 10; i++) {
        if (precios[i] != 0.0) {
            fprintf(file, "%f\n", precios[i]);
        }
    }
    fclose(file);
}

void guardarcantidades(int cantidades[], char *cantidadesdoc) {
    FILE *file = fopen("D:/Documentos/cantidades.txt", "w");
    if (!file) {
        printf("No se pudo abrir el archivo %s\n", cantidadesdoc);
        return;
    }
    for (int i = 0; i < 10; i++) {
        fprintf(file, "%d\n", cantidades[i]);
    }
    fclose(file);
}