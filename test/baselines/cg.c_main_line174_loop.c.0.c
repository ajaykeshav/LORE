#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
extern int j;
extern int lastrow;
extern int firstrow;
extern int k;
extern int rowstr[14000 + 1 + 1];
extern int colidx[14000 * (11 + 1) * (11 + 1) + 14000 * (11 + 2) + 1];
extern int firstcol;

void loop()
{
  int __j_0__ = j;
  int __k_1__ = k;
  
#pragma scop
  for (__j_0__ = 1; __j_0__ <= lastrow - firstrow + 1; __j_0__ += 1) {
    for (__k_1__ = rowstr[__j_0__]; __k_1__ <= rowstr[__j_0__ + 1] - 1; __k_1__ += 1) {
      colidx[__k_1__] = colidx[__k_1__] - firstcol + 1;
    }
  }
  
#pragma endscop
  j = __j_0__;
  k = __k_1__;
}
