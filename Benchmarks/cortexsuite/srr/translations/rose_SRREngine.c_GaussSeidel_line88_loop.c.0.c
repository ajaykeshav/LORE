#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
  double A[16][16];
  int j;
  double Y[500];
  double X[500];
  int i;
  FILE stderr[500];
  FILE stdout[500];
  FILE stdin[500];
  int __i_0__ = i;
  int __j_1__ = j;
  
#pragma scop
  for (__i_0__ = 0; __i_0__ <= 15; __i_0__ += 1) {{
      X[__i_0__] = Y[__i_0__];
    }
    for (__j_1__ = 0; __j_1__ <= 15; __j_1__ += 1) {
      if (__j_1__ != __i_0__) {
        X[__i_0__] = X[__i_0__] - A[__i_0__][__j_1__] * X[__j_1__];
      }
       else {
      }
    }
  }
  
#pragma endscop
  i = __i_0__;
  j = __j_1__;
  return 0;
}
