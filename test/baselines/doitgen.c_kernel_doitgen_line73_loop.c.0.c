#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
extern int r;
extern int nr;
extern int q;
extern int nq;
extern int p;
extern int np;
extern double sum[160 + 0];
extern int s;
extern double A[150 + 0][140 + 0][160 + 0];
extern double C4[160 + 0][160 + 0];

void loop()
{
  int __r_0__ = r;
  int __q_1__ = q;
  int __p_2__ = p;
  int __s_3__ = s;
  
#pragma scop
{
    for (__r_0__ = 0; __r_0__ <= nr - 1; __r_0__ += 1) {
      for (__q_1__ = 0; __q_1__ <= nq - 1; __q_1__ += 1) {
        for (__p_2__ = 0; __p_2__ <= np - 1; __p_2__ += 1) {
          sum[__p_2__] = 0.0;
          for (__s_3__ = 0; __s_3__ <= np - 1; __s_3__ += 1) {
            sum[__p_2__] += A[__r_0__][__q_1__][__s_3__] * C4[__s_3__][__p_2__];
          }
        }
        for (__p_2__ = 0; __p_2__ <= np - 1; __p_2__ += 1) {
          A[__r_0__][__q_1__][__p_2__] = sum[__p_2__];
        }
      }
    }
  }
  
#pragma endscop
  r = __r_0__;
  q = __q_1__;
  p = __p_2__;
  s = __s_3__;
}
