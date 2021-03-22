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
extern  __restrict__ Matrix classmatrix;
extern  __restrict__ Matrix mean;
extern int j;
extern int classStart;
extern int classEnd;

void loop()
{
  int __i_0__ = i;
  int __j_1__ = j;
  
#pragma scop
  for (__i_0__ = 0; __i_0__ <= classmatrix -> row_dim - 1; __i_0__ += 1) {
    mean -> cols[0][__i_0__] = 0.0;
    for (__j_1__ = classStart; __j_1__ <= classEnd; __j_1__ += 1) {
      mean -> cols[0][__i_0__] += classmatrix -> cols[__j_1__][__i_0__];
    }
    mean -> cols[0][__i_0__] = mean -> cols[0][__i_0__] / (classEnd - classStart + 1);
  }
  
#pragma endscop
  i = __i_0__;
  j = __j_1__;
}
