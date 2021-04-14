#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
extern long j;
extern long n;
extern long i;
extern double * __restrict__ out;

void loop()
{
  int __j_0__ = j;
  int __i_1__ = i;
  
#pragma scop
  for (__j_0__ = 2; __j_0__ <= n - ((long )2) - 1; __j_0__ += 1) {
    for (__i_1__ = 2; __i_1__ <= n - ((long )2) - 1; __i_1__ += 1) {
      out[__i_1__ + __j_0__ * n] = ((double )0.0);
    }
  }
  
#pragma endscop
  j = __j_0__;
  i = __i_1__;
}
