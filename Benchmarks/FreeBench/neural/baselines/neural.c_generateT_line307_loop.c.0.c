#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
extern int row;
extern int NNTOT;
extern int col;
typedef float real;
extern real ** __restrict__ Tmatrix;
extern int ** __restrict__ vectors;
extern int vec;

void loop()
{
  int __row_0__ = row;
  int __col_1__ = col;
  
#pragma scop
  for (__row_0__ = 0; __row_0__ <= NNTOT - 1; __row_0__ += 1) {
    for (__col_1__ = 0; __col_1__ <= NNTOT - 1; __col_1__ += 1) {
      if (__row_0__ == __col_1__) {
        Tmatrix[__row_0__][__col_1__] = 0.0;
      }
       else {
        Tmatrix[__row_0__][__col_1__] += (vectors[vec][__row_0__] * vectors[vec][__col_1__]);
      }
    }
  }
  
#pragma endscop
  row = __row_0__;
  col = __col_1__;
}
