#include <stdio.h>
#include <stdlib.h>
#include "menus.h"


void menu_general(int *opc) {

    printf("\n***Graficos estadisticos COVID-19***\n\n");
    //Agregas tantas opciones como necesites
    printf("  1) Nuevo estado\n");
    printf("  2) Modificar estado\n");
    printf("  3) Borrar estado\n");
    printf("  4) Nueva persona\n");
    printf("  5) Modificar persona\n");
    printf("  6) Borrar persona\n");
    printf("  7) Registrar casos\n");
    printf("  8) Graficos\n");
    printf("  9) Listar estados\n");
    printf(" 10) Listar personas\n");
    printf(" 11) Listar casos\n");
    printf(" 12) Salir\n\n");
    ////////////////////////////////////////
    printf(" Teclea la opcion requerida: ");
    scanf("%d", opc);
    while (*opc < 1 || 12 < *opc){
        printf(" ¡Opcion no valida!\n");
        system("pause");
        printf(" Tecleea la opcion requerida: ");
        scanf("%d", opc);
    }

    return;
}

void menu_graficos(int *opc) {
    printf("\n***Menu graficos***\n\n");
    //Agregas tantas opciones como necesites
    printf(" 1) Positivos y no positivos general, acumulado\n");
    printf(" 2) Evolucion de positivos por estado\n");
    printf(" 3) Evolucion de positivos por estado, acumulado\n");
    printf(" 4) Evolucion de positivos general\n");
    printf(" 5) Evolucion de positivos general, acumulado\n");
    printf(" 6) Regresar al menu general\n\n");
    ////////////////////////////////////////
    printf("Teclea la opcion requerida: ");
    scanf("%d", opc);
    while (*opc < 1 || 6 < *opc){
        printf(" ¡Opcion no valida!\n");
        system("pause");
        printf(" Tecleea la opcion requerida: ");
        scanf("%d", opc);
    }
    return;
}

void menu_modificar_persona(int *opc) {
    printf("\n***Modificar persona***\n\n");
    //Agregas tantas opciones como necesites
    printf("  1) Modificar numero de seguro social \n");
    printf("  2) Modificar nombre\n");
    printf("  3) Modificar domicilio\n");
    printf("  4) Modificar edad\n");
    printf("  5) Modificar genero\n");
    printf("  6) Regresar al menu general\n\n");
    ////////////////////////////////////////
    printf(" Teclea la opcion requerida: ");
    scanf("%d", opc);
    while (*opc < 1 || 6 < *opc){
        printf(" ¡Opcion no valida!\n");
        system("pause");
        printf(" Tecleea la opcion requerida: ");
        scanf("%d", opc);
    }
    return;
}

void menu_modificar_estado(int *opc) {
    printf("\n***Modificar estado***\n\n");
    //Agregas tantas opciones como necesites
    printf("  1) Modificar poblacion\n");
    printf("  2) Regresar al menu general\n\n");
    ////////////////////////////////////////
    printf(" Teclea la opcion requerida: ");
    scanf("%d", opc);
    while (*opc < 1 || 2 < *opc){
        printf(" ¡Opcion no valida!\n");
        system("pause");
        printf(" Tecleea la opcion requerida: ");
        scanf("%d", opc);
    }
    return;
}
