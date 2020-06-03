#include <stdio.h>
#include <winbgim.h>
#include <graphics.h>
#include "pastel.h"

void rellenar_pastel(int pattern,int a, int b, int c){
    //Establece el relleno y contorno de una figura
    setcolor(COLOR(a,b,c));
    setfillstyle(pattern , COLOR(a,b,c));

    return;
}


void animacion_pastel(int x, int y, int inicio, int final, int radio){

    for(int i = 1; i<=final; i++){
        pieslice(x, y, inicio, inicio+i, radio);
        delay(10);
    }

    return;
}


void texto_pastel(int x, int y, char *imp_1, float porc, char *imp_2, int val, int a, int b, int c){

    char texto[25];

    setcolor(0);
    sprintf(texto, imp_1, porc);
    outtextxy(x, y, texto);

    sprintf(texto, imp_2, val);
    outtextxy(x, y+40, texto);

    rellenar_pastel(SOLID_FILL, a, b, c);
    pieslice(x-15, y-10, 0, 360, 10);

    return;
}


void graficos_pastel(long long total, long long a, long long b){

    initwindow(1280,720,"Graficos de pastel");
    setbkcolor(COLOR(230,230,230));
    cleardevice();

    int radio = 200;
    int x = getmaxx()/2;
    int y = getmaxy()/2;
    int angulo_a = (int)((a*360LL)/total);
    int angulo_b = (int)((b*360LL)/total);

    float aux_1, aux_2, aux_3;
    aux_1 = (float)total;
    aux_2 = (float)a;
    aux_3 = (float)b;
    float porc_a = (float)((aux_2*100.00)/aux_1);
    float porc_b = (float)((aux_3*100.00)/aux_1);

    //Revisar si en serio se necesita while
    while((angulo_a+angulo_b)!=360){
        //Correccion de numeros decimales
        angulo_a++;
    }

    int ultimo_angulo = 90;

    //Se rellena la parte de b
    rellenar_pastel(SOLID_FILL,255,133,0);
    animacion_pastel(x/2, y, ultimo_angulo, angulo_b, radio);

    //Se actualiza el ultimo angulo
    ultimo_angulo+=angulo_b;

    //Se rellena la parte de a
    rellenar_pastel(SOLID_FILL,0, 89,255);
    animacion_pastel(x/2, y, ultimo_angulo, angulo_a, radio);

    //Se dibuja el contorno
    setcolor(0);
    circle(x/2, y, radio);

    //Se establece el estilo del texto
    settextstyle(BOLD_FONT , HORIZ_DIR , 4);
    settextjustify(LEFT_TEXT , CENTER_TEXT);

    //Se imprime el titulo
    texto_pastel(x+60, y-150, "Casos totales:", 0, "    %d", (int)total, 0, 0, 0);

    //Se imprime el texto de a
    texto_pastel(x+60, y-50, "Casos positivos (%.2f%%):", porc_a, "    %d", (int)a, 0, 89, 255);

    //Se imprime el texto de b
    texto_pastel(x+60, y+50, "Casos negativos (%.2f%%):", porc_b, "    %d", (int)b, 255, 133, 0);

    return;
}


