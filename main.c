#include <stdio.h>
#include "funciones.h"
#define maximoinventario 10

int main(int argc, char *argv[]) {
    char alimentos[maximoinventario][3][30];
    float precios[maximoinventario];
    int cantidades[maximoinventario];
    int numeroitem = 0, opcion, opcionr;
    printf("BIENVENIDOS A CARNICERIA WALDOWN");
    do {
        printf("Seleccione una opcion:\n1. Ingresar Alimentos\n2. Buscar alimentos\n3. Eliminar alimentos\n4. Editar alimento\n5. Imprimir Inventario\n>> ");
        scanf("%d", &opcion);
        switch (opcion) {
            case 1:
                printf("¿Cuantos alimentos desea ingresar? ");
                scanf("%d", &numeroitem);
                if (numeroitem > maximoinventario) {
                    printf("El numero maximo es %d\n", maximoinventario);
                    numeroitem = maximoinventario;
                }
                ingresarAlimentos(alimentos, precios, cantidades, numeroitem);
                break;
            case 2:
                printf("Ingrese el nombre del alimento que desea ver: ");
                scanf("%s", alimentos[0][0]);
                int index = BuscarAlimento(alimentos, alimentos[0][0], numeroitem);
                imprimirAlimentoIndex(alimentos, precios, cantidades, index);
                imprimiradvertencia();
                break;
            case 3:
                eliminarAlimento(alimentos, precios, cantidades, &numeroitem);
                break;
            case 4:
                editarAlimento(alimentos, precios, cantidades, numeroitem);
                break;
            case 5:
                imprimirAlimentos(alimentos, precios, cantidades, numeroitem);
                break;
            default:
                printf("Opcion no valida\n");
                break;
        }
        printf("Desea elegir una nueva opcion? 1.Si / 2.No\n>> ");
        scanf("%d", &opcionr);
    } while (opcionr == 1);

    return 0;
}
