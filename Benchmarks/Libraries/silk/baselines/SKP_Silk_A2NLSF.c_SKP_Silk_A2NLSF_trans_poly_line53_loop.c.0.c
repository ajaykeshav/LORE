#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
extern int k;
extern int dd;
extern int n;
extern int * __restrict__ p;

void loop()
{
  int __k_0__ = k;
  int __n_1__ = n;
  
#pragma scop
  for (__k_0__ = 2; __k_0__ <= dd; __k_0__ += 1) {
    for (__n_1__ = dd; __n_1__ >= __k_0__ + 1; __n_1__ += - 1) {
      p[__n_1__ - 2] -= p[__n_1__];
    }
{
      p[__k_0__ - 2] -= p[__k_0__] << 1;
    }
  }
  
#pragma endscop
  k = __k_0__;
  n = __n_1__;
}
