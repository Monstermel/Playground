#include <stdio.h>
#include <stdlib.h>
#include <winbgim.h>
#include <graphics.h>
#include <math.h>

#include "barras.h"
#include "algoritmos.h"


unsigned int altura(unsigned int n, unsigned int max, unsigned int y){
    return (n*y)/max;
}

void impresion_barras(int prtc_2, int max, int y_long, size_t dias, const unsigned int *casos){

    unsigned int *cntd;
    cntd = (unsigned int *)calloc(dias, sizeof(unsigned int));

    //Error handling
    if(cntd == NULL){
        printf("\nERROR**Solucionando\n");
        size_t errores = 0;
        do{
            errores++;
            cntd = (unsigned int *)calloc(dias, sizeof(unsigned int));
            if(10 <= errores){
                printf("ERROR**Cerrando programa\n");
                exit(1);
            }
        }while(cntd == NULL);
    }

    //Variables para las barras
    int left = 100;
    int top;
    int right;
    int bottom = getmaxy()-100;
    int pts[10];

    //Establecemos el estilo de las barras
    setcolor(COLOR(0, 58, 255));
    setfillstyle(1, COLOR(0, 58, 255));

    //Este for controla cuantos aumentos hay
    for(size_t i = 0; i < max; i++){

        for(size_t j = 0; j < dias; j++){

            cntd[j]++;

            if(cntd[j]>casos[j]){
                left += 6 * prtc_2;
                continue;
            }

            left += prtc_2;
            top = bottom - altura(cntd[j], max, y_long);
            right = left + 4 * prtc_2;

            //Primer punto
            pts[0] = left;
            pts[1] = top;

            //Segundo punto
            pts[2] = right;
            pts[3] = top;

            //Tercer punto
            pts[4] = right;
            pts[5] = bottom;

            //Cuarto punto
            pts[6] = left;
            pts[7] = bottom;

            //Punto de cierre
            pts[8] = left;
            pts[9] = top;


            fillpoly(5, pts);

            //Sumamos 5 prtcs_2's por que partimos
            //el sector de cada barra en 1/6,
            //ya habiamos sumado 1/6 asi que nos
            //faltan 5/6 para completar el sector
            left+= 5 * prtc_2;

        }
        left = 100;
        delay(10);
    }
}




void graficos_barras(const char *texto, size_t dias, const unsigned int *casos){

    //Dias es la cantidad de elemtos del arreglo de casos
    //Texto es el titulo de la grafica

    initwindow(1280,720,"Graficos de barras");
    setbkcolor(COLOR(250,250,250));
    cleardevice();


    //Marco coords (100, 100, getmaxx()-100, getmaxy()-100).


    //Calc la dimension del marco
    const short x_long = getmaxx() - 200;
    const short y_long = getmaxy() - 200;

    //Calc cuanto vale cada particion
    const short prtc_1 = (short)roundf(x_long/(float)dias);//Particion del marco
    const short prtc_2 = (short)roundf(prtc_1/6.0);//Particion del sector de cada barra

    //Tenemos que encontrar el dia mas alto
    //y despues redondearlo i.e: 135=>150
    unsigned int max = 0;
    for(size_t i = 0; i<dias; i++){
        if(casos[i] > max) max = casos[i];
    }
    max = integer_round(max);

    impresion_barras(prtc_2, max, y_long, dias, casos);

    //Dibujamos la linea de la base
    setcolor(0);
    line(100,getmaxy()-100,getmaxx()-100, getmaxy()-100);
    line(100,100,100,getmaxy()-100);


    return;

}
