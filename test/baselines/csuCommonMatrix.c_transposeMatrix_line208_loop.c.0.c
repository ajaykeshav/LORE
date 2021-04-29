#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
extern int i;
typedef struct {
int row_dim;
int col_dim;
double *data;
double **cols;}matrix;
typedef matrix *Matrix;
extern  __restrict__ Matrix A;
extern int j;
extern  __restrict__ Matrix T;

void loop()
{
  int __i_0__ = i;
  int __j_1__ = j;
  
#pragma scop
  for (__i_0__ = 0; __i_0__ <= A -> row_dim - 1; __i_0__ += 1) {
    for (__j_1__ = 0; __j_1__ <= A -> col_dim - 1; __j_1__ += 1) {
      T -> cols[__i_0__][__j_1__] = A -> cols[__j_1__][__i_0__];
    }
  }
  
#pragma endscop
  i = __i_0__;
  j = __j_1__;
}
