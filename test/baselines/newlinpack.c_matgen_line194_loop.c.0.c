#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
extern int j;
extern int n;
extern int i;
typedef double REAL;
extern REAL * __restrict__ b;
extern REAL * __restrict__ a;
extern int lda;

void loop()
{
  int __j_0__ = j;
  int __i_1__ = i;
  
#pragma scop
  for (__j_0__ = 0; __j_0__ <= n - 1; __j_0__ += 1) {
    for (__i_1__ = 0; __i_1__ <= n - 1; __i_1__ += 1) {
      b[__i_1__] = b[__i_1__] + a[lda * __j_0__ + __i_1__];
    }
  }
  
#pragma endscop
  j = __j_0__;
  i = __i_1__;
}
