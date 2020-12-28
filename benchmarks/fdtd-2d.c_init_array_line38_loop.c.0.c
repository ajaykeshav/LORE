#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
extern int i;
extern int nx;
extern int j;
extern int ny;
extern double ex[1000 + 0][1200 + 0];
extern double ey[1000 + 0][1200 + 0];
extern double hz[1000 + 0][1200 + 0];

void loop()
{
  int __i_0__ = i;
  int __j_1__ = j;
  
#pragma scop
{
    for (__i_0__ = 0; __i_0__ <= nx - 1; __i_0__ += 1) {
      for (__j_1__ = 0; __j_1__ <= ny - 1; __j_1__ += 1) {
        ex[__i_0__][__j_1__] = ((double )__i_0__) * (__j_1__ + 1) / nx;
        ey[__i_0__][__j_1__] = ((double )__i_0__) * (__j_1__ + 2) / ny;
        hz[__i_0__][__j_1__] = ((double )__i_0__) * (__j_1__ + 3) / nx;
      }
    }
  }
  
#pragma endscop
  i = __i_0__;
  j = __j_1__;
}
