#include "utils.h"

/**
 * Entrada: dois números (a, b)
 * Saída: a combiação linear de a e b que resulta no mdc(a, b)
 * Em outras palavras, os valores de s e t na equação mdc(a, b) = s*a + t*b
 */

int main() {
  long long a, b, s, t;
  scanf("%lld %lld", &a, &b);
  euclides(a, b, &s, &t);
  printf("s = %lld\nt = %lld\n", s, t);
  return 0;
}