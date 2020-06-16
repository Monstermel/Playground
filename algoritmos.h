#ifndef ALGORITMOS_H_INCLUDED
#define ALGORITMOS_H_INCLUDED
#include "registros.h"

void sort_fechas(Fecha *fechas, size_t elementos);
_uint integer_round(_uint n);//Funion que redondea un int ej: 31->35, 3567->4000
size_t digit_count(int n);//Funcion que dice cuantos digitos tiene un int

int comparar_dia(Fecha a, Fecha b);
int int_pow(int n, _uint m);//Existe pow pero regresa tipos de punto flotante y puede causar errores

#endif // ALGORITMOS_H_INCLUDED
