#include "utils.h"

/**
 * Entrada: um número n
 * Saída: 1 se o número for primo; 0 se o número não for primo
 */

int main() {
  long long n;
  scanf("%lld", &n);
  printf("%d\n", is_prime(n));
  return 0;
}