#include <stdio.h>
#include <stdlib.h>
#include <winbgim.h>
#include <graphics.h>

#include "pastel.h"
#include "barras.h"
#include "cuadricula.h"
#include "menus.h"
#include "registros.h"
#include "algoritmos.h"


void switch_estado(){

    int registro, opc;
    _uint_8 ID;

    printf("\n***Modificar estado\n");
    ID = captura_estadoID();

    if(buscar_estado(ID, &registro)){

        FILE *fp;
        Estado buffer;

        fp = fopen(F_ESTADOS,"r+b");

        if(fp == NULL){
            printf("No fue posible abrir el archivo\n");
            system("pause");
            return;
        }

        fseek(fp, registro*sizeof(Estado), SEEK_SET);
        fread(&buffer, sizeof(Estado), 1, fp);

        do{
            system("cls");
            printf("\n*Estado encontrado:\n");
            imprimir_ESTADO(buffer);
            menu_modificar_estado(&opc);

            switch (opc){
                case 1:
                    buffer.poblacion = capturar_poblacion();
                    break;
                case 2:
                    fseek(fp, registro*sizeof(Estado), SEEK_SET);
                    fwrite(&buffer, sizeof(Estado), 1, fp);
                    fclose(fp);
                    break;
                }

        } while (opc != 2);

    }
    else{

      printf("Estado no disponible\n");

    }

    return;
}

int main(void){
    int opc;
    do{
        system("cls");
        menu_general(&opc);
        switch (opc){
            case 1://Apartado listo
                system("cls");
                nuevo_estado();
                system("pause");
                break;
            case 2://Apartado listo
                system("cls");
                switch_estado();
                system("pause");
                break;
            case 3://Apartado listo
                system("cls");
                borrar_estado();
                system("pause");
                break;
            case 4:
                system("cls");
                nueva_persona();
                system("pause");
                break;
            case 5:
                //Modificar persona
                break;
            case 6:
                //Borrar persona
                break;
            case 7:
                //Registrar caso
                break;
            case 8:
                //Menu graficos
                break;
            case 9:
                break;
        }
    } while (opc != 9);




    return 0;
}
