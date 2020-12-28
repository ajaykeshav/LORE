#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
  double u[1000][1000];
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
    for (__i_0__ = 0; __i_0__ <= 1000; __i_0__ += 1) {
      for (__j_1__ = 0; __j_1__ <= 1000; __j_1__ += 1) {
        u[__i_0__][__j_1__] = ((double )(__i_0__ + n - __j_1__)) / n;
      }
    }
  }
  
#pragma endscop
  i = __i_0__;
  j = __j_1__;
  return 0;
}
