#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct {
int width;
int height;
int channels;
double ***data;}image;
typedef image *Image;

int main()
{
  double pmin;
  int channel;
  double pmax;
  int y;
  image im[500];
  int x;
  FILE stderr[500];
  FILE stdout[500];
  FILE stdin[500];
  int __x_0__ = x;
  int __y_1__ = y;
  
#pragma scop
  for (__x_0__ = 0; __x_0__ <= 500; __x_0__ += 1) {
    for (__y_1__ = 0; __y_1__ <= 500; __y_1__ += 1) {
      pmax = (im -> data[__x_0__][__y_1__][channel] < pmax?pmax : im -> data[__x_0__][__y_1__][channel]);
      pmin = (im -> data[__x_0__][__y_1__][channel] > pmin?pmin : im -> data[__x_0__][__y_1__][channel]);
    }
  }
  
#pragma endscop
  x = __x_0__;
  y = __y_1__;
  return 0;
}
