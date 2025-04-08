#include "utils.h"

/**
 * Entrada: dois números (a, b)
 * Saída: mdc(a, b)
 */

int main() {
  long long a, b, mdc;
  scanf("%lld %lld", &a, &b);
  mdc = gcd(a, b);
  printf("%lld\n", mdc);
}