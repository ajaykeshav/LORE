#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
  double hz[1000][1200];
  double ey[1000][1200];
  double ex[1000][1200];
  int ny;
  int j;
  int nx;
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
        ex[__i_0__][__j_1__] = ((double )__i_0__) * (__j_1__ + 1) / nx;
        ey[__i_0__][__j_1__] = ((double )__i_0__) * (__j_1__ + 2) / ny;
        hz[__i_0__][__j_1__] = ((double )__i_0__) * (__j_1__ + 3) / nx;
      }
    }
  }
  
#pragma endscop
  i = __i_0__;
  j = __j_1__;
  return 0;
}
