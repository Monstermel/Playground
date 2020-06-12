#include <stdio.h>

#include "menus.h"


void menu_general(int *opc) {
    system("cls"); //Windows
    printf(" ***Graficos estadisticos COVID-19***\n\n");
    //Agregas tantas opciones como necesites
    printf("  1) Nuevo estado\n");
    printf("  2) Modificar estado\n");
    printf("  3) Borrar estado\n");
    printf("  4) Nueva persona\n");
    printf("  5) Modificar persona\n");
    printf("  6) Borrar persona\n");
    printf("  7) Registrar casos\n");
    printf("  8) Graficos\n");
    printf("  9) Salir\n\n");
    ////////////////////////////////////////
    printf(" Teclea la opcion requerida: ");
    scanf("%d", opc);
    while (*opc < 1 || 9 < *opc){
        printf(" ¡Opcion no valida!\n");
        system("pause");
        printf(" Tecleea la opcion requerida: ");
        scanf("%d", opc);
    }
    return;
}

void menu_graficos(int *opc) {
    system("cls"); //Windows
    printf(" ***Menu graficos***\n\n");
    //Agregas tantas opciones como necesites
    printf("  1) Positivos y no positivos general, acumulado\n");
    printf("  2) Evolución de positivos por estado\n");
    printf("  3) Evolución de positivos por estado, acumulado\n");
    printf("  4) Evolución de positivos general\n");
    printf("  5) Evolución de positivos general, acumulado\n");
    printf("  6) Regresar al menú general\n");
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

void menu_modificar_persona(int *opc) {
    system("cls"); //Windows
    printf(" ***Modificar persona***\n\n");
    //Agregas tantas opciones como necesites
    printf("  1) Modificar numero de seguro social \n");
    printf("  2) Modificar nombre\n");
    printf("  3) Modificar domicilio\n");
    printf("  4) Modificar edad\n");
    printf("  5) Modificar genero\n");
    printf("  6) Regresar al menú general\n");
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
      system("cls"); //Windows
    printf(" ***Modificar estado***\n\n");
    //Agregas tantas opciones como necesites
    printf("  1) Modificar descripcion\n");
    printf("  2) Modificar poblacion\n");
    printf("  3) Regresar al menú general\n");
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
