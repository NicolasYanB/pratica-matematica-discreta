#include <stdio.h>

/**
 * Entrada: Um número n
 * Saída: Todos os fatores primos desse número em ordem
 */

void factorization(long long n) {
  for (long long i = 2; i * i <= n; i++) {
    while (n % i == 0) {
      printf("%lld\n", i);
      n /= i;
    }
  }
  if (n > 1) {
    printf("%lld\n", n);
  }
}

int main () {
  long long n;
  scanf("%lld", &n);
  factorization(n);
  return 0;
}

