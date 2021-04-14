#include <inttypes.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
  double basis[64][64];
  int i;
  int n;
  int j;
  FILE stderr[138];
  FILE stdout[343];
  FILE stdin[347];
  int signgam;
  int __j_0__ = j;
  int __i_1__ = i;
  
#pragma scop
  for (__j_0__ = 0; __j_0__ <= 15; __j_0__ += 1) {
    for (__i_1__ = 0; __i_1__ <= 60; __i_1__ += 1) {
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
  return 0;
}
