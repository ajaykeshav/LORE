#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
extern int i;
extern int n;
extern double x[2000 + 0];
extern double b[2000 + 0];
extern int j;
extern double L[2000 + 0][2000 + 0];

void loop()
{
  int __i_0__ = i;
  int __j_1__ = j;
  
#pragma scop
{
    for (__i_0__ = 0; __i_0__ <= n - 1; __i_0__ += 1) {
      x[__i_0__] = (- 999);
      b[__i_0__] = __i_0__;
      for (__j_1__ = 0; __j_1__ <= __i_0__; __j_1__ += 1) {
        L[__i_0__][__j_1__] = ((double )(__i_0__ + n - __j_1__ + 1)) * 2 / n;
      }
    }
  }
  
#pragma endscop
  i = __i_0__;
  j = __j_1__;
}
