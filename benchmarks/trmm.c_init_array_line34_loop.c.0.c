#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
extern int i;
extern int m;
extern int j;
extern double A[1000 + 0][1000 + 0];
extern int n;
extern double B[1000 + 0][1200 + 0];

void loop()
{
  int __i_0__ = i;
  int __j_1__ = j;
  
#pragma scop
{
    for (__i_0__ = 0; __i_0__ <= m - 1; __i_0__ += 1) {
      for (__j_1__ = 0; __j_1__ <= __i_0__ - 1; __j_1__ += 1) {
        A[__i_0__][__j_1__] = ((double )((__i_0__ + __j_1__) % m)) / m;
      }
      A[__i_0__][__i_0__] = 1.0;
      for (__j_1__ = 0; __j_1__ <= n - 1; __j_1__ += 1) {
        B[__i_0__][__j_1__] = ((double )((n + (__i_0__ - __j_1__)) % n)) / n;
      }
    }
  }
  
#pragma endscop
  i = __i_0__;
  j = __j_1__;
}
