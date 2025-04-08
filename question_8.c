#include "utils.h"

/**
 * Entrada: três números (a, b, m) que formam a congruência ax === b (mod m)
 * Saída: resultado da congruência (x), ou uma mensagem informando que a congruência não têm solução
 */

int main() {
  long long a, b, m;
  scanf("%lld %lld %lld", &a, &b, &m);
  long long x = congruence(a, b, m);
  if (x == -1) {
    printf("Não existe solução\n");
  } else {
    printf("%lld\n", x);
  }
  return 0;
}