#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tgmath.h>

int main(int argc, char* argv[]) {
    int n = atoi(argv[1]);
    unsigned long long seed = strtoull(argv[2], NULL, 10);
    char* next_seed = (char*)calloc(2 * n, sizeof(char));

    char format_1[50];
    snprintf(format_1, sizeof(format_1), "%%0%dllu", 2 * n);

    char format_2[50];
    snprintf(format_2, sizeof(format_2), "%%0%dllu,", n);

    printf("Seed: %llu n: %d\n", seed, n);
    printf("(");
    for (int i = 0; i < 100; i++) {
        snprintf(next_seed, 2 * n * sizeof(char), format_1, seed * seed);
        int offset = (int)floor(n / 2);
        int digit_pos = 10;
        seed = (next_seed[n + offset - 1] - '0');
        for (int j = n + offset - 2; offset <= j; j--) {
            seed += (next_seed[j] - '0') * digit_pos;
            digit_pos *= 10;
        }
        printf(format_2, seed);
    }
    printf(")");

    return 0;
}
