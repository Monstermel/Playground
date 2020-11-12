#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>

#include "funciones.h"
#include "menu.h"

void metodo_newton(unsigned fnctn) {
    puts("\n# METODO DE NEWTON");
    printf("# Funcion a resolver: %s\n", fnctns[fnctn]);

    printf("\n# Valor inicial: ");
    double x;
    scanf("%lf%*c", &x);

    printf("# Digite el numero maximo de iteraciones: ");
    unsigned itr_max;
    scanf("%u%*c", &itr_max);

    printf("# Digite la tolerancia: ");
    double tolerancia;
    scanf("%lf%*c", &tolerancia);

    double e_abs, e_rel, e_por;
    double aux;

    printf("\n------Iteracion # 0------");
    printf("\nxk     = %.6lf ", x);
    printf("\nf(xk)  = %.6lf", f_x[fnctn](x));
    printf("\nf'(xk) = %.6lf", df_x[fnctn](x));

    unsigned i = 1;
    while (i <= itr_max) {
        if (isnan(f_x[fnctn](x)) || isnan(df_x[fnctn](x))) {
            puts("\n# Error de dominio");
            break;
        }

        if (df_x[fnctn](x) == 0) {
            puts("\n# Error, derivada igual a 0");
            break;
        }

        aux = x - f_x[fnctn](x) / df_x[fnctn](x);

        e_abs = fabs(aux - x);
        e_rel = e_abs / fabs(x);
        e_por = e_rel * 100.00;


        printf("\n------Iteracion # %u------", i);
        printf("\nxk     = %.10lf ", aux);
        printf("\nf(xk)  = %.10lf", f_x[fnctn](aux));
        printf("\nf'(xk) = %.10lf", df_x[fnctn](aux));
        printf("\nError Absoluto  : %.10lf", e_abs);
        printf("\nError Relativo  : %.10lf", e_rel);
        printf("\nError Porcentual: %.10lf%%", e_por);
        printf("\n");

        if (e_abs < tolerancia) {
            puts("\n# Tolerancia alcanzada");
            break;
        }

        i++;
        if (itr_max < i) {
            puts("\n# Maximo de iteraciones alcanzada");
            break;
        }

        x = aux;
    }

    printf("\n# Solucion obtenida: x  %.10lf\n\n", aux);
    system("pause");
    system("cls");

    return;
}