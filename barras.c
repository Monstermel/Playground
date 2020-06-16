#include <stdio.h>
#include <stdlib.h>
#include <winbgim.h>
#include <graphics.h>
#include <math.h>

#include "barras.h"
#include "algoritmos.h"


void impresion_barras(int prtc_2, int max, int y_long, size_t inicio, size_t final, size_t tamanio, const unsigned int *casos){
    //Cntd es como un contador, cada elemento i aumenta
    //mientra sea menor al elemento i en casos
    unsigned int *cntd;

    //Declaramos memoria con todos sus bits establecidos en 0
    cntd = (unsigned int *)calloc(tamanio, sizeof(unsigned int));

    //Error handling
    if(cntd == NULL){
        printf("\n\tERROR**Solucionando\n");
        size_t errores = 0;
        do{
            errores++;
            cntd = (unsigned int *)calloc((final-inicio+1), sizeof(unsigned int));
            if(10 < errores){
                printf("\tERROR**Cerrando programa\n");
                exit(1);
            }
        }while(cntd == NULL);
    }

    //Variables para las barras
    int left   = 100;
    int top;
    int right;
    int bottom = getmaxy()-100;
    int pts[10];

    //Variable para el texto
    char texto[6];

    //Establecemos el estilo de las
    //barras, lineas y texto
    setfillstyle(1, COLOR(0, 58, 255));
    setlinestyle(SOLID_LINE, 0, 1);
    settextstyle(BOLD_FONT, 0, 1);
    settextjustify(1, 0);

    //Establecemos el color del texto y
    //diujamos todo lo estatico
    setcolor(0);
    outtextxy(50, bottom+30, "Dia:");
    line(100,getmaxy()-100,getmaxx()-100, getmaxy()-100);

    for(size_t j = inicio-1; j < final; j++){

        left += prtc_2;
        right = left + 4 * prtc_2;

        //Numeros
        sprintf(texto,"%d",j+1);
        outtextxy(left+(right-left)/2, bottom+30, texto);

        left += 5 * prtc_2;

    }

    //Restablecemos la variable left
    left = 100;

    //Disbujamos las barras
    setcolor(COLOR(0, 58, 255));

    for(size_t i = 0; i < max; i++){
    //Este for aumenta la altura de cada barra

        for(size_t j = inicio-1; j < final; j++){
        //Este for imprime cada barra

            cntd[j]++;
            //Si la barra ya se termino de imprimir
            //actualizamos left para la siguiente barra
            //y nos saltamos esta iteracion
            if(cntd[j]>casos[j]){
                left += 6 * prtc_2;
                continue;
            }

            top   = bottom - altura(cntd[j], max, y_long);
            left += prtc_2;
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

            //Dibujamos la barra
            fillpoly(5, pts);

            //Sumamos 5 prtcs_2's por que partimos
            //el sector de cada barra en 1/6,
            //ya habiamos sumado 1/6 asi que nos
            //faltan 5/6 para completar el sector
            left+= 5 * prtc_2;

        }

        left = 100;
    }

    free(cntd);
    return;
}
void graficos_barras(const char *texto, size_t inicio, size_t final, size_t tamanio, const unsigned int *casos){

    //Texto es el titulo de la grafica
    initwindow(1280,720,"Graficos de barras");
    setbkcolor(COLOR(250,250,250));
    cleardevice();
    //Imprimimos el titulo
    setcolor(0);
    settextstyle(BOLD_FONT, 0, 3);
    settextjustify(1, 0);
    outtextxy(100+(getmaxx()-200)/2, 50, texto);

    //Marco coords (100, 100, getmaxx()-100, getmaxy()-100).
    //Calc la dimension del marco
    const short x_long = getmaxx() - 200;
    const short y_long = getmaxy() - 200;

    //Calc cuanto vale cada particion
    const short prtc_1 = (short)roundf(x_long/(float)(final-inicio+1));//Particion del marco
    const short prtc_2 = (short)roundf(prtc_1/6.0);//Particion del sector de cada barra

    //Tenemos que encontrar el dia mas alto
    //y despues redondearlo i.e: 135=>150
    unsigned int max = 0;
    for(size_t i = inicio-1; i<(final); i++){
        if(casos[i] > max) max = casos[i];
    }

    max = integer_round(max);

    impresion_lineas(max, y_long);
    impresion_barras(prtc_2, max, y_long, inicio, final, tamanio, casos);

    return;
}
unsigned int altura(unsigned int n, unsigned int max, unsigned int y){
    return (n*y)/max;
}
void impresion_lineas(int max, int y_long){

    int potencia = digit_count(max) - 2;
    //Este if es para que numeros como 1 se redonde a 5
    //y que 8 se redonde a 10
	if (potencia < 0){
		potencia = 0;
	}

	unsigned int cmp = 5 * int_pow(10, potencia); //comparacion

    unsigned int alt; //altura
    const unsigned int _buffer_max = max;

    const int left   = 100;
    const int right  = getmaxx()-100;
    const int bottom = getmaxy()-100;

    setcolor(COLOR(200, 200, 200));
    setlinestyle(DOTTED_LINE, 0, 1);

    char texto[10];

    while(max){

        alt = altura(max, _buffer_max, y_long);


        sprintf(texto,"%u",max);
        settextstyle(BOLD_FONT, 0, 1);
        settextjustify(2, 1);
        outtextxy(left, bottom-alt, texto);

        line(left, bottom-alt, right, bottom-alt);
        max -= cmp;

    }

    return;
}

