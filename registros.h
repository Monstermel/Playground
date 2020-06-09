#ifndef REGISTROS_H_INCLUDED
#define REGISTROS_H_INCLUDED

//Hay compiladores que ya tienen esta definicion
//pero he notado que varia como lo definen asi que
//mejor lo defino yo para que no haya problemas
typedef unsigned char _uint_8;
typedef unsigned int _uint;
//Revisar que el compilador que uso en codeblocks no tenga problemas con estas declaraciones

enum Disponibilidad {
    Borrado,
    No_borrado
};

//DEFINICIONES ESTADO
enum Estados {
    Aguascalientes,
    Baja_california,
    Baja_california_sur,
    Campeche,
    Chiapas,
    Chihuahua,
    Ciudad_de_mexico,
    Coahuila,
    Colima,
    Durango,
    Estado_de_mexico,
    Guanajuato,
    Guerrero,
    Hidalgo,
    Jalisco,
    Michoacan,
    Morelos,
    Nayarit,
    Nuevo_leon,
    Oaxaca,
    Puebla,
    Queretaro,
    Quintana_roo,
    San_luis_potosi,
    Sinaloa,
    Sonora,
    Tabasco,
    Tamaulipas,
    Tlaxcala,
    Veracruz,
    Yucatan,
    Zacatecas
};

typedef struct Estado {
    _uint_8 borrado:1;
    _uint_8 estado:7;
    char descripcion[100];
    int poblacion;
} Estado;
////////////////////////

//DEFINICIONES PERSONA
enum Generos {
    Femenino,
    Masculino,
    Otro
};

typedef struct Nombre {
    char apll_P[20];
    char apll_M[20];
    char nom[20];
} Nombre;

typedef struct Domicilio {
    char calle[50];
    char numero[20];
    char colonia[50];
    char municipio[50];
    char estado[50];//Revisar
} Domicilio;

typedef struct Persona {
    //Numero de seguro social
    char num_SS[12];
    Nombre nombre;
    Domicilio domicilio;
    _uint_8 edad;
    _uint_8 genero:7;
    _uint_8 borrado:1;
} Persona;
///////////////////////

//DEFINICIONES CASOS
enum Covid_19 {
    negativo,
    positivo
};

typedef struct Fecha {
    _uint dia : 5;
    _uint mes : 4;
    _uint anio : 23;
} Fecha; 

typedef struct Caso{
    char no_SS[12];
    _uint_8 estado:7;
    _uint_8 covid:1;
    Fecha fecha;
} Caso;
//////////////////////



//FUNCIONES DE IMPRESION
void imprimir_Caso(Caso imp);
void imprimir_fecha(Fecha imp);
void imprimir_covid(_uint_8 imp);
void imprimir_estado(_uint_8 imp);
void imprimir_Genero( _uint_8 imp);
void imprimir_Domicilio(Domicilio imp);
void imprimir_Nombre(Nombre imp);
////////////////////////


//FUNCIONES DE CAPTURA
_uint_8 capturar_covid(void);
Fecha capturar_fecha(void);
char* capturar_numSS(void);
_uint_8 captura_genero(void);
Domicilio captura_domicilio(void);
Nombre captura_nombre(void);
_uint_8 captura_estadoID(void);
////////////////////////

//FUNCIONES DE REGISTRO
Caso registrar_caso(void);
Persona registrar_persona(void);
Estado registrar_estado(void);
//////////////////////

//FUNCIONES DE CREACION
void nuevo_caso(void);
void nueva_persona(void);
void nuevo_estado(void);
///////////////////

//FUNCIONES DE BUSQUEDA
int buscar_casos_Estado(_uint_8 ID, int **registro);
int buscar_caso_PN(int *registro);//Positivos y negativos
int buscar_persona(const char *No_SS, int *registro);
int buscar_estado(_uint_8 ID, int *registro);
///////////////////






#endif // REGISTROS_H_INCLUDED
