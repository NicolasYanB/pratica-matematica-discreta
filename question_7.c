#include "utils.h"

/**
 * Entrada: dois valores inteiros (a, b)
 * Saída: O inveso de a modulo b
 * Em outras palavras, o resultado da congruência ax === 1 (mod b)
 * caso o inverso não exista será sinalizado
 */
int main() {
  long long a, b, inv;
  scanf("%lld %lld", &a, &b);
  inv = inverse_mod(a, b);
  if (inv == -1) {
    printf("Não existe inverso\n");
  } else {
    printf("%lld\n", inv);
  }
  return 0;
}