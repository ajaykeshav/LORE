#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
typedef float real;

int main()
{
  int vec;
  int vectors[321][286];
  real Tmatrix[228][127];
  int col;
  int NNTOT;
  int row;
  FILE stderr[138];
  FILE stdout[343];
  FILE stdin[347];
  int __row_0__ = row;
  int __col_1__ = col;
  
#pragma scop
  for (__row_0__ = 0; __row_0__ <= 43; __row_0__ += 1) {
    for (__col_1__ = 0; __col_1__ <= 119; __col_1__ += 1) {
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
  return 0;
}
