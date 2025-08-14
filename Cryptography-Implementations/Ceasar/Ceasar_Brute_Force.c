#include <stdio.h>
#include <string.h>
#include <tgmath.h>
#define block_size 1024

const int ascii_offset = 65;
const int alphbt_size = 26;

int mod(const int a, const int b) {
  return (a < 0 ? (((a % b) + b) % b) : (a % b));
}

int main(void) {
  char input[block_size] =
      "G HRAK PGE CGY VRKGYGTZRE LREOTM GRUTM ZNK XUGJ CNKT YAJJKTRE G NGXRKE "
      "JGBOJYUT GVVKGXY. ZNK ZOTE HOXJ SGTKABKXY JKYVKXGZKRE HAZ YZORR "
      "IURROJKY GMGOTYZ ZNK XGOJKX'Y NKRSKZ. ZNK MAE YZUVY, RUUQY ZNK OTPAXKJ "
      "PGE ZNGZ RGEY JUCT UT ZNK LRUUX GTJ, LKKROTM MAORZE, JKIOJKY ZU ZGQK OZ "
      "NUSK. UTIK ZNKXK, ZNK XOJKX VAZY ZNK ATIUTYIOUAY HOXJ OT G IGMK COZN "
      "YUSK HXKGJ GTJ YUSK CGZKX; ZNKT RKGBKY ZNK NUAYK. G SOTAZK RGZKX, ZNK "
      "HRAK PGE YZGXZY XKIUBKXOTM GTJ, YZORR JOFFE, RUUQY GXUATJ... GTJ OZ "
      "YKKY HXKGJ... YKKY CGZKX... YKKY NOSYKRL YAXXUATJKJ HE HGXY... "
      "UBKXCNKRSKJ, NURJY OZY NKGJ COZN OZY COTMY GTJ IXOKY: NURE IUC! O "
      "QORRKJ ZNK MAE OT ZNK SUZUXIEIRK... !";
  char output[block_size];
  memcpy(output, input, sizeof(input));

  // Fuerza bruta
  for (int key = 0; key <= 25; key++) {
    for (int i = 0; input[i]; i++) {
      if ('A' <= input[i] && input[i] <= 'Z') {
        output[i] =
            mod(input[i] - ascii_offset - key, alphbt_size) + ascii_offset;
      }
    }
    printf("%d: %s\n\n", key, output);
  }

  return 0;
}
