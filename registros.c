#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include "registros.h"

_uint_8 captura_estadoID(void){
    int buffer;
    printf("*Estado: ");
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

Estado registrar_estado(void){

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

char* capturador_de_strings(const char *texto, size_t max_size){

    char *aux = (char *)malloc(10 * sizeof(char));
    int error = 0;
    while (aux == NULL)
    {
        error++;
        aux = (char *)malloc(10 * sizeof(char));
        if (10 < error)
        {
            printf("ERROR GRAVE: Cerrando programa\n");
            exit(EXIT_FAILURE);
        }
    }
    printf(texto);
    fflush(stdin);
    gets(aux);
    do
    {
        error = 0;
        if (strlen(aux) != max_size)
        {
            error = 1;
        }
        for (size_t i = 0; i < strlen(aux) && !error; i++)
        {
            if (aux[i] < '0' || '9' < aux[i])
            {
                error = 1;
            }
        }
        if (error)
        {
            printf("Opcion no valida!\n");
            system("pause");
            printf(texto);
            fflush(stdin);
            gets(aux);
        }
    } while (error);
    return aux;
}

char* generar_numSS(void) {
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
    char *aux;
    printf("*Generar no. seguro social\n");

    //Primeros dos digitos
    aux = capturador_de_strings("Id de la clinica del IMSS del paciente (2 digitos): ", 2);
    strcpy(buffer,aux);
    free(aux);

    //tercer y cuarto digito
    aux = capturador_de_strings("Ultimos dos digitos del año en que se dio de alta\n(2 digitos): ", 2);
    srcat(buffer,aux);
    free(aux);

    //quinto y sexto digito
    aux = capturador_de_strings("Ultimos dos digitos del año de nacimiento del paciente\n(2 digitos): ", 2);
    srcat(buffer, aux);
    free(aux);

    //Ultimnos digitos
    char tmp[12];
    int paciente;
    do{
        strcpy(tmp, buffer);
        error = 0;
        aux = capturador_de_strings("Digite 5 digitos: ", 5);
        srcat(tmp, aux);
        free(aux);

        if (buscar_persona(tmp,&paciente)){
            error = 1;
            printf("El paciente no.%d ya tiene este NSS\n", paciente+1);
            printf("Cambie los ultimos 5 digitos\n");
        }

    }while(error);
    srcpy(buffer, tmp);
    return buffer;
}

Nombre captura_nombre(void){
    Nombre buffer;
    printf("*Nombre completo\n");
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

Domicilio captura_domicilio(void){
    Domicilio buffer;
    printf("*Domicilio\n");
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
    buffer.estado = captura_estadoID();
    return buffer;
}

_uint_8 capturar_edad(void){
    int buffer;
    printf("*Edad\n");
    printf("Edad: ");
    scanf("%d", &buffer);
    while (buffer < 0 || 255 < buffer)
    {
        printf("Opcion no valida!\n");
        system("pause");
        printf("Tecleea la opcion requerida: ");
        scanf("%d", &buffer);
    }
    return (_uint_8)(buffer);
}

_uint_8 captura_genero(void){
    int buffer;
    printf("*Genero\n");
    printf(" 1) Femenino\n");
    printf(" 2) Masculino\n");
    printf(" 3) Otro\n");
    printf("Teclea la opcion requerida: ");
    scanf("%d", &buffer);
 
    while (buffer < 1 || 3 < buffer){
        printf("Opcion no valida!\n");
        system("pause");
        printf("Tecleea la opcion requerida: ");
        scanf("%d", &buffer);
    }
    return (_uint_8)(buffer--);
}

void imprimir_nombre(Nombre imp){
    printf("Nombre: %s %s %s\n", imp.apll_P, imp.apll_M, imp.nom);
    return;
}

void imprimir_domicilio(Domicilio imp){
    printf("Calle: %s\n", imp.calle);
    printf("Numero: %s\n", imp.numero);
    printf("Colonia: %s\n", imp.colonia);
    printf("Municipio: %s\n", imp.municipio);
    imprimir_estado(imp.estado);
}

void imprimir_numSS(const char *imp){
    printf("No. seguro social: %s\n", imp);
    return;
}
void imprimir_edad(_uint_8 imp){
    printf("Edad: %d\n", imp);
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

Persona registrar_persona(void){
    Persona buffer_persona;
    buffer_persona.borrado = No_borrado;
    char *aux = generar_numSS();
    strcpy(buffer_persona.num_SS, aux);
    free(aux);
    buffer_persona.nombre = captura_nombre();
    buffer_persona.domicilio = captura_domicilio();
    buffer_persona.edad = capturar_edad();
    buffer_persona.genero = captura_genero();

    //Comprobador:
    printf("\nPersona agregada:\n");
    imprimir_PERSONA(buffer_persona);
    ////
    return buffer_persona;
}

char* capturar_numSS(void){
    char *buffer;
    printf("*Numero de seguro social\n");
    buffer = capturador_de_strings("No. seguro social (11 digitos): ", 11);
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
    while(buffer_aux < 0 || 8388607 < buffer_aux){
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

void imprimir_CASO(Caso imp){
    printf("No. seguro social: %s\n", imp.no_SS);
    imprimir_estado(imp.estado);
    imprimir_covid(imp.covid);
    imprimir_fecha(imp.fecha);
    return;
}

Caso registrar_caso(void){
    Caso buffer_caso;
    char *aux;
    aux = capturar_numSS();
    strcpy(buffer_caso.no_SS, aux);
    free(aux);
    buffer_caso.estado = captura_estadoID();
    buffer_caso.fecha = capturar_fecha();
    buffer_caso.covid = capturar_covid();
    //Comprobador:
    printf("\nCaso agregado:\n");
    imprimir_Caso(buffer_caso);
    return buffer_caso;
}

void nuevo_estado(void){

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

void nueva_persona(void){

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

void nuevo_caso(void){

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

int buscar_estado(_uint_8 ID, int *registro){
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

int buscar_persona(const char *No_SS, int *registro){
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

int buscar_caso_PN(int *registro){
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

int buscar_casos_Estado(_uint_8 ID, int **registro){
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
