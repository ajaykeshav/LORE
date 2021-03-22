#include <inttypes.h>
#include <math.h>
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
  double inv_len;
  int j;
  double sumsqr;
  matrix eigenvectors[500];
  int i;
  FILE stderr[500];
  FILE stdout[500];
  FILE stdin[500];
  int signgam;
  int __i_0__ = i;
  int __j_1__ = j;
  
#pragma scop
  for (__i_0__ = 0; __i_0__ <= 500; __i_0__ += 1) {{
      sumsqr = 0.0;
    }
    for (__j_1__ = 0; __j_1__ <= 500; __j_1__ += 1) {
      sumsqr += eigenvectors -> cols[__i_0__][__j_1__] * eigenvectors -> cols[__i_0__][__j_1__];
    }
    if (sumsqr != 0) {
      inv_len = 1.0 / sqrt(sumsqr);
    }
     else {
      inv_len = 0;
    }
    for (__j_1__ = 0; __j_1__ <= 500; __j_1__ += 1) {
      eigenvectors -> cols[__i_0__][__j_1__] *= inv_len;
    }
  }
  
#pragma endscop
  i = __i_0__;
  j = __j_1__;
  return 0;
}
