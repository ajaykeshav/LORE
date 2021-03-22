#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct {
int width;
int height;
float data[];}F2D;

int main()
{
  float val;
  F2D out[500];
  int cols;
  int j;
  int rows;
  int i;
  FILE stderr[500];
  FILE stdout[500];
  FILE stdin[500];
  int __i_0__ = i;
  int __j_1__ = j;
  
#pragma scop
  for (__i_0__ = 0; __i_0__ <= 0; __i_0__ += 1) {
    for (__j_1__ = 0; __j_1__ <= 0; __j_1__ += 1) {
      out -> data[__i_0__ * out -> width + __j_1__] = val;
    }
  }
  
#pragma endscop
  i = __i_0__;
  j = __j_1__;
  return 0;
}
