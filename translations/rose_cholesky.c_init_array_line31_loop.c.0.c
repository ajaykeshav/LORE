#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
  double A[2000][2000];
  int j;
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
      for (__j_1__ = 0; __j_1__ <= 2000; __j_1__ += 1) {
        A[__i_0__][__j_1__] = ((double )(-__j_1__ % n)) / n + 1;
      }
      for (__j_1__ = __i_0__ + 1; __j_1__ <= 2000; __j_1__ += 1) {
        A[__i_0__][__j_1__] = 0;
      }
      A[__i_0__][__i_0__] = 1;
    }
  }
  
#pragma endscop
  i = __i_0__;
  j = __j_1__;
  return 0;
}
