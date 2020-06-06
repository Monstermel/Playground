#ifndef BARRAS_H_INCLUDED
#define BARRAS_H_INCLUDED

unsigned int altura(unsigned int n, unsigned int max, unsigned int y);
void impresion_lineas(int max, int y_long);
void impresion_barras(int prtc_2, int max, int y_long, size_t dias, const unsigned int *casos);
void graficos_barras(const char *texto, size_t dias, const unsigned int *casos);

#endif // BARRAS_H_INCLUDED
