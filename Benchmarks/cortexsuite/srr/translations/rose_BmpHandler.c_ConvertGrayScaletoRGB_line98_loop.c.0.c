#include <inttypes.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
  unsigned char bitmapImage[500];
  int imageIdx;
  double max;
  double min;
  double *grayscale[500][500];
  int temp;
  int k;
  int x;
  int j;
  int y;
  int i;
  FILE stderr[500];
  FILE stdout[500];
  FILE stdin[500];
  int signgam;
  int __i_0__ = i;
  int __Yindex_1__;
  int __Xindex_2__;
  int __j_3__ = j;
  int __k_4__ = k;
  
#pragma scop
  for (__i_0__ = 0; __i_0__ <= 500; __i_0__ += 1) {
    for (__j_3__ = 0; __j_3__ <= 500; __j_3__ += 1) {
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
  return 0;
}
