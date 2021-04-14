#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
extern int j;
extern int n;
extern int i;
extern int m;
extern double * __restrict__ vector;

void loop()
{
  int __j_0__ = j;
  int __i_1__ = i;
  
#pragma scop
  for (__j_0__ = 0; __j_0__ <= n - 1; __j_0__ += 1) {
    for (__i_1__ = 0; __i_1__ <= m - 1; __i_1__ += 1) {
      vector[__i_1__ + __j_0__ * m] = 0.0;
    }
  }
  
#pragma endscop
  j = __j_0__;
  i = __i_1__;
}
