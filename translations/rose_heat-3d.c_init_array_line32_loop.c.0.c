#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
  double B[120][120][120];
  double A[120][120][120];
  int k;
  int j;
  int n;
  int i;
  FILE stderr[500];
  FILE stdout[500];
  FILE stdin[500];
  int __i_0__ = i;
  int __j_1__ = j;
  int __k_2__ = k;
  
#pragma scop
  for (__i_0__ = 0; __i_0__ <= 120; __i_0__ += 1) {
    for (__j_1__ = 0; __j_1__ <= 120; __j_1__ += 1) {
      for (__k_2__ = 0; __k_2__ <= 120; __k_2__ += 1) {
        A[__i_0__][__j_1__][__k_2__] = B[__i_0__][__j_1__][__k_2__] = ((double )(__i_0__ + __j_1__ + (n - __k_2__))) * 10 / n;
      }
    }
  }
  
#pragma endscop
  i = __i_0__;
  j = __j_1__;
  k = __k_2__;
  return 0;
}
