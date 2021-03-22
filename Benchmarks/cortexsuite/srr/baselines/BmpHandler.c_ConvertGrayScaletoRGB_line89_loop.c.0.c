#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
extern int i;
extern int y;
extern int j;
extern int x;
extern int k;
extern double *** __restrict__ grayscale;
extern double max;
extern double min;

void loop()
{
  int __i_0__ = i;
  int __j_1__ = j;
  int __k_2__ = k;
  
#pragma scop
  for (__i_0__ = 0; __i_0__ <= y - 1; __i_0__ += 1) {
    for (__j_1__ = 0; __j_1__ <= x - 1; __j_1__ += 1) {
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
}
