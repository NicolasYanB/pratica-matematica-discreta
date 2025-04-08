#include <stdio.h>

/**
 * Entrada: Dois números (a, b) e um outro número m (0 ou 1)
 * Saída: mdc(a, b), se m for 1 ou o mmc(a, b) se m for 0
 */

long long llmax(long long a, long long b) {
  if (a >= b) return a;
  return b;
}

long long llmin(long long a, long long b) {
  if (a <= b) return a;
  return b;
}

long long gcd_lcm(long long a, long long b, int op) {
  // se op for 1 retorna mdc, se op for 0 retorna mmc 
  long long final = op == 1 ? llmin(a, b) : llmax(a, b);
  long long acc = 1, result = 1;

  for (long long i = 2; i * i <= final; i++) {
    while (a % i == 0 || b % i == 0) {
      int condition1 = a % i == 0;
      int condition2 = b % i == 0;
      if (op == 1 && (condition1 && condition2)) {
        acc *= i;
      } else if (op == 0 && (condition1 || condition2)) {
        acc *= i;
      }
      a /= condition1 ? i : 1;
      b /= condition2 ? i : 1;
    }
    result *= acc;
    acc = 1;
  }

  if (a > 1 || b > 1) {
    if (a == b) {
      result *= a;
    } else if (op == 0) {
      result *= a * b;
    }
  }

  return result;
}

int main() {
  long long a, b, res;
  int m;
  scanf("%lld %lld %d", &a, &b, &m);
  res = gcd_lcm(a, b, m);
  printf("%lld\n", res);
  return 0;
}