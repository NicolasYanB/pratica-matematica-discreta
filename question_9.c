#include "utils.h"

/**
 * Entrada: 3 pares de números (r_i, m_i) representando um sistema com três congruências lineares na forma
 * x === r_1 (mod m_1); x === r_2 (mod m_2); x === r_3 (mod m_3)
 * Saída: o valor de x, solução do sistema
 */

int main() {
  long long r[3], m[3], x;
  for (int i=0; i<3; i++) {
    scanf("%lld %lld", &r[i], &m[i]);
  }
  x = chinese_remainder(r, m, 3);
  printf("%lld\n", x);
  return 0;
}