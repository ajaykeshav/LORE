#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
  double tbasis[64][64];
  double basis[64][64];
  double e[64][64];
  double ret;
  int j;
  int n;
  int i;
  FILE stderr[138];
  FILE stdout[343];
  FILE stdin[347];
  int __i_0__ = i;
  int __j_1__ = j;
  
#pragma scop
{
    for (__i_0__ = 0; __i_0__ <= 51; __i_0__ += 1) {
      for (__j_1__ = 0; __j_1__ <= 56; __j_1__ += 1) {
        ret += e[__i_0__][__j_1__] * (basis[__i_0__][__j_1__] - tbasis[__i_0__][__j_1__]);
      }
    }
  }
  
#pragma endscop
  i = __i_0__;
  j = __j_1__;
  return 0;
}
