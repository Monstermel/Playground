#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)                                  \
    (byte & 0x80 ? '1' : '0'), (byte & 0x40 ? '1' : '0'),     \
        (byte & 0x20 ? '1' : '0'), (byte & 0x10 ? '1' : '0'), \
        (byte & 0x08 ? '1' : '0'), (byte & 0x04 ? '1' : '0'), \
        (byte & 0x02 ? '1' : '0'), (byte & 0x01 ? '1' : '0')

enum { BITS_PER_CHAR = 8, CHARS_PER_BLOCK = 10, n = 80, k = 80, r = 80 };

const unsigned char msg[] =
    "EL SABIO NO DICE NUNCA TODO LO QUE PIENSA, PERO SIEMPRE PIENSA TODO "
    "LO QUE DICE.";
const unsigned char key[] = {0b00101011, 0b01010001, 0b01110101, 0b00110011,
                             0b10101101, 0b01010101, 0b11000111, 0b00101110,
                             0b11101100, 0b11010011};
const unsigned char init[] = {0b10110011, 0b01001011, 0b00100110, 0b11111100,
                              0b10111001, 0b01101001, 0b10111101, 0b11000111,
                              0b10100100, 0b10100110};

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
    // CFB mode
    printf("Mensaje particionado: \n");
    display_blocks(msg, sizeof(msg));

    int cyphr_len = sizeof(msg);
    unsigned char* cyphertext =
        (unsigned char*)calloc(cyphr_len, sizeof(unsigned char));
    memcpy_s(cyphertext, sizeof(msg), msg, sizeof(msg));

    // Encriptacion
    printf("Mensaje encriptado: \n");
    unsigned char* I_j =
        (unsigned char*)calloc(CHARS_PER_BLOCK, sizeof(unsigned char));
    unsigned char* O_i =
        (unsigned char*)calloc(CHARS_PER_BLOCK, sizeof(unsigned char));

    int u = (sizeof(msg) - 1) * BITS_PER_CHAR / n;
    memcpy_s(I_j, CHARS_PER_BLOCK, init, sizeof(init));
    for (int i = 0; i < u; i++) {
        for (int j = 0; j < CHARS_PER_BLOCK; j++) {
            O_i[j] = I_j[j] ^ key[j];
        }
        for (int j = 0; j < CHARS_PER_BLOCK; j++) {
            cyphertext[j + i * CHARS_PER_BLOCK] ^= O_i[j];
            I_j[j] = cyphertext[j + i * CHARS_PER_BLOCK];
        }
    }
    display_blocks(cyphertext, cyphr_len);

    // Desencriptacion
    printf("Mensaje desencriptado: \n");
    memcpy_s(I_j, CHARS_PER_BLOCK, init, sizeof(init));
    for (int i = 0; i < u; i++) {
        for (int j = 0; j < CHARS_PER_BLOCK; j++) {
            O_i[j] = I_j[j] ^ key[j];
        }
        for (int j = 0; j < CHARS_PER_BLOCK; j++) {
            I_j[j] = cyphertext[j + i * CHARS_PER_BLOCK];
            cyphertext[j + i * CHARS_PER_BLOCK] ^= O_i[j];
        }
    }
    display_blocks(cyphertext, cyphr_len);
    free(O_i);
    free(I_j);

    // Mensaje original
    printf("Mensaje original: \n");
    for (int i = 0; i < cyphr_len - 1; i++) {
        printf("%c", cyphertext[i]);
    }
    printf("\n\n");

    free(cyphertext);
    return 0;
}