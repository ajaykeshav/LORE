#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
extern int j;
extern int m;
extern float * __restrict__ mean;
extern int i;
extern int n;
extern float ** __restrict__ data;

void loop()
{
  int __j_0__ = j;
  int __i_1__ = i;
  
#pragma scop
{
    for (__j_0__ = 1; __j_0__ <= m; __j_0__ += 1) {
      mean[__j_0__] = 0.0;
      for (__i_1__ = 1; __i_1__ <= n; __i_1__ += 1) {
        mean[__j_0__] += data[__i_1__][__j_0__];
      }
      mean[__j_0__] /= ((float )n);
    }
  }
  
#pragma endscop
  j = __j_0__;
  i = __i_1__;
}
