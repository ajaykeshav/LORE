#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
extern int i;
extern int j;
extern double * __restrict__ result;
extern double ** __restrict__ mat1;
extern double * __restrict__ mat2;

void loop()
{
  int __i_0__ = i;
  int __j_1__ = j;
  
#pragma scop
{
    for (__i_0__ = 0; __i_0__ <= 15; __i_0__ += 1) {
      for (__j_1__ = 0; __j_1__ <= 15; __j_1__ += 1) {
        result[__i_0__] += mat1[__i_0__][__j_1__] * mat2[__j_1__];
      }
    }
  }
  
#pragma endscop
  i = __i_0__;
  j = __j_1__;
}
