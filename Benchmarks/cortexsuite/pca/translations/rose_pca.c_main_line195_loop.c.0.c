#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
  float symmat[500][500];
  int k2;
  int k;
  float data[500][500];
  float interm[500];
  int m;
  int j;
  int n;
  int i;
  FILE stderr[500];
  FILE stdout[500];
  FILE stdin[500];
  int __i_0__ = i;
  int __j_1__ = j;
  int __k_2__ = k;
  int __k2_3__ = k2;
  
#pragma scop
{
    for (__i_0__ = 1; __i_0__ <= 500; __i_0__ += 1) {
      for (__j_1__ = 1; __j_1__ <= 500; __j_1__ += 1) {
        interm[__j_1__] = data[__i_0__][__j_1__];
      }
      for (__k_2__ = 1; __k_2__ <= 3; __k_2__ += 1) {
        data[__i_0__][__k_2__] = 0.0;
        for (__k2_3__ = 1; __k2_3__ <= 500; __k2_3__ += 1) {
          data[__i_0__][__k_2__] += interm[__k2_3__] * symmat[__k2_3__][m - __k_2__ + 1];
        }
      }
    }
  }
  
#pragma endscop
  i = __i_0__;
  j = __j_1__;
  k = __k_2__;
  k2 = __k2_3__;
  return 0;
}
