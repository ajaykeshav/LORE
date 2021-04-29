#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
extern int i;
extern int ni;
extern int j;
extern int nj;
extern double C[1000 + 0][1100 + 0];

void loop()
{
  int __i_0__ = i;
  int __j_1__ = j;
  
#pragma scop
{
    for (__i_0__ = 0; __i_0__ <= ni - 1; __i_0__ += 1) {
      for (__j_1__ = 0; __j_1__ <= nj - 1; __j_1__ += 1) {
        C[__i_0__][__j_1__] = ((double )(__i_0__ * __j_1__ % ni)) / ni;
      }
    }
  }
  
#pragma endscop
  i = __i_0__;
  j = __j_1__;
}
