
#include <stdio.h>
#include <winbgim.h>
#include <graphics.h>
#include <stdarg.h>

#include "pastel.h"
#include "barras.h"
#include "cuadricula.h"



int main(void){

    //DRIVER DE BARRAS
    unsigned int casos[10] = {967, 568, 389, 589, 523, 634, 767, 879, 243, 938};

    graficos_barras("Hola mundo", 10, casos);


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
