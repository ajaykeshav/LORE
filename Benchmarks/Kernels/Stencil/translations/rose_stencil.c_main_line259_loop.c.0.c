#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
  float out[127];
  float norm;
  int i;
  long n;
  int j;
  FILE stderr[138];
  FILE stdout[343];
  FILE stdin[347];
  int __j_0__ = j;
  int __i_1__ = i;
  
#pragma scop
{
    for (__j_0__ = 2; ((long )__j_0__) <= 14; __j_0__ += 1) {
      for (__i_1__ = 2; ((long )__i_1__) <= 125; __i_1__ += 1) {
        norm += ((float )((out[__i_1__ + __j_0__ * n] >= 0?out[__i_1__ + __j_0__ * n] : -out[__i_1__ + __j_0__ * n])));
      }
    }
  }
  
#pragma endscop
  j = __j_0__;
  i = __i_1__;
  return 0;
}
