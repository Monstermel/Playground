#include <stdio.h>

int fpeak(FILE *stream) {
    int foo = fgetc(stream);
    ungetc(foo, stream);
    return foo;
}

int main(void) {
    FILE *rand_set = fopen("rand5.txt", "r");
    FILE *compress_output = fopen("output.txt", "w");

    int var;
    int state;  // 0 1
    int count = 0;
    while ((var = fgetc(rand_set)) != EOF) {
        if (var == '0') {
            state = '0';
        } else if (var == '1') {
            state = '1';
        }
        count++;

        int next = fpeak(rand_set);
        if (state != next) {
            if (count > 1 && state == '0') {
                fprintf(compress_output, "%dA", count);
            } else if (state == '0') {
                fprintf(compress_output, "A");
            } else if (count > 1 && state == '1') {
                fprintf(compress_output, "%dB", count);
            } else if (state == '1') {
                fprintf(compress_output, "B");
            }
            count = 0;
        }
    }

    fclose(rand_set);
    fclose(compress_output);

    return 0;
}
