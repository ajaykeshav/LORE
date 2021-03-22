#include <inttypes.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
extern int i;
extern int n;
extern int j;
extern int m;
extern float ** __restrict__ data;
extern float * __restrict__ mean;
extern float x;
extern float * __restrict__ stddev;

void loop()
{
  int __i_0__ = i;
  int __j_1__ = j;
  
#pragma scop
  for (__i_0__ = 1; __i_0__ <= n; __i_0__ += 1) {
    for (__j_1__ = 1; __j_1__ <= m; __j_1__ += 1) {
      data[__i_0__][__j_1__] -= mean[__j_1__];
      x = (sqrt(((float )n)));
      x *= stddev[__j_1__];
      data[__i_0__][__j_1__] /= x;
    }
  }
  
#pragma endscop
  i = __i_0__;
  j = __j_1__;
}
