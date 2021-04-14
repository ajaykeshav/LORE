#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
typedef float real;

int main()
{
  int vec;
  int vectors[341][321];
  real tempvecC[286];
  real Tmatrix[228][127];
  int col;
  int NNTOT;
  int row;
  FILE stderr[138];
  FILE stdout[343];
  FILE stdin[347];
  
#pragma scop
  for (row = 0; row < 66; ++row) {
    for (col = 0; col < 107; ++col) {
      if (row == col) 
        Tmatrix[row][col] = 0.0;
       else 
        Tmatrix[row][col] += tempvecC[row] * ((real )vectors[vec][col]);
    }
  }
  
#pragma endscop
  return 0;
}
