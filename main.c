
#include <stdio.h>
#include <winbgim.h>
#include <graphics.h>
#include <stdarg.h>

#include "pastel.h"
#include "barras.h"
#include "cuadricula.h"



//Problema encontrado: todas las funciones que usen una ventana grafica deben de poder crearla si no esta no existe
//ademas si ya existe una trabajar en ella, investigar como hacer eso

int main(void){

    //Programa driver
    long long total;
    long long positivos;
    long long negativos;


    printf("Casos totales: ");
    scanf("%lld",&total);
    printf("Casos positivos: ");
    scanf("%lld",&positivos);
    negativos = total - positivos;
    printf("Casos negativos: %lld\n", negativos);
    graficos_pastel(total, positivos, negativos);
    mostrar_cuadricula(8);

    system("pause");

    return 0;
}
