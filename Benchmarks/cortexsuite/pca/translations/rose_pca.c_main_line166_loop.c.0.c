#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
  float symmat[500][500];
  float symmat2[500][500];
  int j;
  int m;
  int i;
  FILE stderr[500];
  FILE stdout[500];
  FILE stdin[500];
  int __i_0__ = i;
  int __j_1__ = j;
  
#pragma scop
{
    for (__i_0__ = 1; __i_0__ <= 500; __i_0__ += 1) {
      for (__j_1__ = 1; __j_1__ <= 500; __j_1__ += 1) {
        symmat2[__i_0__][__j_1__] = symmat[__i_0__][__j_1__];
      }
    }
  }
  
#pragma endscop
  i = __i_0__;
  j = __j_1__;
  return 0;
}
