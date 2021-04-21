#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
extern float suma;
extern float a[32000];
extern float sumb;
extern float b[32000];
extern float sumc;
extern float c[32000];
extern float sumd;
extern float d[32000];
extern float sume;
extern float e[32000];

void loop()
{
  int i;
  int __i_0__ = i;
  
#pragma scop
{
    int _lt_var___i_0__;
    for (_lt_var___i_0__ = 0; _lt_var___i_0__ <= 31999; _lt_var___i_0__ += 32) {
/* iter_count = (ub-lb+1)%step ==0?(ub-lb+1)/step: (ub-lb+1)/step+1; */
/* fringe = iter_count%unroll_factor==0 ? 0:unroll_factor*step */
      int _lu_fringe_55 = ((((((31999 < (_lt_var___i_0__ + 32 - 1))?31999 : (_lt_var___i_0__ + 32 - 1))) + 1 - _lt_var___i_0__) % 1 == 0?((((31999 < (_lt_var___i_0__ + 32 - 1))?31999 : (_lt_var___i_0__ + 32 - 1))) + 1 - _lt_var___i_0__) / 1 : ((((31999 < (_lt_var___i_0__ + 32 - 1))?31999 : (_lt_var___i_0__ + 32 - 1))) + 1 - _lt_var___i_0__) / 1 + 1)) % 2 == 0?0 : 2;
      for (__i_0__ = _lt_var___i_0__; __i_0__ <= (((31999 < (_lt_var___i_0__ + 32 - 1))?31999 : (_lt_var___i_0__ + 32 - 1))) - _lu_fringe_55; __i_0__ += 2) {
        suma += a[__i_0__];
        sumb += b[__i_0__];
        sumc += c[__i_0__];
        sumd += d[__i_0__];
        sume += e[__i_0__];
{
          suma += a[__i_0__ + 1];
          sumb += b[__i_0__ + 1];
          sumc += c[__i_0__ + 1];
          sumd += d[__i_0__ + 1];
          sume += e[__i_0__ + 1];
        }
      }
      for (; __i_0__ <= (((31999 < (_lt_var___i_0__ + 32 - 1))?31999 : (_lt_var___i_0__ + 32 - 1))); __i_0__ += 1) {
        suma += a[__i_0__];
        sumb += b[__i_0__];
        sumc += c[__i_0__];
        sumd += d[__i_0__];
        sume += e[__i_0__];
      }
    }
  }
  
#pragma endscop
  i = __i_0__;
}
