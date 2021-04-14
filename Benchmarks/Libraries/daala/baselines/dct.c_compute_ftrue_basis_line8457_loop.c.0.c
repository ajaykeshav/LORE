#include <inttypes.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
extern int j;
extern int n;
extern int i;
extern double basis[1 << 2 + 5 - 1][1 << 2 + 5 - 1];

void loop()
{
  int __j_0__ = j;
  int __i_1__ = i;
  
#pragma scop
  for (__j_0__ = 0; __j_0__ <= n - 1; __j_0__ += 1) {
    for (__i_1__ = 0; __i_1__ <= n - 1; __i_1__ += 1) {
      basis[__j_0__][__i_1__] = sqrt(2.0 / n) * cos((__i_1__ + 0.5) * __j_0__ * 3.14159265358979323846 / n);
      if (__j_0__ == 0) {
        basis[__j_0__][__i_1__] *= 0.70710678118654752440;
      }
       else {
      }
    }
  }
  
#pragma endscop
  j = __j_0__;
  i = __i_1__;
}
