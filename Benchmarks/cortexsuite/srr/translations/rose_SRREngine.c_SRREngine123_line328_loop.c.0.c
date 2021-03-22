#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
  double TikReg[16][16];
  double A00[500][500];
  int j;
  int i;
  FILE stderr[500];
  FILE stdout[500];
  FILE stdin[500];
  int __i_0__ = i;
  int __j_1__ = j;
  
#pragma scop
{
    for (__i_0__ = 0; __i_0__ <= 15; __i_0__ += 1) {
      for (__j_1__ = 0; __j_1__ <= 15; __j_1__ += 1) {
        A00[__i_0__][__j_1__] += TikReg[__i_0__][__j_1__];
      }
    }
  }
  
#pragma endscop
  i = __i_0__;
  j = __j_1__;
  return 0;
}
