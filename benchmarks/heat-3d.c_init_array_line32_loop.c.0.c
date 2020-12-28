#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
extern int i;
extern int n;
extern int j;
extern int k;
extern double A[120 + 0][120 + 0][120 + 0];
extern double B[120 + 0][120 + 0][120 + 0];

void loop()
{
  int __i_0__ = i;
  int __j_1__ = j;
  int __k_2__ = k;
  
#pragma scop
  for (__i_0__ = 0; __i_0__ <= n - 1; __i_0__ += 1) {
    for (__j_1__ = 0; __j_1__ <= n - 1; __j_1__ += 1) {
      for (__k_2__ = 0; __k_2__ <= n - 1; __k_2__ += 1) {
        A[__i_0__][__j_1__][__k_2__] = B[__i_0__][__j_1__][__k_2__] = ((double )(__i_0__ + __j_1__ + (n - __k_2__))) * 10 / n;
      }
    }
  }
  
#pragma endscop
  i = __i_0__;
  j = __j_1__;
  k = __k_2__;
}
