#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
  int imageIdx;
  unsigned char bitmapImage[500];
  double grayscale[500][500];
  int x;
  int j;
  int y;
  int i;
  FILE stderr[500];
  FILE stdout[500];
  FILE stdin[500];
  int __i_0__ = i;
  int __j_1__ = j;
  
#pragma scop
  for (__i_0__ = 0; __i_0__ <= 500; __i_0__ += 1) {
    for (__j_1__ = 0; __j_1__ <= 500; __j_1__ += 1) {
      grayscale[y - __i_0__ - 1][__j_1__] = ((double )(66 * bitmapImage[imageIdx + 2] + 129 * bitmapImage[imageIdx + 1] + 25 * bitmapImage[imageIdx] + 128 >> 8));
      imageIdx += 3;
    }
  }
  
#pragma endscop
  i = __i_0__;
  j = __j_1__;
  return 0;
}
