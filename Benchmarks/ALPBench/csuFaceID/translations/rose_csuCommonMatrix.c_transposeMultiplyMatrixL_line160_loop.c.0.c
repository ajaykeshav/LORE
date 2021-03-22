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
  matrix P[500];
  int k;
  matrix A[500];
  int i;
  matrix B[500];
  int j;
  FILE stderr[500];
  FILE stdout[500];
  FILE stdin[500];
  int __j_0__ = j;
  int __i_1__ = i;
  int __k_2__ = k;
  
#pragma scop
  for (__j_0__ = 0; __j_0__ <= 500; __j_0__ += 1) {
    for (__i_1__ = 0; __i_1__ <= 500; __i_1__ += 1) {
      for (__k_2__ = 0; __k_2__ <= 500; __k_2__ += 1) {
        P -> cols[__j_0__][__i_1__] += A -> cols[__i_1__][__k_2__] * B -> cols[__j_0__][__k_2__];
      }
    }
  }
  
#pragma endscop
  j = __j_0__;
  i = __i_1__;
  k = __k_2__;
  return 0;
}
