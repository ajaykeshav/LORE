#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
  double C[286];
  double B[228];
  double A[127];
  int i;
  int order;
  int j;
  FILE stderr[138];
  FILE stdout[343];
  FILE stdin[347];
  int __j_0__ = j;
  int __i_1__ = i;
  
#pragma scop
  for (__j_0__ = 0; __j_0__ <= 81; __j_0__ += 1) {
    for (__i_1__ = 0; __i_1__ <= 49; __i_1__ += 1) {
      A[__i_1__ + order * __j_0__] = B[__i_1__ + order * __j_0__] = ((double )__j_0__);
      C[__i_1__ + order * __j_0__] = 0.0;
    }
  }
  
#pragma endscop
  j = __j_0__;
  i = __i_1__;
  return 0;
}
