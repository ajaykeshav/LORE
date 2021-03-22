#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
extern int i;
extern int col1;
extern int col2;
extern int j;
typedef struct {
int row_dim;
int col_dim;
double *data;
double **cols;}matrix;
typedef matrix *Matrix;
extern  __restrict__ Matrix mat;
extern  __restrict__ Matrix cols;

void loop()
{
  int __i_0__ = i;
  int __j_1__ = j;
  
#pragma scop
  for (__i_0__ = col1; __i_0__ <= col2; __i_0__ += 1) {
    for (__j_1__ = 0; __j_1__ <= mat -> row_dim - 1; __j_1__ += 1) {
      cols -> cols[__i_0__ - col1][__j_1__] = mat -> cols[__i_0__][__j_1__];
    }
  }
  
#pragma endscop
  i = __i_0__;
  j = __j_1__;
}
