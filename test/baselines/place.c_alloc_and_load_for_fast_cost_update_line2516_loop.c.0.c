#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
extern int high;
extern int ny;
extern float ** __restrict__ chanx_place_cost_fac;
extern int * __restrict__ chan_width_x;
extern int low;

void loop()
{
  int __high_0__ = high;
  int __low_1__ = low;
  
#pragma scop
{
    for (__high_0__ = 1; __high_0__ <= ny; __high_0__ += 1) {
      chanx_place_cost_fac[__high_0__][__high_0__] = chan_width_x[__high_0__];
      for (__low_1__ = 0; __low_1__ <= __high_0__ - 1; __low_1__ += 1) {
        chanx_place_cost_fac[__high_0__][__low_1__] = chanx_place_cost_fac[__high_0__ - 1][__low_1__] + chan_width_x[__high_0__];
      }
    }
  }
  
#pragma endscop
  high = __high_0__;
  low = __low_1__;
}
