#include <graphics.h>
#include <winbgim.h>
#include <stdio.h>

#include "pastel.h"

void texto_pastel(int x, int y, const char *imp_1, float porc, const char *imp_2, int val, int a, int b, int c){

    char texto[100];

    setcolor(0);
    sprintf(texto, imp_1, porc);
    outtextxy(x, y, texto);

    sprintf(texto, imp_2, val);
    outtextxy(x, y+40, texto);

    rellenar_pastel(SOLID_FILL, a, b, c);
    pieslice(x-15, y-10, 0, 360, 10);

    return;
}
void animacion_pastel(int x, int y, int inicio, int final, int radio){

    for(int i = 1; i<=final; i++){
        pieslice(x, y, inicio, inicio+i, radio);
        delay(10);
    }

    return;
}
void graficos_pastel(long long total, long long a, long long b){

    initwindow(1280,720,"Graficos de pastel");
    setbkcolor(COLOR(250,250,250));
    cleardevice();

    unsigned char radio = 200;
    short x             = (short)(getmaxx()/2);
    short y             = (short)(getmaxy()/2);

    //Valores entre [0,360]
    short ultimo_angulo = 90;
    short angulo_a      = (short)((a*360LL)/total);
    short angulo_b      = (short)((b*360LL)/total);
    if((angulo_a+angulo_b)!=360){
        //Correccion de numeros decimales
        angulo_a++;
    }

    float porc_a = 100.00 * (a/(float)total);
    float porc_b = 100.00 * (b/(float)total);

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
    texto_pastel(x-280, y-250, "Positivos y no positivos general", 0.0, "", 0, 250,250,250);

    //Se imprime los casos totales
    texto_pastel(x+60, y-150, "Casos totales:", 0.0, "    %d", (int)total, 0, 0, 0);

    //Se imprime el texto de a
    texto_pastel(x+60, y-50, "Casos positivos (%.2f%%):", porc_a, "    %d", (int)a, 0, 89, 255);

    //Se imprime el texto de b
    texto_pastel(x+60, y+50, "Casos negativos (%.2f%%):", porc_b, "    %d", (int)b, 255, 133, 0);

    return;
}
void rellenar_pastel(int pattern, int a, int b, int c){
    //Establece el relleno y contorno del pastel
    setcolor(COLOR(a,b,c));
    setfillstyle(pattern , COLOR(a,b,c));

    return;
}




