#include <stdio.h>
#include <winbgim.h>
#include <graphics.h>
#include "cuadricula.h"

void mostrar_cuadricula(int particion){

    setcolor(0);

    for(int i=getmaxx()/particion; i<getmaxx(); i+=getmaxx()/particion){

        line(i, 0, i, getmaxy());

    }

     for(int i=getmaxy()/particion; i<getmaxy(); i+=getmaxy()/particion){

        line(0, i, getmaxx(), i);

    }

    return;
}
