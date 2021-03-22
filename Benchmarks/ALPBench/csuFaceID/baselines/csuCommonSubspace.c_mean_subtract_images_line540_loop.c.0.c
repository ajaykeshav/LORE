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
extern  __restrict__ Matrix images;
extern int j;
extern  __restrict__ Matrix mean;

void loop()
{
  int __i_0__ = i;
  int __j_1__ = j;
  
#pragma scop
  for (__i_0__ = 0; __i_0__ <= images -> row_dim - 1; __i_0__ += 1) {
    for (__j_1__ = 0; __j_1__ <= images -> col_dim - 1; __j_1__ += 1) {
      images -> cols[__j_1__][__i_0__] -= mean -> cols[0][__i_0__];
    }
  }
  
#pragma endscop
  i = __i_0__;
  j = __j_1__;
}
