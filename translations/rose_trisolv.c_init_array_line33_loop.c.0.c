#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
  double L[2000][2000];
  int j;
  double b[2000];
  double x[2000];
  int n;
  int i;
  FILE stderr[500];
  FILE stdout[500];
  FILE stdin[500];
  int __i_0__ = i;
  int __j_1__ = j;
  
#pragma scop
{
    for (__i_0__ = 0; __i_0__ <= 2000; __i_0__ += 1) {
      x[__i_0__] = (- 999);
      b[__i_0__] = __i_0__;
      for (__j_1__ = 0; __j_1__ <= 2000; __j_1__ += 1) {
        L[__i_0__][__j_1__] = ((double )(__i_0__ + n - __j_1__ + 1)) * 2 / n;
      }
    }
  }
  
#pragma endscop
  i = __i_0__;
  j = __j_1__;
  return 0;
}
