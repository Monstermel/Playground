#include <stdio.h>
#include <tgmath.h>

const int ascii_offset = 65;
const int alphbt_size = 26;

int mod(const int a, const int b) {
  return (a < 0 ? (((a % b) + b) % b) : (a % b));
}

int main(void) {
  char key[] = "MAC";
  char str[] = "HOLAQUEHACE";
  printf("%s : %s\n", str, key);

  printf("Encriptado: ");
  for (int i = 0, j = 0; str[i]; i++) {
    if ('A' <= str[i] && str[i] <= 'Z') {
      str[i] =
          mod(str[i] + key[j] - 2 * ascii_offset, alphbt_size) + ascii_offset;
      j = (j + 1) % (sizeof(key) - 1);
    }
  }
  printf("%s\n", str);

  printf("Desencriptado: ");
  for (int i = 0, j = 0; str[i]; i++) {
    if ('A' <= str[i] && str[i] <= 'Z') {
      str[i] =
          mod(str[i] - key[j] - 2 * ascii_offset, alphbt_size) + ascii_offset;
      j = (j + 1) % (sizeof(key) - 1);
    }
  }
  printf("%s\n", str);

  return 0;
}
