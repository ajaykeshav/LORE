#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
extern int i;
extern int height;
extern int j;
extern int width;
extern unsigned char ** __restrict__ cimage;
extern char * __restrict__ superbuffer;

void loop()
{
  int __i_0__ = i;
  int __j_1__ = j;
  
#pragma scop
  for (__i_0__ = 0; __i_0__ <= height - 1; __i_0__ += 1) {
    for (__j_1__ = 0; __j_1__ <= width - 1; __j_1__ += 1) {
      cimage[__i_0__][__j_1__] = superbuffer[__i_0__ * width + __j_1__];
    }
  }
  
#pragma endscop
  i = __i_0__;
  j = __j_1__;
}
