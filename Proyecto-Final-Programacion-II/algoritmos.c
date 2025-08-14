
#include <stdio.h>
#include <math.h>

#include "algoritmos.h"
#include "registros.h"

//Insertion sort
void sort_fechas(Fecha *fechas, size_t elementos){
    int i, j;
    Fecha aux;
    for (i = 1; i < elementos; i++){
        aux = fechas[i];
        j = i - 1;
        while (j >= 0 && comparar_dia(fechas[j], aux)== 1){
            fechas[j+1] = fechas[j];
            j --;
        }
       fechas[j+1] = aux;
    }
    return;
}

//Regresa si uno si a es mayor o igual que b
//y 0 si b es mayor a y -1 si son iguales
int comparar_dia(Fecha a, Fecha b){

    if(a.anio > b.anio){
        return 1;
    }
    else if(a.anio < b.anio){
        return 0;
    }
    else{
        if(a.mes > b.mes){
            return 1;
        }
        else if(a.mes < b.mes){
            return 0;
        }
        else{
            if(a.dia > b.dia){
                return 1;
            }
            else if(a.dia < b.dia){
                return 0;
            }
            else{
                return -1;
            }
        }
    }

}

_uint integer_round(_uint n){

    int potencia = digit_count(n) - 3;

    //Este if es para que numeros como 1 se
    //redonde a 5 y que 8 se redonde a 10
	if (potencia < 0){
		potencia = 0;
	}

    //Variable de comparacion
	_uint cmp = 5 * int_pow(10, potencia);

    while (n % cmp != 0){
        n++;
    }

    return n;
}

//Mi implementacion de exponential squaring
int int_pow(int n, _uint m){
    if(m==0){
        return 1;
    }
    else if(m==1){
        return n;
    }
    else if(m%2==0){
        return int_pow(n*n, m/2);
    }
    else if(m%2!=0){
        return n*int_pow(n*n, (m-1)/2);
    }
}

size_t digit_count(int n){
    double aux = floor(log10(n));
    size_t ans = 1 + (size_t)(aux);
    return ans;
}







