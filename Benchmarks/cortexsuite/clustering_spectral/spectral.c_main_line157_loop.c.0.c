#include <inttypes.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
extern int i;
extern int n;
extern int j;
extern double * __restrict__ A;
extern double * __restrict__ D;

void loop()
{
  int __i_0__ = i;
  int __j_1__ = j;
  
#pragma scop
  for (__i_0__ = 0; __i_0__ <= n - 1; __i_0__ += 1) {
    for (__j_1__ = 0; __j_1__ <= n - 1; __j_1__ += 1) {
      A[n * __i_0__ + __j_1__] = A[n * __i_0__ + __j_1__] / sqrt(D[__i_0__]) / sqrt(D[__j_1__]);
    }
  }
  
#pragma endscop
  i = __i_0__;
  j = __j_1__;
}
