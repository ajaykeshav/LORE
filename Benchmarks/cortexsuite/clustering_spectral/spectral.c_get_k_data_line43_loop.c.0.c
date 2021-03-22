#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
extern int i;
extern int k;
extern double min;
extern int j;
extern int n;
extern int * __restrict__ check;
extern double * __restrict__ ev;
extern int index;
extern int l;
extern double ** __restrict__ k_data;
extern double * __restrict__ A;

void loop()
{
  int __i_0__ = i;
  int __j_1__ = j;
  int __l_2__ = l;
  
#pragma scop
  for (__i_0__ = 0; __i_0__ <= k - 1; __i_0__ += 1) {{
      min = 1.7976931348623157e+308;
    }
    for (__j_1__ = 0; __j_1__ <= n - 1; __j_1__ += 1) {
      if (check[__j_1__]) {
        continue; 
      }
       else {
        if (ev[__j_1__] < min) {
          min = ev[__j_1__];
          index = __j_1__;
        }
         else {
        }
      }
    }{
      check[index] = 1;
    }
    for (__l_2__ = 0; __l_2__ <= n - 1; __l_2__ += 1) {
      k_data[__l_2__][__i_0__] = A[__l_2__ * n + index];
    }
  }
  
#pragma endscop
  i = __i_0__;
  j = __j_1__;
  l = __l_2__;
}
