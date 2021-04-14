#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
typedef float real;

int main()
{
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
{
    for (__row_0__ = 0; __row_0__ <= 65; __row_0__ += 1) {
      for (__col_1__ = 0; __col_1__ <= 90; __col_1__ += 1) {
        Tmatrix[__row_0__][__col_1__] = 0.0;
      }
    }
  }
  
#pragma endscop
  row = __row_0__;
  col = __col_1__;
  return 0;
}
