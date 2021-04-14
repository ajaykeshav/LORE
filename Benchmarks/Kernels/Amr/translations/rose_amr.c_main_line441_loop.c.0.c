#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
  long ii;
  double in[228];
  double weight[5][5];
  double out[127];
  long jj;
  long i;
  long n;
  long j;
  FILE stderr[138];
  FILE stdout[343];
  FILE stdin[347];
  int __j_0__ = j;
  int __i_1__ = i;
  int __jj_2__ = jj;
  int __ii_3__ = ii;
  
#pragma scop
  for (__j_0__ = 2; __j_0__ <= 3; __j_0__ += 1) {
    for (__i_1__ = 2; __i_1__ <= 3; __i_1__ += 1) {
      for (__jj_2__ = - 2; __jj_2__ <= 2; __jj_2__ += 1) {
        out[__i_1__ + __j_0__ * n] += weight[0 + 2][__jj_2__ + 2] * in[__i_1__ + (__j_0__ + __jj_2__) * n];
      }
      for (__ii_3__ = - 2; __ii_3__ <= 1; __ii_3__ += 1) {
        out[__i_1__ + __j_0__ * n] += weight[__ii_3__ + 2][0 + 2] * in[(__i_1__ + __ii_3__) + __j_0__ * n];
      }
      for (__ii_3__ = 1; __ii_3__ <= 2; __ii_3__ += 1) {
        out[__i_1__ + __j_0__ * n] += weight[__ii_3__ + 2][0 + 2] * in[(__i_1__ + __ii_3__) + __j_0__ * n];
      }
    }
  }
  
#pragma endscop
  j = __j_0__;
  i = __i_1__;
  jj = __jj_2__;
  ii = __ii_3__;
  return 0;
}
