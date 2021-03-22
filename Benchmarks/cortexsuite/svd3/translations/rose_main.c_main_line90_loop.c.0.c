#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct {
int width;
int height;
float data[];}F2D;

int main()
{
  F2D v[500];
  F2D u[500];
  int j;
  F2D s[500];
  int i;
  FILE stderr[500];
  FILE stdout[500];
  FILE stdin[500];
  int __i_0__ = i;
  int __j_1__ = j;
  
#pragma scop
  for (__i_0__ = 0; __i_0__ <= 0; __i_0__ += 1) {
    for (__j_1__ = 0; __j_1__ <= 0; __j_1__ += 1) {
      u -> data[__j_1__ * u -> width + __i_0__] = u -> data[__j_1__ * u -> width + __i_0__] * s -> data[0 * s -> width + __i_0__];
    }
    for (__j_1__ = 0; __j_1__ <= 0; __j_1__ += 1) {
      v -> data[__j_1__ * v -> width + __i_0__] = v -> data[__j_1__ * v -> width + __i_0__] * s -> data[0 * s -> width + __i_0__];
    }
  }
  
#pragma endscop
  i = __i_0__;
  j = __j_1__;
  return 0;
}
