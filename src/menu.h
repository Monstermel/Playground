#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

void menu_funciones(unsigned* opc);
void menu_metodo(unsigned* opc, unsigned fnctn);
void read_opc(unsigned* opc);
void crtr_paro(unsigned* crtr);

extern const char* fnctns[];

#endif