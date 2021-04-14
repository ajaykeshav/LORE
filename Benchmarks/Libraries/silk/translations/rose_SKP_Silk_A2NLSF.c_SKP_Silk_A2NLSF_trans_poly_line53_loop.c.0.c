#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
  int p[127];
  int n;
  int dd;
  int k;
  FILE stderr[138];
  FILE stdout[343];
  FILE stdin[347];
  int __k_0__ = k;
  int __n_1__ = n;
  
#pragma scop
  for (__k_0__ = 2; __k_0__ <= 25; __k_0__ += 1) {
    for (__n_1__ = dd; __n_1__ >= 47; __n_1__ += - 1) {
      p[__n_1__ - 2] -= p[__n_1__];
    }
{
      p[__k_0__ - 2] -= p[__k_0__] << 1;
    }
  }
  
#pragma endscop
  k = __k_0__;
  n = __n_1__;
  return 0;
}
