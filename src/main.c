#include <assert.h>
#include <stdlib.h>
#include <tgmath.h>

#include "menu.h"

/*
    Nota:
    Talves se saquen de onda con los whiles, es algo que no nos enseñan en la carrea
    (que se me hace medio pendejo ya que es muy util), pero en C/C++ existe un operador
    especial, la coma: ",".
    por ejemplo: (expresion_1, expresion_2, expresion_3), si escribimos eso lo que el
    programa hara es evualar la expresion 1, luego la 2 y al final la 3, (puede ser caulquier
    tipo de instruccion) y regresara lo que regrese la ultima en ese caso la expresion 3.
*/

int main(void) {
    unsigned opc_1;
    while (menu_funciones(&opc_1), system("cls"), opc_1 != 5) {
        unsigned opc_2;
        while (menu_metodo(&opc_2, opc_1), system("cls"), opc_2 != 3) {
            /*
                Aqui va el resto del programa:
                Opc_1 es la funcion que vamos a resolver.
                Opc_2 es el metodo que vamos a usar para eso.
                Dependiendo el metodo capturamos los siguientes
                datos: intervalo o valor inicial, máximo de
                iteraciones y tolerancia.
            */
        }
    }
    return EXIT_SUCCESS;
}
