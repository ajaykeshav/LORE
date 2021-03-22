#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
extern int i;
extern int y;
extern int j;
extern int x;
extern double ** __restrict__ grayscale;
extern unsigned char * __restrict__ bitmapImage;
extern int imageIdx;

void loop()
{
  int __i_0__ = i;
  int __j_1__ = j;
  
#pragma scop
  for (__i_0__ = 0; __i_0__ <= y - 1; __i_0__ += 1) {
    for (__j_1__ = 0; __j_1__ <= x - 1; __j_1__ += 1) {
      grayscale[y - __i_0__ - 1][__j_1__] = ((double )(66 * bitmapImage[imageIdx + 2] + 129 * bitmapImage[imageIdx + 1] + 25 * bitmapImage[imageIdx] + 128 >> 8));
      imageIdx += 3;
    }
  }
  
#pragma endscop
  i = __i_0__;
  j = __j_1__;
}
