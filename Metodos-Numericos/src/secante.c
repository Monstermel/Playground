#include "secante.h"

#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>

#include "funciones.h"
#include "menu.h"

void metodo_secante(unsigned fnctn) {
    puts("\n# METODO DE LA SECANTE");
    printf("# Funcion a resolver: %s\n", fnctns[fnctn]);

    printf("\n# Inicio del intervalo: ");
    double x_n_2;
    scanf("%lf%*c", &x_n_2);
    printf("# Fin del intervalo: ");
    double x_n_1;
    scanf("%lf%*c", &x_n_1);

    printf("# Digite el numero maximo de iteraciones: ");
    unsigned itr_max;
    scanf("%u%*c", &itr_max);

    unsigned crtr;
    crtr_paro(&crtr);

    printf("# Digite la tolerancia: ");
    double tolerancia;
    scanf("%lf%*c", &tolerancia);

    double e_abs, e_rel, e_por, x_n = 0.0;

    unsigned i = 1;
    while (i <= itr_max) {
        if (isnan(f_x[fnctn](x_n_2)) || isnan(f_x[fnctn](x_n_1))) {
            puts("\n# Error de dominio en la evaluacion de funciones");
            break;
        }

        if (fabs(f_x[fnctn](x_n_2) - f_x[fnctn](x_n_1)) < __DBL_EPSILON__) {
            puts("\n# Error, division con cero");
            break;
        }

        x_n = x_n_1 - f_x[fnctn](x_n_1) * (x_n_2 - x_n_1) / (f_x[fnctn](x_n_2) - f_x[fnctn](x_n_1));

        e_abs = fabs(x_n_1 - x_n_2);
        e_rel = e_abs / fabs(x_n_1);
        e_por = e_rel * 100.00;

        if (isnan(e_rel)) {
            puts("\n# Error de dominio en el calculo de errores");
            break;
        }

        printf("\n------Iteracion # %u------", i);
        printf("\nx_n-1     = %.10lf ", x_n_2);
        printf("\nx_n       = %.10lf ", x_n_1);
        printf("\nf(x_n-1)  = %.10lf", f_x[fnctn](x_n_2));
        printf("\nf(x_n)    = %.10lf", f_x[fnctn](x_n_1));
        printf("\nx_n+1     = %.10lf ", x_n);
        printf("\nf(x_n+1)  = %.10lf", f_x[fnctn](x_n));
        printf("\nError Absoluto  : %.10lf", e_abs);
        printf("\nError Relativo  : %.10lf", e_rel);
        printf("\nError Porcentual: %.10lf%%", e_por);
        printf("\n");

        double swtch_crtr[] = {
            [1] = e_abs,
            [2] = e_rel,
            [3] = e_por,
        };

        if (swtch_crtr[crtr] < tolerancia) {
            puts("\n# Tolerancia alcanzada");
            break;
        }

        i++;
        if (itr_max < i) {
            puts("\n# Maximo de iteraciones alcanzada");
            break;
        }

        x_n_2 = x_n_1;
        x_n_1 = x_n;
    }

    printf("\n# Solucion obtenida: x = %.10lf\n\n", x_n);
    system("pause");
    system("cls");
    return;
}