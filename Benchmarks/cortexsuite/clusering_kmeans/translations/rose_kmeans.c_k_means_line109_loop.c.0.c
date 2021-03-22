#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
  double c1[500][500];
  int counts[500];
  double c[500][500];
  int m;
  int j;
  int k;
  int i;
  FILE stderr[500];
  FILE stdout[500];
  FILE stdin[500];
  int __i_0__ = i;
  int __j_1__ = j;
  
#pragma scop
{
    for (__i_0__ = 0; __i_0__ <= 500; __i_0__ += 1) {
      for (__j_1__ = 0; __j_1__ <= 500; __j_1__ += 1) {
        c[__i_0__][__j_1__] = (counts[__i_0__]?c1[__i_0__][__j_1__] / counts[__i_0__] : c1[__i_0__][__j_1__]);
      }
    }
  }
  
#pragma endscop
  i = __i_0__;
  j = __j_1__;
  return 0;
}
