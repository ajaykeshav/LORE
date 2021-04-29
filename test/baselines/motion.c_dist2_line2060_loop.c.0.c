#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
extern int j;
extern int h;
extern int i;
extern int v;
extern unsigned char * __restrict__ p1;
extern unsigned char * __restrict__ p2;
extern int s;
extern int lx;

void loop()
{
  int __j_0__ = j;
  int __i_1__ = i;
  
#pragma scop
{
    for (__j_0__ = 0; __j_0__ <= h - 1; __j_0__ += 1) {
      for (__i_1__ = 0; __i_1__ <= 15; __i_1__ += 1) {
        v = ((((unsigned int )(p1[__i_1__] + p1[__i_1__ + 1] + 1)) >> 1) - p2[__i_1__]);
        s += v * v;
      }
      p1 += lx;
      p2 += lx;
    }
  }
  
#pragma endscop
  j = __j_0__;
  i = __i_1__;
}
