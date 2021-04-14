#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
extern long jt;
extern long n;
extern int tile_size;
extern long it;
extern long j;
extern long i;
extern long jj;
extern double * __restrict__ out;
extern double weight[4 + 1][4 + 1];
extern double * __restrict__ in;
extern long ii;

void loop()
{
  int __jt_0__ = jt;
  int __it_1__ = it;
  int __j_2__ = j;
  int __i_3__ = i;
  int __jj_4__ = jj;
  int __ii_5__ = ii;
  
#pragma scop
  for (__jt_0__ = 2; __jt_0__ <= n - ((long )2) - 1; __jt_0__ += tile_size) {
    for (__it_1__ = 2; __it_1__ <= n - ((long )2) - 1; __it_1__ += tile_size) {
      for (__j_2__ = __jt_0__; __j_2__ <= ((n - ((long )2) < __jt_0__ + ((long )tile_size)?n - ((long )2) : __jt_0__ + ((long )tile_size))) - 1; __j_2__ += 1) {
        for (__i_3__ = __it_1__; __i_3__ <= ((n - ((long )2) < __it_1__ + ((long )tile_size)?n - ((long )2) : __it_1__ + ((long )tile_size))) - 1; __i_3__ += 1) {
          for (__jj_4__ = - 2; __jj_4__ <= 2; __jj_4__ += 1) {
            out[__i_3__ + __j_2__ * n] += weight[0 + 2][__jj_4__ + 2] * in[__i_3__ + (__j_2__ + __jj_4__) * n];
          }
          for (__ii_5__ = - 2; __ii_5__ <= ((long )0) - 1; __ii_5__ += 1) {
            out[__i_3__ + __j_2__ * n] += weight[__ii_5__ + 2][0 + 2] * in[(__i_3__ + __ii_5__) + __j_2__ * n];
          }
          for (__ii_5__ = 1; __ii_5__ <= 2; __ii_5__ += 1) {
            out[__i_3__ + __j_2__ * n] += weight[__ii_5__ + 2][0 + 2] * in[(__i_3__ + __ii_5__) + __j_2__ * n];
          }
        }
      }
    }
  }
  
#pragma endscop
  jt = __jt_0__;
  it = __it_1__;
  j = __j_2__;
  i = __i_3__;
  jj = __jj_4__;
  ii = __ii_5__;
}
