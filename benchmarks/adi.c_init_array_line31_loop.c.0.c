#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
extern int i;
extern int n;
extern int j;
extern double u[1000 + 0][1000 + 0];

void loop()
{
  int __i_0__ = i;
  int __j_1__ = j;
  
#pragma scop
{
    for (__i_0__ = 0; __i_0__ <= n - 1; __i_0__ += 1) {
      for (__j_1__ = 0; __j_1__ <= n - 1; __j_1__ += 1) {
        u[__i_0__][__j_1__] = ((double )(__i_0__ + n - __j_1__)) / n;
      }
    }
  }
  
#pragma endscop
  i = __i_0__;
  j = __j_1__;
}
