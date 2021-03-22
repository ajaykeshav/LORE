#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
  double mat2[500];
  double mat1[500][500];
  double result[500];
  int j;
  int i;
  FILE stderr[500];
  FILE stdout[500];
  FILE stdin[500];
  int __i_0__ = i;
  int __j_1__ = j;
  
#pragma scop
{
    for (__i_0__ = 0; __i_0__ <= 15; __i_0__ += 1) {
      for (__j_1__ = 0; __j_1__ <= 15; __j_1__ += 1) {
        result[__i_0__] += mat1[__i_0__][__j_1__] * mat2[__j_1__];
      }
    }
  }
  
#pragma endscop
  i = __i_0__;
  j = __j_1__;
  return 0;
}
