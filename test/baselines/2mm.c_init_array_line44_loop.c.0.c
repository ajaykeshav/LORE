#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
extern int i;
extern int nj;
extern int j;
extern int nl;
extern double C[900 + 0][1200 + 0];

void loop()
{
  int __i_0__ = i;
  int __j_1__ = j;
  
#pragma scop
{
    for (__i_0__ = 0; __i_0__ <= nj - 1; __i_0__ += 1) {
      for (__j_1__ = 0; __j_1__ <= nl - 1; __j_1__ += 1) {
        C[__i_0__][__j_1__] = ((double )(__i_0__ * (__j_1__ + 3) % nl)) / nl;
      }
    }
  }
  
#pragma endscop
  i = __i_0__;
  j = __j_1__;
}
