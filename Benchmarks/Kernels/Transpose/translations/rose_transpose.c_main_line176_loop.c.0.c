#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
  double B_p[127];
  double abserr;
  int i;
  int order;
  int j;
  FILE stderr[138];
  FILE stdout[343];
  FILE stdin[347];
  int __j_0__ = j;
  int __i_1__ = i;
  
#pragma scop
{
    for (__j_0__ = 0; __j_0__ <= 44; __j_0__ += 1) {
      for (__i_1__ = 0; __i_1__ <= 93; __i_1__ += 1) {
        abserr += (B_p[__i_1__ + order * __j_0__] - ((double )(order * __i_1__ + __j_0__)) >= 0?B_p[__i_1__ + order * __j_0__] - ((double )(order * __i_1__ + __j_0__)) : -(B_p[__i_1__ + order * __j_0__] - ((double )(order * __i_1__ + __j_0__))));
      }
    }
  }
  
#pragma endscop
  j = __j_0__;
  i = __i_1__;
  return 0;
}
