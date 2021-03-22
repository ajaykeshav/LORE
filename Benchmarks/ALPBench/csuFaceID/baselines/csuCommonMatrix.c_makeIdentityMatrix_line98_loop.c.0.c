#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
extern int i;
extern int dim;
extern int j;
typedef struct {
int row_dim;
int col_dim;
double *data;
double **cols;}matrix;
typedef matrix *Matrix;
extern  __restrict__ Matrix I;

void loop()
{
  int __i_0__ = i;
  int __j_1__ = j;
  
#pragma scop
  for (__i_0__ = 0; __i_0__ <= dim - 1; __i_0__ += 1) {
    for (__j_1__ = 0; __j_1__ <= dim - 1; __j_1__ += 1) {
      I -> cols[__j_1__][__i_0__] = (__i_0__ == __j_1__);
    }
  }
  
#pragma endscop
  i = __i_0__;
  j = __j_1__;
}
