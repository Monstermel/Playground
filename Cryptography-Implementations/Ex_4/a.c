#include <stdio.h>

#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)                                  \
    (byte & 0x10 ? '1' : '0'), (byte & 0x08 ? '1' : '0'),     \
        (byte & 0x04 ? '1' : '0'), (byte & 0x02 ? '1' : '0'), \
        (byte & 0x01 ? '1' : '0')

int main(void) {
    printf("Mensaje: ");
    char mensaje[50];
    scanf("%[^\n]%*c", mensaje);

    for (int i = 0; mensaje[i]; i++) {
        printf(BYTE_TO_BINARY_PATTERN " ", BYTE_TO_BINARY(mensaje[i] - 64));
    }
    printf("\n\n");

    char key[] = {"ABCD"};
    printf("Clave: %s\n", key);
    for (int i = 0; key[i]; i++) {
        printf(BYTE_TO_BINARY_PATTERN " ", BYTE_TO_BINARY(key[i] - 64));
    }
    printf("\n\n");

    printf("Tecnica de Vernam:\n");
    char result[50];
    for (int i = 0; mensaje[i]; i++) {
        result[i] = (key[i] - 64) ^ (mensaje[i] - 64);
        printf(BYTE_TO_BINARY_PATTERN " ", BYTE_TO_BINARY(result[i] - 64));
        if (!mensaje[i + 1]) {
            result[i + 1] = '\0';
        }
    }
    printf("\n\n");

    printf("Mensaje desencriptado:\n");
    for (int i = 0; result[i]; i++) {
        result[i] = (key[i] - 64) ^ (result[i] - 64);
        printf(BYTE_TO_BINARY_PATTERN " ", BYTE_TO_BINARY(result[i] - 64));
    }
    printf("\n\n");

    return 0;
}
