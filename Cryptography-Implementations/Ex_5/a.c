#include <stdio.h>

int main(void) {
    char num_cta[] = "7992739871x";
    printf("Num cta: %s\n", num_cta);

    int sum = 0;
    int size_cta = sizeof(num_cta) - 1;
    for (int i = 2; i <= size_cta; i++) {
        if (!(i % 2)) {
            printf("[%d]: %c ->", size_cta - i, num_cta[size_cta - i]);
            int buffer = 2 * (num_cta[size_cta - i] - '0');
            if (buffer > 9) {
                buffer -= 9;
            }
            num_cta[size_cta - i] = buffer + '0';
            printf(" %c\n", num_cta[size_cta - i]);
        }
        sum += num_cta[size_cta - i] - '0';
    }
    printf("Suma: %d\n", sum);
    printf("Digito de control: %d\n", (sum * 9) % 10);
    return 0;
}
