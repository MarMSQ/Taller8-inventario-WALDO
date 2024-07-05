#include <stdio.h>
#include "funciones.h"
#define maximoinventario 10

int main(int argc, char *argv[]) {
    char alimentos[maximoinventario][30];
    float precios[maximoinventario];
    int cantidades[maximoinventario];
    int numeroitem = 0, opcion, opcionr,nuevosAlimentos;

    leeralimentos(alimentos, "D:/Documentos/alimentos.txt");
    leerprecios(precios, "D:/Documentos/precios.txt");   
    leercantidades(cantidades, "D:/Documentos/cantidades.txt");

    printf("BIENVENIDOS A CARNICERIA WALDO\n");
    do {
        printf("Seleccione una opcion:\n1. Ingresar Alimentos\n2. Buscar alimentos\n3. Eliminar alimentos\n4. Editar alimento\n5. Imprimir Inventario\n>> ");
        scanf("%d", &opcion);
        switch (opcion) {
            case 1:
                opcionIngresarAlimentos(alimentos, precios, cantidades, &numeroitem, maximoinventario);
                guardaralimentos(alimentos, "alimentos.txt");
                guardarprecios(precios, "precios.txt");
                guardarcantidades(cantidades, "cantidades.txt");
                break;
            case 2:
                opcionBuscarAlimento(alimentos, precios, cantidades, numeroitem);
                break;
            case 3:
                eliminarAlimento(alimentos, precios, cantidades, &numeroitem);
                guardaralimentos(alimentos, "alimentos.txt");
                guardarprecios(precios, "precios.txt");
                guardarcantidades(cantidades, "cantidades.txt");
                break;
            case 4:
                editarAlimento(alimentos, precios, cantidades, numeroitem);
                guardaralimentos(alimentos, "alimentos.txt");
                guardarprecios(precios, "precios.txt");
                guardarcantidades(cantidades, "cantidades.txt");
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
