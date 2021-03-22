#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
extern int i;
extern int rows;
extern int j;
extern int cols;
typedef struct {
int width;
int height;
float data[];}F2D;
extern F2D * __restrict__ out;
extern F2D * __restrict__ in;

void loop()
{
  int __i_0__ = i;
  int __j_1__ = j;
  
#pragma scop
  for (__i_0__ = 0; __i_0__ <= rows - 1; __i_0__ += 1) {
    for (__j_1__ = 0; __j_1__ <= cols - 1; __j_1__ += 1) {
      out -> data[__i_0__ * out -> width + __j_1__] = in -> data[__i_0__ * in -> width + __j_1__];
    }
  }
  
#pragma endscop
  i = __i_0__;
  j = __j_1__;
}
