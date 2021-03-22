#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
  float data[500][500];
  int n;
  int i;
  float mean[500];
  int m;
  int j;
  FILE stderr[500];
  FILE stdout[500];
  FILE stdin[500];
  int __j_0__ = j;
  int __i_1__ = i;
  
#pragma scop
{
    for (__j_0__ = 1; __j_0__ <= 500; __j_0__ += 1) {
      mean[__j_0__] = 0.0;
      for (__i_1__ = 1; __i_1__ <= 500; __i_1__ += 1) {
        mean[__j_0__] += data[__i_1__][__j_0__];
      }
      mean[__j_0__] /= ((float )n);
    }
  }
  
#pragma endscop
  j = __j_0__;
  i = __i_1__;
  return 0;
}
