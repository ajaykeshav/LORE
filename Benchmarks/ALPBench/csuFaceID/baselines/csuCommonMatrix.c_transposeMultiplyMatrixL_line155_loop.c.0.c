#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
extern int j;
typedef struct {
int row_dim;
int col_dim;
double *data;
double **cols;}matrix;
typedef matrix *Matrix;
extern  __restrict__ Matrix B;
extern int i;
extern  __restrict__ Matrix A;
extern  __restrict__ Matrix P;

void loop()
{
  int __j_0__ = j;
  int __i_1__ = i;
  
#pragma scop
  for (__j_0__ = 0; __j_0__ <= B -> col_dim - 1; __j_0__ += 1) {
    for (__i_1__ = 0; __i_1__ <= A -> col_dim - 1; __i_1__ += 1) {
      P -> cols[__j_0__][__i_1__] = 0;
    }
  }
  
#pragma endscop
  j = __j_0__;
  i = __i_1__;
}
