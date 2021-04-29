#include <inttypes.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
extern int i;
extern int n;
typedef double REAL;
extern REAL * __restrict__ dx;
extern REAL dmax;
extern int itemp;

void loop()
{
  int __i_0__ = i;
  
#pragma scop
  for (__i_0__ = 1; __i_0__ <= n - 1; __i_0__ += 1) {
    if (fabs(((double )dx[__i_0__])) > dmax) {
      itemp = __i_0__;
      dmax = fabs(((double )dx[__i_0__]));
    }
     else {
    }
  }
  
#pragma endscop
  i = __i_0__;
}
