#include "utils.h"
#include <time.h>

/**
 * Printa todos os números primos encontrados em um intervalo de
 * 60 segundos
 */

int main() {
  time_t begin, now;
  double passed = 0;
  long long n = 2;
  time(&begin);
  do {
    if (is_prime(n)) {
      printf("%lld\n", n);
    }
    n++;
    time(&now);
    passed = difftime(now, begin);
  } while(passed < 60);
  return 0;
}