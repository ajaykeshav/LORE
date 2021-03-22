#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
extern int i;
extern int k;
extern int j;
extern int m;
extern double ** __restrict__ c;
extern int * __restrict__ counts;
extern double ** __restrict__ c1;

void loop()
{
  int __i_0__ = i;
  int __j_1__ = j;
  
#pragma scop
{
    for (__i_0__ = 0; __i_0__ <= k - 1; __i_0__ += 1) {
      for (__j_1__ = 0; __j_1__ <= m - 1; __j_1__ += 1) {
        c[__i_0__][__j_1__] = (counts[__i_0__]?c1[__i_0__][__j_1__] / counts[__i_0__] : c1[__i_0__][__j_1__]);
      }
    }
  }
  
#pragma endscop
  i = __i_0__;
  j = __j_1__;
}
