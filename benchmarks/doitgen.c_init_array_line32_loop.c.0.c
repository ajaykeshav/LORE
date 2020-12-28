#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
extern int i;
extern int nr;
extern int j;
extern int nq;
extern int k;
extern int np;
extern double A[150 + 0][140 + 0][160 + 0];

void loop()
{
  int __i_0__ = i;
  int __j_1__ = j;
  int __k_2__ = k;
  
#pragma scop
{
    for (__i_0__ = 0; __i_0__ <= nr - 1; __i_0__ += 1) {
      for (__j_1__ = 0; __j_1__ <= nq - 1; __j_1__ += 1) {
        for (__k_2__ = 0; __k_2__ <= np - 1; __k_2__ += 1) {
          A[__i_0__][__j_1__][__k_2__] = ((double )((__i_0__ * __j_1__ + __k_2__) % np)) / np;
        }
      }
    }
  }
  
#pragma endscop
  i = __i_0__;
  j = __j_1__;
  k = __k_2__;
}
