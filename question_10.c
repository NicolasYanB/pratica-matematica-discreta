#include "utils.h"

/**
 * Entrada: um número (n) seguido de n pares de números (r_i, m_i) representando um sistema com três congruências lineares na forma
 * x === r_1 (mod m_1); x === r_2 (mod m_2); x === r_3 (mod m_3); ...
 * Saída: o valor de x, solução do sistema
 */

int main() {
  int n;
  scanf("%d", &n);
  long long r[n], m[n], x;
  for (int i=0; i<n; i++) {
    scanf("%lld %lld", &r[i], &m[i]);
  }
  x = chinese_remainder(r, m, n);
  printf("%lld\n", x);
  return 0;
}