#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)                                  \
    (byte & 0x80 ? '1' : '0'), (byte & 0x40 ? '1' : '0'),     \
        (byte & 0x20 ? '1' : '0'), (byte & 0x10 ? '1' : '0'), \
        (byte & 0x08 ? '1' : '0'), (byte & 0x04 ? '1' : '0'), \
        (byte & 0x02 ? '1' : '0'), (byte & 0x01 ? '1' : '0')

enum { BITS_PER_CHAR = 8, CHARS_PER_BLOCK = 10, n = 80 };

const char msg[] =
    "EL SABIO NO DICE NUNCA TODO LO QUE PIENSA, PERO SIEMPRE PIENSA TODO "
    "LO QUE DICE.";
const unsigned char key[] = {0b00101011, 0b01010001, 0b01110101, 0b00110011,
                             0b10101101, 0b01010101, 0b11000111, 0b00101110,
                             0b11101100, 0b11010011};

void display_blocks(const unsigned char* ptr, int size) {
    printf("[");
    for (int i = 0, cnt = 0; i < size - 1; i++) {
        if (cnt == n) {
            cnt = 0;
            printf("][");
        }
        printf(BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(ptr[i]));
        cnt += BITS_PER_CHAR;
    }
    printf("]\n\n");
}

int main() {
    // ECB mode
    printf("Mensaje particionado: \n");
    display_blocks(msg, sizeof(msg));

    int cyphr_len = sizeof(msg);
    unsigned char* cyphertext = (char*)calloc(cyphr_len, sizeof(char));
    memcpy_s(cyphertext, sizeof(msg), msg, sizeof(msg));

    // Encriptacion
    printf("Mensaje encriptado: \n");
    for (int i = 0; i < cyphr_len - 1; i++) {
        cyphertext[i] ^= key[i % CHARS_PER_BLOCK];
    }
    display_blocks(cyphertext, cyphr_len);
    // Desencriptacion
    printf("Mensaje desencriptado: \n");
    for (int i = 0; i < cyphr_len - 1; i++) {
        cyphertext[i] ^= key[i % CHARS_PER_BLOCK];
    }
    display_blocks(cyphertext, cyphr_len);
    // Mensaje original
    printf("Mensaje original: \n");
    for (int i = 0; i < cyphr_len - 1; i++) {
        printf("%c", cyphertext[i]);
    }
    printf("\n\n");

    free(cyphertext);
    return 0;
}