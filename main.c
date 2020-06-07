
#include <stdio.h>
#include <winbgim.h>
#include <graphics.h>
#include <stdarg.h>

#include "pastel.h"
#include "barras.h"
#include "cuadricula.h"



int main(void){

    //DRIVER DE BARRAS         0    1    2    3    4    5    6    7    8    9
    //                         1    2    3    4    5    6    7    8    9    10
    unsigned int casos[10] = {134, 234, 387, 99, 500, 951, 500, 500, 500, 100};

    graficos_barras("Hola mundo", 1, 10, 10, casos);


    /*
    // DRIVER DE PASTEL

    int total;
    int positivos;
    int negativos;

    printf("Casos totales: ");
    scanf("%d",&total);
    printf("Casos positivos: ");
    scanf("%d",&positivos);
    negativos = total - positivos;
    printf("Casos negativos: %d\n", negativos);
    graficos_pastel(total, positivos, negativos);
    */


    system("pause");

    return 0;
}
