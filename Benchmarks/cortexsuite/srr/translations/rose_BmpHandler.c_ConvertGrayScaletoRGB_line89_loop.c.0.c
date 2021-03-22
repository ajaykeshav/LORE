#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
  double min;
  double max;
  double *grayscale[500][500];
  int k;
  int x;
  int j;
  int y;
  int i;
  FILE stderr[500];
  FILE stdout[500];
  FILE stdin[500];
  int __i_0__ = i;
  int __j_1__ = j;
  int __k_2__ = k;
  
#pragma scop
  for (__i_0__ = 0; __i_0__ <= 500; __i_0__ += 1) {
    for (__j_1__ = 0; __j_1__ <= 500; __j_1__ += 1) {
      for (__k_2__ = 0; __k_2__ <= 15; __k_2__ += 1) {
        if (grayscale[__i_0__ + 1][__j_1__][__k_2__] > max) {
          max = grayscale[__i_0__ + 1][__j_1__][__k_2__];
        }
         else {
        }
        if (grayscale[__i_0__ + 1][__j_1__][__k_2__] < min) {
          min = grayscale[__i_0__ + 1][__j_1__][__k_2__];
        }
         else {
        }
      }
    }
  }
  
#pragma endscop
  i = __i_0__;
  j = __j_1__;
  k = __k_2__;
  return 0;
}
