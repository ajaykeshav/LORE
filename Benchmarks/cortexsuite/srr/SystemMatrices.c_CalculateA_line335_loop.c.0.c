#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
extern int i;
extern int j;
extern double ** __restrict__ A00;
extern double temp1[4 * 4][4 * 4];
extern double temp2[4 * 4][4 * 4];
extern double temp3[4 * 4][4 * 4];
extern double temp4[4 * 4][4 * 4];

void loop()
{
  int __i_0__ = i;
  int __j_1__ = j;
  
#pragma scop
{
    for (__i_0__ = 0; __i_0__ <= 15; __i_0__ += 1) {
      for (__j_1__ = 0; __j_1__ <= 15; __j_1__ += 1) {
        A00[__i_0__][__j_1__] += temp1[__i_0__][__j_1__] + temp2[__i_0__][__j_1__] + temp3[__i_0__][__j_1__] + temp4[__i_0__][__j_1__];
      }
    }
  }
  
#pragma endscop
  i = __i_0__;
  j = __j_1__;
}
