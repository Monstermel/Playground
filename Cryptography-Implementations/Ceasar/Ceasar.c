// Abreu Alvarez Jose Antonio
// Seguridad Computacional

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>

const int ascii_offset = 65;
const int alphbt_size = 26;

int mod(const int a, const int b) {
    return (a < 0 ? (((a % b) + b) % b) : (a % b));
}

// Ej: ceaser 10 "hola mundo"
int main(int argc, char **argv) {
    int key = atoi(argv[1]);
    char *str = argv[2];

    char *itr = str;
    while (*itr) {
        *itr = toupper((int)*itr);
        itr++;
    }

    printf("%s : %d\n", str, key);

    printf("Encriptado: ");
    key = mod(key, alphbt_size);
    for (int i = 0; i < sizeof(str) - 1; i++) {
        if ('A' <= str[i] && str[i] <= 'Z') {
            str[i] =
                mod(str[i] - ascii_offset + key, alphbt_size) + ascii_offset;
        }
    }
    printf("%s\n", str);

    printf("Desencriptado: ");
    for (int i = 0; i < sizeof(str) - 1; i++) {
        if ('A' <= str[i] && str[i] <= 'Z') {
            str[i] =
                mod(str[i] - ascii_offset - key, alphbt_size) + ascii_offset;
        }
    }
    printf("%s\n", str);

    return EXIT_SUCCESS;
}