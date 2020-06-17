
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

#include "algoritmos.h"
#include "registros.h"


//FUNCIONES DE IMPRESION
void imprimir_domicilio(Domicilio imp){
    printf("Calle: %s\n", imp.calle);
    printf("Numero: %s\n", imp.numero);
    printf("Colonia: %s\n", imp.colonia);
    printf("Municipio: %s\n", imp.municipio);
    imprimir_estado(imp.estado);
    return;
}
void imprimir_numSS(const char *imp){
    printf("No. seguro social: %s\n", imp);
    return;
}
void imprimir_genero( _uint_8 imp){
    if(imp == Femenino){
        printf("Genero: Femenino\n");
    }
    else if(imp == Masculino){
        printf("Genero: Masculino\n");
    }
    else if(imp == Otro){
        printf("Genero: Otro\n");
    }
    return;
}
void imprimir_PERSONA(Persona imp){
    imprimir_nombre(imp.nombre);
    imprimir_domicilio(imp.domicilio);
    imprimir_numSS(imp.num_SS);
    imprimir_edad(imp.edad);
    imprimir_genero(imp.genero);
    return;
}
void imprimir_estado(_uint_8 imp){
    switch(imp){
        case 0:
            printf("Estado: Aguascalientes\n");
            break;
        case 1:
            printf("Estado: Baja California\n");
            break;
        case 2:
            printf("Estado: Baja California Sur\n");
            break;
        case 3:
            printf("Estado: Campeche\n");
            break;
        case 4:
            printf("Estado: Chiapas\n");
            break;
        case 5:
            printf("Estado: Chihuahua\n");
            break;
        case 6:
            printf("Estado: Ciudad de Mexico\n");
            break;
        case 7:
            printf("Estado: Coahuila\n");
            break;
        case 8:
            printf("Estado: Colima\n");
            break;
        case 9:
            printf("Estado: Durango\n");
            break;
        case 10:
            printf("Estado: Estado de Mexico\n");
            break;
        case 11:
            printf("Estado: Guanajuato\n");
            break;
        case 12:
            printf("Estado: Guerrero\n");
            break;
        case 13:
            printf("Estado: Hidalgo\n");
            break;
        case 14:
            printf("Estado: Jalisco\n");
            break;
        case 15:
            printf("Estado: Michoacan\n");
            break;
        case 16:
            printf("Estado: Morelos\n");
            break;
        case 17:
            printf("Estado: Nayarit\n");
            break;
        case 18:
            printf("Estado: Nuevo Leon\n");
            break;
        case 19:
            printf("Estado: Oaxaca\n");
            break;
        case 20:
            printf("Estado: Puebla\n");
            break;
        case 21:
            printf("Estado: Queretaro\n");
            break;
        case 22:
            printf("Estado: Quintana Roo\n");
            break;
        case 23:
            printf("Estado: San Luis Potosi\n");
            break;
        case 24:
            printf("Estado: Sinaloa\n");
            break;
        case 25:
            printf("Estado: Sonora\n");
            break;
        case 26:
            printf("Estado: Tabasco\n");
            break;
        case 27:
            printf("Estado: Tamaulipas\n");
            break;
        case 28:
            printf("Estado: Tlaxcala\n");
            break;
        case 29:
            printf("Estado: Veracruz\n");
            break;
        case 30:
            printf("Estado: Yucatan\n");
            break;
        case 31:
            printf("Estado: Zacatecas\n");
            break;
    }
    return;
}
void imprimir_ESTADO(Estado imp){
    printf("ID: %d\n", (int)imp.estado);
    printf("Estado: %s\n", imp.descripcion);
    printf("Poblacion: %d\n", imp.poblacion);
    return;
}
void imprimir_covid(_uint_8 imp){
    (imp==positivo)? printf("Covid: Positivo\n"):
                     printf("Covid: Negativo\n");
    return;
}
void imprimir_nombre(Nombre imp){
    printf("Nombre: %s %s %s\n", imp.apll_P, imp.apll_M, imp.nom);
    return;
}
void imprimir_edad(_uint_8 imp){
    printf("Edad: %d\n", imp);
    return;
}
void imprimir_fecha(Fecha imp){
    printf("Fecha: %02u/%02u/%u\n",
       imp.dia, imp.mes, imp.anio);
    return;
}
void imprimir_CASO(Caso imp){
    printf("No. seguro social: %s\n", imp.no_SS);
    imprimir_estado(imp.estado);
    imprimir_covid(imp.covid);
    imprimir_fecha(imp.fecha);
    return;
}
/////////////////////////


//FUNCIONES DE CAPTURA
char* capturar_string(const char *texto, size_t max_size){

    char *aux = (char *)malloc(51 * sizeof(char));

    int error = 0;
    while (aux == NULL){
        error++;
        aux = (char *)malloc(10 * sizeof(char));
        if (10 < error){
            printf("ERROR GRAVE: Cerrando programa\n");
            exit(EXIT_FAILURE);
        }
    }

    printf(texto);
    fflush(stdin);
    gets(aux);

    do{
        error = 0;

        if (strlen(aux) != max_size){
            error = 1;
        }

        for (size_t i = 0; i < strlen(aux) && !error; i++){
            if (aux[i] < '0' || '9' < aux[i]){
                error = 1;
            }
        }

        if (error){
            printf("Opcion no valida!\n");
            system("pause");
            printf(texto);
            fflush(stdin);
            gets(aux);
        }

    }while(error);

    return aux;
}
char* capturar_descripcion(_uint_8 ID){

    char *buffer = (char *)malloc(100 * sizeof(char));

    int error = 0;
    while (buffer == NULL){
        error++;
        buffer = (char *)malloc(100 * sizeof(char));
        if (10 < error){
            printf("ERROR GRAVE: Cerrando programa\n");
            exit(EXIT_FAILURE);
        }
    }

    switch (ID){
        case 0:
            strcpy(buffer, "Aguascalientes");
            break;
        case 1:
            strcpy(buffer, "Baja California");
            break;
        case 2:
            strcpy(buffer, "Baja California Sur");
            break;
        case 3:
            strcpy(buffer, "Campeche");
            break;
        case 4:
            strcpy(buffer, "Chiapas");
            break;
        case 5:
            strcpy(buffer, "Chihuahua");
            break;
        case 6:
            strcpy(buffer, "Ciudad de Mexico");
            break;
        case 7:
            strcpy(buffer, "Coahuila");
            break;
        case 8:
            strcpy(buffer, "Colima");
            break;
        case 9:
            strcpy(buffer, "Durango");
            break;
        case 10:
            strcpy(buffer, "Estado de Mexico");
            break;
        case 11:
            strcpy(buffer, "Guanajuato");
            break;
        case 12:
            strcpy(buffer, "Guerrero");
            break;
        case 13:
            strcpy(buffer, "Hidalgo");
            break;
        case 14:
            strcpy(buffer, "Jalisco");
            break;
        case 15:
            strcpy(buffer, "Michoacan");
            break;
        case 16:
            strcpy(buffer, "Morelos");
            break;
        case 17:
            strcpy(buffer, "Nayarit");
            break;
        case 18:
            strcpy(buffer, "Nuevo Leon");
            break;
        case 19:
            strcpy(buffer, "Oaxaca");
            break;
        case 20:
            strcpy(buffer, "Puebla");
            break;
        case 21:
            strcpy(buffer, "Queretaro");
            break;
        case 22:
            strcpy(buffer, "Quintana Roo");
            break;
        case 23:
            strcpy(buffer, "San Luis Potosi");
            break;
        case 24:
            strcpy(buffer, "Sinaloa");
            break;
        case 25:
            strcpy(buffer, "Sonora");
            break;
        case 26:
            strcpy(buffer, "Tabasco");
            break;
        case 27:
            strcpy(buffer, "Tamaulipas");
            break;
        case 28:
            strcpy(buffer, "Tlaxcala");
            break;
        case 29:
            strcpy(buffer, "Veracruz");
            break;
        case 30:
            strcpy(buffer, "Yucatan");
            break;
        case 31:
            strcpy(buffer, "Zacatecas");
            break;
    }

    return buffer;
}
char* capturar_numSS(void){
    char *buffer;
    printf("*Numero de seguro social\n");
    buffer = capturar_string("No. seguro social (11 digitos): ", 11);
    return buffer;
}
char* generar_numSS(void){

    char *buffer = (char*)malloc(12*sizeof(char));

    int error = 0;
    while (buffer == NULL)
    {
        error++;
        buffer = (char *)malloc(10 * sizeof(char));
        if (10 < error)
        {
            printf("ERROR GRAVE: Cerrando programa\n");
            exit(EXIT_FAILURE);
        }
    }

    char *aux = NULL;
    printf("\n*Generar no. seguro social\n");

    //Primeros dos digitos
    aux = capturar_string("ID de la clinica del IMSS del paciente (2 digitos): ", 2);
    strcpy(buffer,aux);
    free(aux);

    //tercer y cuarto digito
    aux = capturar_string("Ultimos dos digitos del anio en que se dio de alta\n(2 digitos): ", 2);
    strcat(buffer,aux);
    free(aux);

    //quinto y sexto digito
    aux = capturar_string("Ultimos dos digitos del anio de nacimiento del paciente\n(2 digitos): ", 2);
    strcat(buffer, aux);
    free(aux);

    //Ultimnos digitos
    char tmp[12];
    int paciente;
    do{
        strcpy(tmp, buffer);
        error = 0;

        aux = capturar_string("Digite 5 digitos: ", 5);
        strcat(tmp, aux);
        free(aux);

        if (buscar_persona(tmp,&paciente)){
            error = 1;
            printf("\nEl paciente no.%d ya tiene este NSS\n", paciente+1);
            printf("Cambie los ultimos 5 digitos\n\n");
        }

    }while(error);

    strcpy(buffer, tmp);
    return buffer;
}

_uint_8 capturar_estadoID(void){

    int buffer;

    printf("\n*Estado:\n");
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
    printf(" 32) Zacatecas\n\n");
    printf("Teclee la opcion requerida: ");
    scanf("%d", &buffer);

    while (buffer < 1 || 32 < buffer ){
        printf("Opcion no valida!\n");
        system("pause");
        printf("Tecleea la opcion requerida: ");
        scanf("%d", &buffer);
    }

    buffer--;
    return (_uint_8)(buffer);
}
_uint_8 capturar_genero(void){

    int buffer;

    printf("\n*Genero\n");
    printf(" 1) Femenino\n");
    printf(" 2) Masculino\n");
    printf(" 3) Otro\n\n");
    printf("Teclea la opcion requerida: ");
    scanf("%d", &buffer);

    while (buffer < 1 || 3 < buffer){
        printf("Opcion no valida!\n");
        system("pause");
        printf("Tecleea la opcion requerida: ");
        scanf("%d", &buffer);
    }

    buffer--;
    return (_uint_8)buffer;
}
_uint_8 capturar_covid(void){

    int buffer;

    printf("\n*Covid-19\n");
    printf(" 1) Negativo\n");
    printf(" 2) Positivo\n");
    printf("Teclea la opcion requerida: ");
    scanf("%d", &buffer);

    while (buffer != 1 && buffer != 2){
        printf("Opcion no valida!\n");
        system("pause");
        printf("Tecleea la opcion requerida: ");
        scanf("%d", &buffer);
    }

    buffer--;
    return (_uint_8)buffer;
}
_uint_8 capturar_edad(void){

    int buffer;

    printf("\n*Edad\n");
    printf("Edad: ");
    scanf("%d", &buffer);

    while (buffer < 0 || 255 < buffer){
        printf("Opcion no valida!\n");
        system("pause");
        printf("Edad: ");
        scanf("%d", &buffer);
    }

    return (_uint_8)(buffer);
}

int       capturar_poblacion(void){

    int buffer;

    printf("\n*Poblacion\n");
    printf("Poblacion: ");
    scanf("%d", &buffer);

    while (buffer < 0){
        printf("Opcion no valida!\n");
        system("pause");
        printf("Poblacion: ");
        scanf("%d", &buffer);
    }

    return (buffer);
}
Domicilio capturar_domicilio(void){

    Domicilio buffer;

    printf("\n*Domicilio\n");
    printf("Calle: ");
    fflush(stdin);
    gets(buffer.calle);
    printf("Numero: ");
    fflush(stdin);
    gets(buffer.numero);
    printf("Colonia: ");
    fflush(stdin);
    gets(buffer.colonia);
    printf("Municipio: ");
    fflush(stdin);
    gets(buffer.municipio);
    buffer.estado = capturar_estadoID();

    return buffer;
}
Persona   capturar_persona(void){

    Persona buffer_persona;

    char *aux = generar_numSS();
    strcpy(buffer_persona.num_SS, aux);
    free(aux);

    buffer_persona.borrado   = No_borrado;
    buffer_persona.nombre    = capturar_nombre();
    buffer_persona.domicilio = capturar_domicilio();
    buffer_persona.edad      = capturar_edad();
    buffer_persona.genero    = capturar_genero();

    //Comprobador:
    printf("\n*Persona agregada:\n");
    imprimir_PERSONA(buffer_persona);

    return buffer_persona;
}
Nombre    capturar_nombre(void){

    Nombre buffer;

    printf("\n*Nombre completo\n");
    printf("Apellido paterno: ");
    fflush(stdin);
    gets(buffer.apll_P);
    printf("Apellido materno: ");
    fflush(stdin);
    gets(buffer.apll_M);
    printf("Nombre: ");
    fflush(stdin);
    gets(buffer.nom);

    return buffer;
}
Estado    capturar_estado(void){

    Estado buffer_estado;

    buffer_estado.borrado   = No_borrado;
    buffer_estado.estado    = capturar_estadoID();

    int aux;
    if(buscar_estado(buffer_estado.estado, &aux)){
        buffer_estado.estado = 127;
        return buffer_estado;
    }

    buffer_estado.poblacion = capturar_poblacion();

    char* aux_2 = capturar_descripcion(buffer_estado.estado);
    strcpy(buffer_estado.descripcion,aux_2);
    free(aux_2);

    //Comprobador:
    printf("\n*Estado agregado:\n");
    imprimir_ESTADO(buffer_estado);

    return buffer_estado;
}
Fecha     capturar_fecha(void){

    int buffer_aux;
    Fecha buffer;

    printf("\n*Fecha\n");

    printf("Dia: ");
    scanf("%d",&buffer_aux);
    while(buffer_aux < 1 || 31 <buffer_aux){
        printf("Opcion no valida!\n");
        system("pause");
        printf("Dia: "); scanf("%d",&buffer_aux);
    }
    buffer.dia = (_uint)buffer_aux;

    printf("Mes: ");
    scanf("%d",&buffer_aux);
    while(buffer_aux < 1 || 12 <buffer_aux){
        printf("Opcion no valida!\n");
        system("pause");
        printf("Mes: "); scanf("%d",&buffer_aux);
    }
    buffer.mes = (_uint)buffer_aux;

    printf("A%co: ",164);
    scanf("%d",&buffer_aux);
    while(buffer_aux < 0 || 8388607 < buffer_aux){
        printf("Opcion no valida!\n");
        system("pause");
        printf("A%co: ",164); scanf("%d",&buffer_aux);
    }
    buffer.anio = (_uint)buffer_aux;

    return buffer;
}
Caso      capturar_caso(void){

    Caso buffer_caso;

    char *aux = capturar_numSS();
    int aux_2;

    if(!buscar_persona(aux, &aux_2)){
        buffer_caso.estado = 127;
        free(aux);
        return buffer_caso;
    }

    strcpy(buffer_caso.no_SS, aux);
    free(aux);

    buffer_caso.estado = capturar_estadoID();
    buffer_caso.fecha  = capturar_fecha();
    buffer_caso.covid  = capturar_covid();

    //Comprobador:
    printf("\nCaso agregado:\n");
    imprimir_CASO(buffer_caso);

    return buffer_caso;
}
////////////////////////

//FUNCIONES DE CREACION
void crear_persona(void){

    FILE *fp_persona = fopen(F_PERSONAS, "ab");

    if(fp_persona==NULL){

        perror("Ha ocurrido un error");

    }
    else{

        printf("\n***Capturar persona\n");
        //Capturamos la persona
        Persona buffer = capturar_persona();
        //Guardamos la informacion:
        fwrite(&buffer, sizeof(Persona), 1, fp_persona);
        fclose(fp_persona);

    }

    return;
}
void crear_estado(void){

    FILE *fp_estado = fopen(F_ESTADOS, "ab");

    if (fp_estado == NULL){

        perror("Ha ocurrido un error");

    }
    else{

        printf("\n***Capturar estado\n");
        //Capturamos el estado
        Estado buffer = capturar_estado();

        if(buffer.estado == 127){
            printf("Estado ya registrado\n");
            fclose(fp_estado);
            return;
        }

        //Guardamos la informacion:
        fwrite(&buffer, sizeof(Estado), 1, fp_estado);
        fclose(fp_estado);

    }

    return;
}
void crear_caso(void){

    FILE *fp_caso = fopen(F_CASOS, "ab");

    if (fp_caso == NULL){

        perror("Ha ocurrido un error");

    }
    else{

        printf("\n***Capturar caso\n\n");
        //Capturamos caso
        Caso buffer = capturar_caso();
        //Revisamos que la persona este registrada
        if(buffer.estado == 127){
            printf("\nPersona no registrada\n\n");
            fclose(fp_caso);
            return;
        }

        //Guardamos la informacion:
        fwrite(&buffer, sizeof(Caso), 1, fp_caso);
        fclose(fp_caso);

    }

    return;
}
///////////////////////

//FUNCIONES DE BUSQUEDA
int buscar_persona(const char *No_SS, int *registro){

    FILE *fp_persona = fopen(F_PERSONAS, "rb");

    if (fp_persona == NULL){
        perror("Error grave");
        printf("No existen datos guardados\n");
        return 0;
    }

    rewind(fp_persona);

    int encontrado = 0;
    Persona buffer;
    *registro = 0;

    while (fread(&buffer, sizeof(Persona), 1, fp_persona)){

        if(feof(fp_persona))
            break;

        if (!strcmp(No_SS,buffer.num_SS) && buffer.borrado == No_borrado){

            encontrado = 1;
            fclose(fp_persona);
            return encontrado;

        }

        (*registro)++;
    }

    fclose(fp_persona);
    return encontrado;
}
int buscar_casos_BE(_uint *aux, size_t elementos){
    //Contamos los casos de Estados para imprimir en los graficos de Barras
    Fecha *fechas = (Fecha*)malloc(elementos*sizeof(Fecha));

    int errores = 0;
    while (fechas == NULL){
        fechas = (Fecha*)malloc(elementos*sizeof(Fecha));
        errores++;
        if(10 < errores){
            printf("ERROR GRAVE: Cerrando programa\n");
            exit(EXIT_FAILURE);
        }
    }

    FILE *fp_casos = fopen(F_CASOS, "rb");
    //Cargamos las fechas encontradas
    Caso buffer;

    for(size_t i = 0; i < elementos; i++){
        fseek(fp_casos, aux[i]*sizeof(Caso), SEEK_SET);
        fread(&buffer, sizeof(Caso), 1, fp_casos);
        fechas[i] = buffer.fecha;
    }

    //Ordenamos las fechas
    sort_fechas(fechas, elementos);

    //Marcamos todo aux[] con unos
    for(size_t i = 0; i < elementos; i++){
        aux[i] = 1;
    }

    size_t aux_i = 0, contador = 1;
    Fecha aux_1 = fechas[0], aux_2;

    for(size_t i = 1; i < elementos; i++){

        aux_2 = fechas[i];

        if(comparar_dia(aux_1, aux_2) == -1){
            aux[aux_i]++;
        }
        else{
            contador++;
            aux_i = contador - 1;
            aux_1 = aux_2;
        }

    }

    free(fechas);
    return contador;
}
int buscar_casos_PE(_uint_8 ID, _uint **registro){
    //Postivos por estado
    FILE *fp_casos = fopen(F_CASOS, "rb");

    if (fp_casos == NULL){
        perror("Error grave");
        printf("No existen datos guardados\n");
        return -1;
    }

    rewind(fp_casos);

    int encontrado = 0, pocision = 0;
    Caso buffer;

    while (fread(&buffer, sizeof(Caso), 1, fp_casos)){
        //Checamos si fread ya llego al EOF
        if(feof(fp_casos))
            break;

        if (buffer.estado == ID && buffer.covid == positivo){

            encontrado++;
            _uint *tp = (_uint *)realloc(*registro, encontrado * sizeof(_uint));
            int errores = 0;

            while (tp == NULL){

                errores++;
                tp = (_uint *)realloc(*registro, encontrado * sizeof(_uint));

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
int buscar_estado(_uint_8 ID, int *registro){

    FILE *fp_estados = fopen(F_ESTADOS, "rb");

    if (fp_estados == NULL){
        perror("Error grave");
        printf("No existen datos guardados\n");
        return 0;
    }

    rewind(fp_estados);

    int encontrado = 0;
    Estado buffer;
    *registro = 0;

    while (fread(&buffer, sizeof(Estado), 1, fp_estados)){

        if(feof(fp_estados))
            break;

        if (buffer.estado == ID && buffer.borrado == No_borrado){

            encontrado = 1;
            fclose(fp_estados);
            return encontrado;

        }

        (*registro)++;

    }

    fclose(fp_estados);
    return encontrado;
}
int buscar_casos_PG(_uint **registro){
    //Postivos general
    FILE *fp_casos = fopen(F_CASOS, "rb");

    if (fp_casos == NULL){
        perror("Error grave");
        printf("No existen datos guardados\n");
        return -1;
    }

    rewind(fp_casos);

    int encontrado = 0, pocision = 0;
    Caso buffer;

    while (fread(&buffer, sizeof(Caso), 1, fp_casos)){
        //Checamos si fread ya llego al EOF
        if(feof(fp_casos))
            break;

        if (buffer.covid == positivo){

            encontrado++;
            _uint *tp = (_uint *)realloc(*registro, encontrado * sizeof(_uint));
            int errores = 0;

            while (tp == NULL){

                errores++;
                tp = (_uint *)realloc(*registro, encontrado * sizeof(_uint));

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
int buscar_caso_PN(int *registro){

    FILE *fp_casos = fopen(F_CASOS, "rb");


    if (fp_casos == NULL){
        perror("Error grave");
        printf("No existen datos guardados\n");
        system("pause");
        return 0;
    }

    rewind(fp_casos);

    memset(registro, 0, 2*sizeof(int));
    Caso buffer;

    while (fread(&buffer, sizeof(Caso), 1, fp_casos)){
        //Checamos si fread ya llego al EOF
        if (feof(fp_casos))
            break;

        (buffer.covid==negativo)? registro[0]++:
                                  registro[1]++;

    }

    fclose(fp_casos);
    return 1;
}
///////////////////////

//FUNCIONES DE BORRADO
void borrar_persona(void){

    printf("\n***Borrar persona\n");

    char *ID = capturar_numSS();
    int registro;

    if(buscar_persona(ID, &registro)){

        FILE *fp = fopen(F_PERSONAS,"r+b");

        if(fp == NULL){
            printf("No fue posible abrir el archivo\n");
            return;
        }

        Persona buffer;

        fseek(fp, registro*sizeof(Persona), SEEK_SET);
        fread(&buffer, sizeof(Persona), 1, fp);

        buffer.borrado = Borrado;

        fseek(fp, registro*sizeof(Persona), SEEK_SET);
        fwrite(&buffer, sizeof(Persona), 1, fp);
        fclose(fp);

        printf("Persona borrada con exito\n");

    }
    else{

        printf("Persona no encontrad\n");

    }

    free(ID);
    return;
}
void borrar_estado(void){

    printf("\n***Borrar estado\n");

    _uint_8 ID = capturar_estadoID();
    int registro;

    if(buscar_estado(ID, &registro)){

        FILE *fp = fopen(F_ESTADOS,"r+b");

        if(fp == NULL){
            printf("No fue posible abrir el archivo\n");
            return;
        }

        Estado buffer;

        fseek(fp, registro*sizeof(Estado), SEEK_SET);
        fread(&buffer, sizeof(Estado), 1, fp);

        buffer.borrado = Borrado;

        fseek(fp, registro*sizeof(Estado), SEEK_SET);
        fwrite(&buffer, sizeof(Estado), 1, fp);
        fclose(fp);

        printf("Estado borrado con exito\n");

    }
    else{

        printf("Estado no encontrado\n");

    }

    return;
}

///////////////////////

//FUNCIONES DE LISTADO
void listar_personas(void){

    FILE *fp_personas = fopen(F_PERSONAS, "rb");

    if (fp_personas == NULL){
        perror("Error grave");
        printf("No existen datos guardados\n");
        return;
    }

    rewind(fp_personas);

    Persona buffer;
    printf("\n***Personas registradas\n\n");
    printf("---------------------------------\n");
    while (fread(&buffer, sizeof(Persona), 1, fp_personas)){

        if(feof(fp_personas))
            break;

        if (buffer.borrado == No_borrado){
            printf("\n");
            imprimir_PERSONA(buffer);
            printf("\n---------------------------------\n");

        }

    }
    fclose(fp_personas);
    return;
}
void listar_estados(void){

    FILE *fp_estados = fopen(F_ESTADOS, "rb");

    if (fp_estados == NULL){
        perror("Error grave");
        printf("No existen datos guardados\n");
        return;
    }

    rewind(fp_estados);

    Estado buffer;
    printf("\n***Estados registrados\n\n");
    printf("---------------------------------\n");
    while (fread(&buffer, sizeof(Estado), 1, fp_estados)){

        if(feof(fp_estados))
            break;

        if (buffer.borrado == No_borrado){
            printf("\n");
            imprimir_ESTADO(buffer);
            printf("\n---------------------------------\n");

        }

    }

    fclose(fp_estados);
    return;
}
void listar_casos(void){

    FILE *fp_casos = fopen(F_CASOS, "rb");

    if (fp_casos == NULL){
        perror("Error grave");
        printf("No existen datos guardados\n");
        return;
    }

    rewind(fp_casos);

    Caso buffer;
    printf("\n***Casos registrados\n\n");
    printf("---------------------------------\n");
    while (fread(&buffer, sizeof(Caso), 1, fp_casos)){

        if(feof(fp_casos))
            break;

        printf("\n");
        imprimir_CASO(buffer);
        printf("\n---------------------------------\n");


    }

    fclose(fp_casos);
    return;
}


/////////////////////


