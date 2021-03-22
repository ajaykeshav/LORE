#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
extern int x;
typedef struct {
int width;
int height;
int channels;
double ***data;}image;
typedef image *Image;
extern  __restrict__ Image im;
extern int y;
extern double pmax;
extern int channel;
extern double pmin;

void loop()
{
  int __x_0__ = x;
  int __y_1__ = y;
  
#pragma scop
  for (__x_0__ = 0; __x_0__ <= im -> width - 1; __x_0__ += 1) {
    for (__y_1__ = 0; __y_1__ <= im -> height - 1; __y_1__ += 1) {
      pmax = (im -> data[__x_0__][__y_1__][channel] < pmax?pmax : im -> data[__x_0__][__y_1__][channel]);
      pmin = (im -> data[__x_0__][__y_1__][channel] > pmin?pmin : im -> data[__x_0__][__y_1__][channel]);
    }
  }
  
#pragma endscop
  x = __x_0__;
  y = __y_1__;
}
