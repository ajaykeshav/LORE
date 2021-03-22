#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
extern int i;
typedef struct {
int width;
int height;
float data[];}F2D;
extern F2D * __restrict__ s;
extern int j;
extern F2D * __restrict__ u;
extern F2D * __restrict__ v;

void loop()
{
  int __i_0__ = i;
  int __j_1__ = j;
  
#pragma scop
  for (__i_0__ = 0; __i_0__ <= s -> width - 1; __i_0__ += 1) {
    for (__j_1__ = 0; __j_1__ <= u -> height - 1; __j_1__ += 1) {
      u -> data[__j_1__ * u -> width + __i_0__] = u -> data[__j_1__ * u -> width + __i_0__] * s -> data[0 * s -> width + __i_0__];
    }
    for (__j_1__ = 0; __j_1__ <= v -> height - 1; __j_1__ += 1) {
      v -> data[__j_1__ * v -> width + __i_0__] = v -> data[__j_1__ * v -> width + __i_0__] * s -> data[0 * s -> width + __i_0__];
    }
  }
  
#pragma endscop
  i = __i_0__;
  j = __j_1__;
}
