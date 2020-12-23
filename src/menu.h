#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <stdlib.h>
#include "matrix.h"

void menu_programa(unsigned* opc);
void menu_ectn_slvr(unsigned* opc);
void menu_funciones(unsigned* opc);
void menu_metodo(unsigned* opc, unsigned fnctn);
void read_opc(unsigned* opc);
void read_opc_size_t(size_t* opc);
void crtr_paro(unsigned* crtr);
void crrctn_mtrx(unsigned* opc, size_t N, size_t M, double arr[N][M]);

extern const char* fnctns[];

#endif
