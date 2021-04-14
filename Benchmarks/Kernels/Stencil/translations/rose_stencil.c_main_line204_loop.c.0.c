#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
  float in[127];
  int i;
  long n;
  int j;
  FILE stderr[138];
  FILE stdout[343];
  FILE stdin[347];
  int __j_0__ = j;
  int __i_1__ = i;
  
#pragma scop
  for (__j_0__ = 0; ((long )__j_0__) <= 62; __j_0__ += 1) {
    for (__i_1__ = 0; ((long )__i_1__) <= 13; __i_1__ += 1) {
      in[__i_1__ + __j_0__ * n] = 1.0f * __i_1__ + 1.0f * __j_0__;
    }
  }
  
#pragma endscop
  j = __j_0__;
  i = __i_1__;
  return 0;
}
