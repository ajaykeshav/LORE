#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct {
int row_dim;
int col_dim;
double *data;
double **cols;}matrix;
typedef matrix *Matrix;

int main()
{
  matrix cols[500];
  matrix mat[500];
  int j;
  int col2;
  int col1;
  int i;
  FILE stderr[500];
  FILE stdout[500];
  FILE stdin[500];
  int __i_0__ = i;
  int __j_1__ = j;
  
#pragma scop
  for (__i_0__ = col1; __i_0__ <= 500; __i_0__ += 1) {
    for (__j_1__ = 0; __j_1__ <= 500; __j_1__ += 1) {
      cols -> cols[__i_0__ - col1][__j_1__] = mat -> cols[__i_0__][__j_1__];
    }
  }
  
#pragma endscop
  i = __i_0__;
  j = __j_1__;
  return 0;
}
