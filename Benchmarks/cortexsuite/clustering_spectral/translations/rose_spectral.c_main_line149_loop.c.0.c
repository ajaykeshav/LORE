#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
  double A[500];
  double D[500];
  int j;
  int n;
  int i;
  FILE stderr[500];
  FILE stdout[500];
  FILE stdin[500];
  int __i_0__ = i;
  int __j_1__ = j;
  
#pragma scop
  for (__i_0__ = 0; __i_0__ <= 500; __i_0__ += 1) {
    for (__j_1__ = 0; __j_1__ <= 500; __j_1__ += 1) {
      D[__i_0__] += -A[n * __i_0__ + __j_1__];
    }
    A[n * __i_0__ + __i_0__] = D[__i_0__];
  }
  
#pragma endscop
  i = __i_0__;
  j = __j_1__;
  return 0;
}
