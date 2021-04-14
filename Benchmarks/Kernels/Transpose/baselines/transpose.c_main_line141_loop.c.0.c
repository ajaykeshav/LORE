#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
extern int j;
extern int order;
extern int i;
extern double * __restrict__ B_p;

void loop()
{
  int __j_0__ = j;
  int __i_1__ = i;
  
#pragma scop
  for (__j_0__ = 0; __j_0__ <= order - 1; __j_0__ += 1) {
    for (__i_1__ = 0; __i_1__ <= order - 1; __i_1__ += 1) {
      B_p[__i_1__ + order * __j_0__] = - 1.0;
    }
  }
  
#pragma endscop
  j = __j_0__;
  i = __i_1__;
}
