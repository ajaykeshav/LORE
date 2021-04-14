#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
extern int j;
extern long n;
extern int i;
extern float * __restrict__ in;

void loop()
{
  int __j_0__ = j;
  int __i_1__ = i;
  
#pragma scop
  for (__j_0__ = 0; ((long )__j_0__) <= n - 1; __j_0__ += 1) {
    for (__i_1__ = 0; ((long )__i_1__) <= n - 1; __i_1__ += 1) {
      in[__i_1__ + __j_0__ * n] = 1.0f * __i_1__ + 1.0f * __j_0__;
    }
  }
  
#pragma endscop
  j = __j_0__;
  i = __i_1__;
}
