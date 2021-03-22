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
  matrix mean[500];
  int classEnd;
  int classStart;
  int j;
  matrix classmatrix[500];
  int i;
  FILE stderr[500];
  FILE stdout[500];
  FILE stdin[500];
  int __i_0__ = i;
  int __j_1__ = j;
  
#pragma scop
  for (__i_0__ = 0; __i_0__ <= 500; __i_0__ += 1) {
    for (__j_1__ = classStart; __j_1__ <= 500; __j_1__ += 1) {
      classmatrix -> cols[__j_1__][__i_0__] -= mean -> cols[0][__i_0__];
    }
  }
  
#pragma endscop
  i = __i_0__;
  j = __j_1__;
  return 0;
}
