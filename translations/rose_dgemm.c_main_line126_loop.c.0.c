#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
  double C[500];
  double B[500];
  double A[500];
  int i;
  int order;
  int j;
  FILE stderr[500];
  FILE stdout[500];
  FILE stdin[500];
  int __j_0__ = j;
  int __i_1__ = i;
  
#pragma scop
  for (__j_0__ = 0; __j_0__ <= 500; __j_0__ += 1) {
    for (__i_1__ = 0; __i_1__ <= 500; __i_1__ += 1) {
      A[__i_1__ + order * __j_0__] = B[__i_1__ + order * __j_0__] = ((double )__j_0__);
      C[__i_1__ + order * __j_0__] = 0.0;
    }
  }
  
#pragma endscop
  j = __j_0__;
  i = __i_1__;
  return 0;
}
