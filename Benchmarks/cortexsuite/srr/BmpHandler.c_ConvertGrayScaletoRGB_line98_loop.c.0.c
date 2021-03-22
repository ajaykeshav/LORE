#include <inttypes.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
extern int i;
extern int y;
extern int j;
extern int x;
extern int k;
extern int temp;
extern double *** __restrict__ grayscale;
extern double min;
extern double max;
extern int imageIdx;
extern unsigned char * __restrict__ bitmapImage;

void loop()
{
  int __i_0__ = i;
  int __Yindex_1__;
  int __Xindex_2__;
  int __j_3__ = j;
  int __k_4__ = k;
  
#pragma scop
  for (__i_0__ = 0; __i_0__ <= y - 1; __i_0__ += 1) {
    for (__j_3__ = 0; __j_3__ <= x - 1; __j_3__ += 1) {
      for (__k_4__ = 0; __k_4__ <= 15; __k_4__ += 1) {
        temp = ((int )((grayscale[__i_0__ + 1][__j_3__ + 1][__k_4__] - min) * 255 / (max - min)));
        __Yindex_1__ = __i_0__ * 4 + ((int )(floor(((double )__k_4__) / ((double )4))));
        __Xindex_2__ = __j_3__ * 4 + __k_4__ % 4;
        imageIdx = 3 * (x * 4 * (y * 4 - __Yindex_1__ - 1) + __Xindex_2__);
        bitmapImage[imageIdx + 2] = ((unsigned char )(298 * (temp - 16) + 128 >> 8));
        bitmapImage[imageIdx + 1] = ((unsigned char )(298 * (temp - 16) + 128 >> 8));
        bitmapImage[imageIdx] = ((unsigned char )(298 * (temp - 16) + 128 >> 8));
      }
    }
  }
  
#pragma endscop
  i = __i_0__;
  j = __j_3__;
  k = __k_4__;
}
