#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
extern int i;
extern double * __restrict__ Y;
extern double A[4 * 4][4 * 4];
extern int j;

void loop()
{
  int __i_0__ = i;
  int __j_1__ = j;
  
#pragma scop
  for (__i_0__ = 0; __i_0__ <= 15; __i_0__ += 1) {{
      Y[__i_0__] = Y[__i_0__] / A[__i_0__][__i_0__];
    }
    for (__j_1__ = 0; __j_1__ <= 15; __j_1__ += 1) {
      if (__i_0__ != __j_1__) {
        A[__i_0__][__j_1__] = ((double )A[__i_0__][__j_1__]) / ((double )A[__i_0__][__i_0__]);
      }
       else {
      }
    }
  }
  
#pragma endscop
  i = __i_0__;
  j = __j_1__;
}
