
#include <graphics.h>
#include <winbgim.h>
#include <stdlib.h>
#include <stdio.h>

#include "cuadricula.h"
#include "algoritmos.h"
#include "registros.h"
#include "pastel.h"
#include "barras.h"
#include "menus.h"


void modificar_estado(void){

    int registro, opc;
    _uint_8 ID;

    printf("\n***Modificar estado\n");
    ID = capturar_estadoID();

    if(buscar_estado(ID, &registro)){

        FILE *fp = fopen(F_ESTADOS,"r+b");
        if(fp == NULL){
            printf("No fue posible abrir el archivo\n");
            system("pause");
            return;
        }

        Estado buffer;
        fseek(fp, registro*sizeof(Estado), SEEK_SET);
        fread(&buffer, sizeof(Estado), 1, fp);

        do{

            system("cls");
            printf("\n*Estado encontrado:\n");
            imprimir_ESTADO(buffer);
            menu_modificar_estado(&opc);

            switch (opc){
                case 1:
                    system("cls");
                    buffer.poblacion = capturar_poblacion();
                    system("pause");
                    break;
                case 2:
                    fseek(fp, registro*sizeof(Estado), SEEK_SET);
                    fwrite(&buffer, sizeof(Estado), 1, fp);
                    fclose(fp);
                    break;
            }

        }while(opc != 2);

    }
    else{

        printf("Estado no disponible\n");

    }

    return;
}

void modificar_persona(void){

    int registro, opc;
    char *aux;

    printf("\n***Modificar persona\n");
    aux = capturar_numSS();

    if(buscar_persona(aux, &registro)){

        free(aux);
        aux = NULL;

        FILE *fp = fopen(F_PERSONAS,"r+b");
        if(fp == NULL){
            printf("No fue posible abrir el archivo\n");
            system("pause");
            return;
        }

        Persona buffer;
        fseek(fp, registro*sizeof(Persona), SEEK_SET);
        fread(&buffer, sizeof(Persona), 1, fp);

        do{
            system("cls");
            printf("\n*Persona encontrada:\n");
            imprimir_PERSONA(buffer);
            menu_modificar_persona(&opc);

            switch (opc){
                case 1:
                    system("cls");
                    aux = generar_numSS();
                    strcpy(buffer.num_SS,aux);
                    free(aux);
                    aux = NULL;
                    system("pause");
                    break;
                case 2:
                    system("cls");
                    buffer.nombre = capturar_nombre();
                    system("pause");
                    break;
                case 3:
                    system("cls");
                    buffer.domicilio = capturar_domicilio();
                    system("pause");
                    break;
                case 4:
                    system("cls");
                    buffer.edad = capturar_edad();
                    system("pause");
                    break;
                case 5:
                    system("cls");
                    buffer.genero = capturar_genero();
                    system("pause");
                    break;
                case 6:
                    fseek(fp, registro*sizeof(Persona), SEEK_SET);
                    fwrite(&buffer, sizeof(Persona), 1, fp);
                    fclose(fp);
                    break;
            }

        }while(opc != 6);

    }
    else{

        printf("Persona no disponible\n");
        system("pause");

    }

    free(aux);
    return;
}

void switch_graficos(void){

    char *text_1 = NULL, text_2[100];
    unsigned int *casos = NULL;
    int opc, aux, registro[2];
    size_t elementos, i;
    _uint_8 ID;

    do{

        system("cls");
        menu_graficos(&opc);

        switch (opc){
            case 1://Apartado listo

                system("cls");
                //Buscamos los casos positivos y negativos
                if(!buscar_caso_PN(registro)){
                    break;
                }

                //Imprimimos los graficos de pastel
                graficos_pastel(registro[negativo]+registro[positivo],
                              registro[positivo], registro[negativo]);

                system("pause");
                closegraph();
                break;

            case 2://Apartado listo

                system("cls");
                //Capturamos la ID del estado requerido y comprobamos que este registrado
                ID        = capturar_estadoID();
                if(!buscar_estado(ID, &aux)){
                    printf("\nEstado no disponible\n\n");
                    system("pause");
                    break;
                }

                //Buscamos los casos postivos de un estado y obtenemos el numero de elementos
                elementos = buscar_casos_PE(ID, &casos);

                //Revisamos que no haya ocurrido errores y que si tenga casos positivos
                if(elementos == -1) {
                    system("pause");
                    break;
                }
                if(!elementos){
                    printf("\nEste estado no tiene casos positivos\n\n");
                    system("pause");
                    free(casos);
                    break;
                }

                //Registramos cuantos casos tiene una fecha y obtenemos el numero de elementos
                elementos = buscar_casos_BE(casos, elementos);

                //Generamos el texto a imprimir en las barras y imprimimos las barras
                text_1 = capturar_descripcion(ID);
                sprintf(text_2, "Evolucion de positivos, %s", text_1);
                graficos_barras(text_2, 1, elementos, elementos, casos);

                system("pause");
                closegraph();
                free(text_1);
                free(casos);
                text_1 = NULL;
                casos  = NULL;
                break;

            case 3:

                system("cls");
                //Capturamos la ID del estado requerido y comprobamos que este registrado
                ID        = capturar_estadoID();
                if(!buscar_estado(ID, &aux)){
                    printf("\nEstado no disponible\n\n");
                    system("pause");
                    break;
                }

                //Buscamos los casos postivos de un estado y obtenemos el numero de elementos
                elementos = buscar_casos_PE(ID, &casos);

                //Revisamos que no haya ocurrido errores y que si tenga casos positivos
                if(elementos == -1) {
                    system("pause");
                    break;
                }
                if(!elementos){
                    printf("\nEste estado no tiene casos positivos\n\n");
                    system("pause");
                    free(casos);
                    break;
                }

                //Registramos cuantos casos tiene una fecha y obtenemos el numero de elementos
                elementos = buscar_casos_BE(casos, elementos);

                //Hacemos la acumulada
                for(i = 1; i < elementos; i++){
                    casos[i] += casos[i-1];
                }

                //Generamos el texto a imprimir en las barras y imprimimos las barras
                text_1 = capturar_descripcion(ID);
                sprintf(text_2, "Evolucion de positivos(acumulado), %s", text_1);
                graficos_barras(text_2, 1, elementos, elementos, casos);

                system("pause");
                closegraph();
                free(text_1);
                free(casos);
                text_1 = NULL;
                casos  = NULL;
                break;

            case 4:

                system("cls");
                //Buscamos los casos postivos generales y obtenemos el numero de elementos
                elementos = buscar_casos_PG(&casos);

                //Revisamos que no haya ocurrido errores y que si tenga casos positivos
                if(elementos == -1) {
                    system("pause");
                    break;
                }
                if(!elementos){
                    printf("\nEste estado no tiene casos positivos\n\n");
                    system("pause");
                    free(casos);
                    break;
                }

                //Registramos cuantos casos tiene una fecha y obtenemos el numero de elementos
                elementos = buscar_casos_BE(casos, elementos);

                //Imprimimos las barras
                graficos_barras("Evolucion de positivos(general)",
                                  1, elementos, elementos, casos);

                system("pause");
                closegraph();
                free(casos);
                casos  = NULL;
                break;

            case 5:

                system("cls");
                //Buscamos los casos postivos generales y obtenemos el numero de elementos
                elementos = buscar_casos_PG(&casos);

                //Revisamos que no haya ocurrido errores y que si tenga casos positivos
                if(elementos == -1) {
                    system("pause");
                    break;
                }
                if(!elementos){
                    printf("\nEste estado no tiene casos positivos\n\n");
                    system("pause");
                    free(casos);
                    break;
                }

                //Registramos cuantos casos tiene una fecha y obtenemos el numero de elementos
                elementos = buscar_casos_BE(casos, elementos);

                //Hacemos la acumulada
                for(i = 1; i < elementos; i++){
                    casos[i] += casos[i-1];
                }

                //Imprimimos las barras
                graficos_barras("Evolucion de positivos(general)",
                                  1, elementos, elementos, casos);

                system("pause");
                closegraph();
                free(casos);
                casos  = NULL;
                break;

            case 6:
                break;
            }
    } while (opc != 6);

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
                crear_estado();
                system("pause");
                break;
            case 2://Apartado listo
                system("cls");
                modificar_estado();
                break;
            case 3://Apartado listo
                system("cls");
                borrar_estado();
                system("pause");
                break;
            case 4://Apartado listo
                system("cls");
                crear_persona();
                system("pause");
                break;
            case 5://Apartado listo
                system("cls");
                modificar_persona();
                break;
            case 6://Apartado listo
                system("cls");
                borrar_persona();
                system("pause");
                break;
            case 7://Apartado listo
                system("cls");
                crear_caso();
                system("pause");
                break;
            case 8://Apartado listo
                system("cls");
                switch_graficos();
                break;
            case 9:
                system("cls");
                listar_estados();
                system("pause");
                break;
            case 10:
                system("cls");
                listar_personas();
                system("pause");
                break;
            case 11:
                system("cls");
                listar_casos();
                system("pause");
                break;
            case 12:
                break;

        }

    } while (opc != 12);

    return 0;
}
