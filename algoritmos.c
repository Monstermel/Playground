#include <math.h>
#include <stdio.h>
#include "algoritmos.h"

size_t digit_count(int n){
    double aux = floor(log10(n));
    size_t ans = 1 + (size_t)(aux);
    return ans;
}

//Mi implementacion de exponential squaring
int int_pow(int n, unsigned int m){
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

unsigned int integer_round(unsigned int n){

    int potenc = digit_count(n) - 2;

	if (potenc < 0){
		//Este if es para que numeros como 1 se redonde a 5
		//y que 8 se redonde a 10
		potenc = 0;
	}

	unsigned int cmp = 5 * int_pow(10, potenc);

    while (n % cmp != 0){
        n++;
    }

    return n;
}
