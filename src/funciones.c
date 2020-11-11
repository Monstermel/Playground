#include "funciones.h"

#include <tgmath.h>

double f_1(double x) { return x * x * cos(x) - 2.0 * x; }
double df_1(double x) { return 2.0 * x * cos(x) - x * x * sin(x) - 2.0; }

double f_2(double x) { return (6.0 - (2.0 / (x * x))) * exp(2.0 + x) / 4.0 + 1.0; }
double df_2(double x) {
    return exp(x + 2.0) / (x * x * x) + (exp(x + 2.0) * (3 * x * x - 1.0)) / (2.0 * x * x);
}

double f_3(double x) { return x * x * x - 3.0 * sin(x * x) + 1.0; }
double df_3(double x) { return 3 * x * x - 6 * x * cos(x * x); }

double f_4(double x) { return x * x * x + 6 * x * x + 9.4 * x + 2.5; }
double df_4(double x) { return 3.0 * x * x + 12.0 * x + 9.4; }

double (*f_x[])(double) = {
    [1] = f_1,
    [2] = f_2,
    [3] = f_3,
    [4] = f_4,
};

double (*df_x[])(double) = {
    [1] = df_1,
    [2] = df_2,
    [3] = df_3,
    [4] = df_4,
};
