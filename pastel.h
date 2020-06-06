#ifndef PASTEL_H_INCLUDED
#define PASTEL_H_INCLUDED


void imprimir_titulo();//Agregar esta funcion o poner titulo al la funcion graficos pastel
void rellenar_pastel(int pattern,int a, int b, int c);
void animacion_pastel(int x, int y, int inicio, int final, int radio);
void texto_pastel(int x, int y, const char *imp_1, float porc, const char *imp_2, int val, int a, int b, int c);
void graficos_pastel(long long total, long long a, long long b);//Funcion principal

#endif // PASTEL_H_INCLUDED
