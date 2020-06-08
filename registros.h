#ifndef REGISTROS_H_INCLUDED
#define REGISTROS_H_INCLUDED

//Hay compiladores que ya tienen esta definicion
//pero he notado que varia como lo definen asi que
//mejor lo defino yo para que no haya problemas
typedef unsigned char _uint_8;

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
    Querétaro,
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
    _uint_8 estado;
    char descripcion[100];
    int poblacion;
    _uint_8 borrado;
} Estado;
////////////////////////

//DEFINICIONES PERSONA
enum Genero {
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
    char num_SS[12];//Numero de seguro social
    Nombre nombre;
    Domicilio domicilio;
    _uint_8 edad;
    _uint_8 genero;
    _uint_8 borrado;
} Persona;
///////////////////////

//ESTRUCTURAS CASOS
enum Covid {
    negativo,
    positivo
};

typedef struct Fecha {
	unsigned int dia:5;
	unsigned int mes:4;
	unsigned int anio:23;
} Fecha; 

typedef struct Caso{
    _uint_8 estado;
    char no_SS[12];
    Fecha fecha;
    _uint_8 confirmado;
} Caso;
//////////////////////







#endif // REGISTROS_H_INCLUDED
