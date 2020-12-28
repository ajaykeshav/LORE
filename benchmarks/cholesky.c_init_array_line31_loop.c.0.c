#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
extern int i;
extern int n;
extern int j;
extern double A[2000 + 0][2000 + 0];

void loop()
{
  int __i_0__ = i;
  int __j_1__ = j;
  
#pragma scop
{
    for (__i_0__ = 0; __i_0__ <= n - 1; __i_0__ += 1) {
      for (__j_1__ = 0; __j_1__ <= __i_0__; __j_1__ += 1) {
        A[__i_0__][__j_1__] = ((double )(-__j_1__ % n)) / n + 1;
      }
      for (__j_1__ = __i_0__ + 1; __j_1__ <= n - 1; __j_1__ += 1) {
        A[__i_0__][__j_1__] = 0;
      }
      A[__i_0__][__i_0__] = 1;
    }
  }
  
#pragma endscop
  i = __i_0__;
  j = __j_1__;
}
