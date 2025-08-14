#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHAR_TO_NUM(character) ((character) - '0')
#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)                                  \
    (byte & 0x80 ? '1' : '0'), (byte & 0x40 ? '1' : '0'),     \
        (byte & 0x20 ? '1' : '0'), (byte & 0x10 ? '1' : '0'), \
        (byte & 0x08 ? '1' : '0'), (byte & 0x04 ? '1' : '0'), \
        (byte & 0x02 ? '1' : '0'), (byte & 0x01 ? '1' : '0')

enum { BITS_PER_CHAR = 8, n = 80, CHARS = 0, BINARY = 1 };

const char msg[] =
    "EL SABIO NO DICE NUNCA TODO LO QUE PIENSA, PERO SIEMPRE PIENSA TODO "
    "LO QUE DICE.";
const char key[] =
    "00101011010100010111010100110011101011010101010111000111001011101110110011"
    "010011";
const char init[] =
    "10110011010010110010011011111100101110010110100110111101110001111010010010"
    "100110";

int nstrtol(const char* ptr, size_t n) {
    char* buffer = (char*)calloc(n, sizeof(char));
    for (int i = 0; i < n; i++) {
        buffer[i] = *(ptr + i);
    }
    int ans = strtol(buffer, NULL, 2);
    free(buffer);
    return ans;
}

void display_blocks(const char* ptr, int mode) {
    assert(mode == CHARS || mode == BINARY);
    printf("[");
    for (int i = 0, cnt = 0; ptr[i]; i++) {
        if (cnt == n) {
            cnt = 0;
            printf("][");
        }
        if (mode == CHARS) {
            printf(BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(ptr[i]));
            cnt += BITS_PER_CHAR;
        } else {
            printf("%c", ptr[i]);
            cnt++;
        }
    }
    printf("]\n\n");
}

int main() {
    // CBC mode
    printf("Mensaje particionado: \n");
    display_blocks(msg, CHARS);

    char* cyphertext =
        (char*)calloc((sizeof(msg) - 1) * BITS_PER_CHAR + 1, sizeof(char));
    for (int i = 0; msg[i]; i++) {
        snprintf(cyphertext + i * BITS_PER_CHAR, BITS_PER_CHAR + 1,
                 BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(msg[i]));
    }
    // Numero de bloques
    int t = (sizeof(msg) - 1) * BITS_PER_CHAR / n;
    // Encriptacion
    for (int i = 0; i < t; i++) {
        const char* ptr = (!i) ? init : cyphertext + (i - 1) * n;
        for (int j = 0; j < n; j++) {
            cyphertext[j + i * n] =
                (CHAR_TO_NUM(cyphertext[j + i * n]) ^ CHAR_TO_NUM(ptr[j]))
                    ? '1'
                    : '0';
            cyphertext[j + i * n] =
                (CHAR_TO_NUM(cyphertext[j + i * n]) ^ CHAR_TO_NUM(key[j]))
                    ? '1'
                    : '0';
        }
    }
    printf("Mensaje encriptado: \n");
    display_blocks(cyphertext, BINARY);
    // Desencriptacion
    for (int i = t - 1; i > -1; i--) {
        const char* ptr = (!i) ? init : cyphertext + (i - 1) * n;
        for (int j = 0; j < n; j++) {
            cyphertext[j + i * n] =
                (CHAR_TO_NUM(cyphertext[j + i * n]) ^ CHAR_TO_NUM(key[j]))
                    ? '1'
                    : '0';
            cyphertext[j + i * n] =
                (CHAR_TO_NUM(cyphertext[j + i * n]) ^ CHAR_TO_NUM(ptr[j]))
                    ? '1'
                    : '0';
        }
    }
    printf("Mensaje desencriptado: \n");
    display_blocks(cyphertext, BINARY);
    // Mensaje original
    printf("Mensaje original: \n");
    for (int i = 0; cyphertext[i]; i += 8) {
        printf("%c", (char)nstrtol(cyphertext + i, 8));
    }
    printf("\n\n");

    free(cyphertext);
    return 0;
}