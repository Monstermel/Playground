#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include "registros.h"

#define F_ESTADOS "registros/estados.dat"
#define F_PERSONAS "registros/personas.dat"
#define F_CASOS "registros/casos.dat"


_uint_8 captura_estadoID(void) {
    int buffer;
    printf("*Covid-19\n");
    printf(" 1) Aguascalientes\n");
    printf(" 2) Baja California\n");
    printf(" 3) Baja California Sur\n");
    printf(" 4) Campeche\n");
    printf(" 5) Chiapas\n");
    printf(" 6) Chihuahua\n");
    printf(" 7) Ciudad de Mexico\n");
    printf(" 8) Coahuila\n");
    printf(" 9) Colima\n");
    printf(" 10) Durango\n");
    printf(" 11) Estado de Mexico\n");
    printf(" 12) Guanajuato\n");
    printf(" 13) Guerrero\n");
    printf(" 14) Hidalgo\n");
    printf(" 15) Jalisco\n");
    printf(" 16) Michoacan\n");
    printf(" 17) Morelos\n");
    printf(" 18) Nayarit\n");
    printf(" 19) Nuevo Leon\n");
    printf(" 20) Oaxaca\n");
    printf(" 21) Puebla\n");
    printf(" 22) Queretaro\n");
    printf(" 23) Quintana Roo\n");
    printf(" 24) San Luis Potosi\n");
    printf(" 25) Sinaloa\n");
    printf(" 26) Sonora\n");
    printf(" 27) Tabasco\n");
    printf(" 28) Tamaulipas\n");
    printf(" 29) Tlaxcala\n");
    printf(" 30) Veracruz\n");
    printf(" 31) Yucatan\n");
    printf(" 32) Zacatecas\n");
    printf("Teclea la opcion requerida: ");
    scanf("%d", &buffer);
    while (buffer < 1 || 33 < buffer )
    {
        printf("Opcion no valida!\n");
        system("pause");
        printf("Tecleea la opcion requerida: ");
        scanf("%d", &buffer);
    }
    return (_uint_8)(buffer--);
}

Estado registrar_estado(void) {

    Estado buffer_estado;
    buffer_estado.estado = captura_estadoID();
    buffer_estado.borrado = No_borrado;
    printf("Descripcion del estado: ");
    fflush(stdin);
    gets(buffer_estado.descripcion);
    //Comprobador:
    printf("\n***Estado agregado:\n");
    printf("Nombre: %s\n", buffer_estado.descripcion);
    printf("ID: %d\n", buffer_estado.estado);
    ////
    return buffer_estado;
}

char* generar_numSS(void) {
    /*Codigo*/
}

Nombre captura_nombre(void) {
    /*Codigo*/
}

Domicilio captura_domicilio(void) {
    /*Codigo*/
}

_uint_8 captura_Genero(void) {
    /*Codigo*/
}

void imprimir_Nombre(Nombre imp)
{
    /*Codigo*/
}

void imprimir_Domicilio(Domicilio imp){
    /*Codigo*/
}

void imprimir_Genero( _uint_8 imp){
    /*Codigo*/
}

Persona registrar_persona(void){

    Persona buffer_persona;
    strcpy(buffer_persona.num_SS, generar_numSS());
    buffer_persona.borrado = No_borrado;
    buffer_persona.nombre = captura_nombre();
    buffer_persona.domicilio = captura_domicilio();
    buffer_persona.borrado = No_borrado;
    
    int buffer_edad;
    printf("Edad: "); scanf("%d",&buffer_edad);
    while(buffer_edad < 0 || 150 < buffer_edad){
        printf("Edad no valida\n");
        system("pause");
        printf("Edad: "); scanf("%d", &buffer_edad);
    }
    buffer_persona.edad = (_uint_8)buffer_edad;

    buffer_persona.genero = captura_Genero();

    //Comprobador:
    printf("\nPersona agregada:\n");
    imprimir_Nombre(buffer_persona.nombre);
    imprimir_Domicilio(buffer_persona.domicilio);
    printf("No. seguro social: %s\n", buffer_persona.num_SS);
    printf("Edad: %d",(int)buffer_persona.edad);
    imprimir_Genero(buffer_persona.genero);
    ////
    return buffer_persona;
}

char* capturar_numSS(void) {
    char buffer[12];
    
    printf("No. seguro social (11 digitos): ");
    fflush(stdin);
    gets(buffer);
    
    int error;
    do{
        error = 0;
        if(strlen(buffer) != 11){
            error = 1;
        }
        for(size_t i = 0; i < strlen(buffer) && !error; i++){
            if(buffer[i] < '0' || '9' < buffer[i] ){
                error = 1;
            }
        }
        if(error){
            printf("Opcion no valida!\n");
            system("pause");
            printf("No. seguro social (11 caracteres): ");
            fflush(stdin);
            gets(buffer);
        }
    }while(error);

    return buffer; 
}

Fecha capturar_fecha(void){
    Fecha buffer;
    int buffer_aux;
    printf("*Fecha\n");

    printf("Dia: "); scanf("%d",&buffer_aux);
    while(buffer_aux < 1 || 31 <buffer_aux){
        printf("Opcion no valida!\n");
        system("pause");
        printf("Dia: "); scanf("%d",&buffer_aux);
    }
    buffer.dia = (_uint)buffer_aux;

    printf("Mes: "); scanf("%d",&buffer_aux);
    while(buffer_aux < 1 || 12 <buffer_aux){
        printf("Opcion no valida!\n");
        system("pause");
        printf("Mes: "); scanf("%d",&buffer_aux);
    }
    buffer.mes = (_uint)buffer_aux;

    printf("A%co: ",164); scanf("%d",&buffer_aux);
    while(buffer_aux < 0 || 8388608 < buffer_aux){
        printf("Opcion no valida!\n");
        system("pause");
        printf("A%co: ",164); scanf("%d",&buffer_aux);
    }
    buffer.anio = (_uint)buffer_aux;

    return buffer;
}

_uint_8 capturar_covid(void){
    int buffer;
    printf("*Covid-19\n");
    printf(" 1) Negativo\n");
    printf(" 2) Positivo\n");
    printf("Teclea la opcion requerida: ");
    scanf("%d", &buffer);
    buffer--;
    while (buffer != 0 && buffer != 1)
    {
        printf("Opcion no valida!\n");
        system("pause");
        printf("Tecleea la opcion requerida: ");
        scanf("%d", &buffer);
        buffer--;
    }
    return (_uint_8)buffer;
}

void imprimir_estado(_uint_8 imp){
    switch(imp){
        case 1:
            printf("Estado: Aguascalientes\n"); 
            break;
        case 2:
            printf("Estado: Baja California\n");
            break;
        case 3:
            printf("Estado: Baja California Sur\n");
            break;
        case 4:
            printf("Estado: Campeche\n");
            break;
        case 5:
            printf("Estado: Chiapas\n");
            break;
        case 6:
            printf("Estado: Chihuahua\n");
            break;
        case 7:
            printf("Estado: Ciudad de Mexico\n");
            break;
        case 8:
            printf("Estado: Coahuila\n");
            break;
        case 9:
            printf("Estado: Colima\n");
            break;
        case 10:
            printf("Estado: Durango\n");
            break;
        case 11:
            printf("Estado: Estado de Mexico\n");
            break;
        case 12:
            printf("Estado: Guanajuato\n");
            break;
        case 13:
            printf("Estado: Guerrero\n");
            break;
        case 14:
            printf("Estado: Hidalgo\n");
            break;
        case 15:
            printf("Estado: Jalisco\n");
            break;
        case 16:
            printf("Estado: Michoacan\n");
            break;
        case 17:
            printf("Estado: Morelos\n");
            break;
        case 18:
            printf("Estado: Nayarit\n");
            break;
        case 19:
            printf("Estado: Nuevo Leon\n");
            break;
        case 20:
            printf("Estado: Oaxaca\n");
            break;
        case 21:
            printf("Estado: Puebla\n");
            break;
        case 22:
            printf("Estado: Queretaro\n");
            break;
        case 23:
            printf("Estado: Quintana Roo\n");
            break;
        case 24:
            printf("Estado: San Luis Potosi\n");
            break;
        case 25:
            printf("Estado: Sinaloa\n");
            break;
        case 26:
            printf("Estado: Sonora\n");
            break;
        case 27:
            printf("Estado: Tabasco\n");
            break;
        case 28:
            printf("Estado: Tamaulipas\n");
            break;
        case 29:
            printf("Estado: Tlaxcala\n");
            break;
        case 30:
            printf("Estado: Veracruz\n");
            break;
        case 31:
            printf("Estado: Yucatan\n");
            break;
        case 32:
            printf("Estado: Zacatecas\n");
            break;
    }
}

void imprimir_covid(_uint_8 imp){
    imp==positivo? printf("Covid: Positivo\n"):printf("Covid: Negativo\n");
    return;
}

void imprimir_fecha(Fecha imp){
    printf("Fecha: %02u/%02u/%u", imp.dia, imp.mes, imp.anio);
    return;
}

void imprimir_Caso(Caso imp){
    printf("No. seguro social: %s\n", imp.no_SS);
    imprimir_estado(imp.estado);
    imprimir_covid(imp.covid);
    imprimir_fecha(imp.fecha);
    return;
}

Caso registrar_caso() {
    Caso buffer_caso;
    strcpy(buffer_caso.no_SS, capturar_numSS());
    buffer_caso.estado = captura_estadoID();
    buffer_caso.fecha = capturar_fecha();
    buffer_caso.covid = capturar_covid();
    //Comprobador:
    printf("\nCaso agregado:\n");
    imprimir_Caso(buffer_caso);
    return buffer_caso;
}

void guardar_estado(void){

    FILE *fp_estado;

    Estado buffer;

    //Iniciamos los archivos
    fp_estado = fopen(F_ESTADOS, "ab");

    if (fp_estado == NULL)
    {
        perror("Ha ocurrido un error");
        system("pause");
    } 
    else
    {
        printf("\n***Capturar estado\n\n");
        //Capturamos el estado
        buffer = registrar_estado();
        //Guardamos la informacion:
        fwrite(&buffer, sizeof(Estado), 1, fp_estado);
        fclose(fp_estado);
    }

    return;

}

void guardar_persona(void){

    FILE *fp_persona;

    Persona buffer;

    //Iniciamos los archivos
    fp_persona = fopen(F_PERSONAS, "ab");

    if(fp_persona==NULL){
            perror("Ha ocurrido un error");
            system("pause");
    }
    else{
        printf("\n***Capturar persona\n\n");
        //Capturamos la persona
        buffer = registrar_persona();
        
        //Guardamos la informacion:
        fwrite(&buffer, sizeof(Persona), 1, fp_persona);

        fclose(fp_persona);
    }
    return;
}

void guardar_caso(void){

    FILE *fp_caso;

    Caso buffer;

    //Iniciamos los archivos
    fp_caso = fopen(F_CASOS, "ab");

    if (fp_caso == NULL)
    {
        perror("Ha ocurrido un error");
        system("pause");
    }
    else
    {
        printf("\n***Capturar caso\n\n");
        //Capturamos caso
        buffer = registrar_caso();

        //Guardamos la informacion:
        fwrite(&buffer, sizeof(Caso), 1, fp_caso);
    
        fclose(fp_caso);

    }
}

int buscar_estado(_uint_8 ID, int *registro) {
    FILE *fp_estados;
    int encontrado = 0;
    *registro = 0;
    Estado buffer;
    fp_estados = fopen(F_ESTADOS, "rb");
    if (fp_estados == NULL)
    {
        perror("Error grave");
        printf("No existen datos guardados\n");
        system("pause");
        return 0;
    }
    rewind(fp_estados);
    while (fread(&buffer, sizeof(Estado), 1, fp_estados))
    {
        if(feof(fp_estados))
            break;
        if (buffer.estado == ID && buffer.borrado == No_borrado)
        {
            encontrado = 1;
            fclose(fp_estados);
            return encontrado;
        }
        (*registro)++;
    }
    fclose(fp_estados);
    return encontrado;
}

int buscar_persona(const char *No_SS, int *registro)
{
    FILE *fp_persona;
    int encontrado = 0;
    *registro = 0;
    Persona buffer;
    fp_persona = fopen(F_PERSONAS, "rb");
    if (fp_persona == NULL)
    {
        perror("Error grave");
        printf("No existen datos guardados\n");
        system("pause");
        return 0;
    }
    rewind(fp_persona);
    while (fread(&buffer, sizeof(Persona), 1, fp_persona))
    {
        if(feof(fp_persona))
            break;
        if (!strcmp(No_SS,buffer.num_SS) && buffer.borrado == No_borrado)
        {
            encontrado = 1;
            fclose(fp_persona);
            return encontrado;
        }
        (*registro)++;
    }
    fclose(fp_persona);
    return encontrado;
}

int buscar_caso_PN(int *registro)
{
    FILE *fp_casos;
    Caso buffer;
    memset(registro, 0, 2*sizeof(int));
    fp_casos = fopen(F_CASOS, "rb");
    if (fp_casos == NULL)
    {
        perror("Error grave");
        printf("No existen datos guardados\n");
        system("pause");
        return 0;
    }
    rewind(fp_casos);
    while (fread(&buffer, sizeof(Caso), 1, fp_casos))
    {
        //Checamos si fread ya llego al EOF
        if (feof(fp_casos))
            break;
        if(buffer.covid==negativo){
            registro[0]++;
        }
        else if(buffer.covid==positivo){
            registro[1]++;
        }
    }
    fclose(fp_casos);
    return 1;
}

int buscar_casos_Estado(_uint_8 ID, int **registro)
{
    FILE *fp_casos;
    int encontrado = 0, pocision = 0;
    int *tp;
    Caso buffer;
    fp_casos = fopen(F_CASOS, "rb");
    if (fp_casos == NULL)
    {
        perror("Error grave");
        printf("No existen datos guardados\n");
        system("pause");
        return 0;
    }
    rewind(fp_casos);
    while (fread(&buffer, sizeof(Caso), 1, fp_casos))
    {
        //Checamos si fread ya llego al EOF
        if(feof(fp_casos)) 
            break;
        if (buffer.estado == ID)
        {
            encontrado++;
            tp = (int *)realloc(*registro, encontrado * sizeof(int));
            int errores = 0;
            while (tp == NULL)
            {     
                errores++;  
                tp = (int *)realloc(*registro, encontrado * sizeof(int));
                if(10 < errores){
                    printf("ERROR GRAVE: Cerrando programa\n");
                    fclose(fp_casos);
                    exit(EXIT_FAILURE);
                } 
            }
            *registro = tp;
            (*registro)[encontrado - 1] = pocision;
        }
        pocision++;
    }
    fclose(fp_casos);
    return encontrado;
}
