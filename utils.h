#include <stdio.h>

int is_prime(long long n) {
  if (n == 2) return 1;
  if (n < 2) return 0;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      return 0;
    }
  }
  return 1;
}

long long gcd(long long a, long long b) {
  if (b > a) return gcd(b, a);
  if (a % b == 0) return b;
  return gcd(b, a % b);
}

void euclides(long long a, long long b, long long *s, long long *t) {
  if (b > a) return euclides(b, a, t, s);
  if (b == 0) {
    (*s) = 1;
    (*t) = 0;
    return;
  }
  euclides(b, a % b, s, t);
  long long temp;
  temp = *s;
  (*s) = *t;
  (*t) = (*t * -(a / b)) + temp;
}

long long mod(long long a, long long b) {
  // Em C o operador % não apresenta o comportamento esperado
  // ao ser usado com números negativos, essa função trata isso
  // e implementa o comportamento experado
  long long result = a % b;
  if (result < 0) {
    result = b + result;
  }
  return result;
}

long long inverse_mod(long long a, long long b) {
  // Caso retorne -1 significa que o inverso não existe
  if (gcd(a, b) != 1) {
    return -1;
  }
  long long x, y;
  euclides(a, b, &x, &y);
  return mod(x, b);
}

long long congruence(long long a, long long b, long long m) {
  // encontra x em ax === b (mod m)
  long long g = gcd(a, m);
  if (g != 1) {
    if (b % g != 0) {
      return -1;
    } else {
      a /= g;
      b /= g;
      m /= g;
    }
  }
  long long inv = inverse_mod(a, m);
  long long result = b*inv;
  return mod(result, m);
}

long long chinese_remainder(long long r[], long long m[], int size) {
  /**
   * Sendo o sistema de congruências: x === r_1 (mod m_1); x === r_2 (mod m_2); etc
   * r - é o array dos restos
   * m - é o array dos mods
   */
  long long M = 1, s, M_i, result = 0;
  // obtem M, produto de todos os m
  for (int i = 0; i < size; i++) {
    if (gcd(M, m[i]) != 1) {
      return -1;
    }
    M *= m[i];
  }
  
  for (int i = 0; i < size; i++) {
    M_i = M/m[i];
    s = congruence(M_i, 1, m[i]);
    result += M_i*s*r[i];
  }
  return mod(result, M);
}