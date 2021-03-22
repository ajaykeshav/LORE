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
  double totalPixels;
  double maxVal;
  double minVal;
  char mask[500][500];
  int c;
  int y;
  image im[500];
  int x;
  FILE stderr[500];
  FILE stdout[500];
  FILE stdin[500];
  int __x_0__ = x;
  int __y_1__ = y;
  int __c_2__ = c;
  
#pragma scop
  for (__x_0__ = 0; __x_0__ <= 500; __x_0__ += 1) {
    for (__y_1__ = 0; __y_1__ <= 500; __y_1__ += 1) {
      for (__c_2__ = 0; __c_2__ <= 500; __c_2__ += 1) {
        if (!mask || mask[__x_0__][__y_1__]) {
          minVal = (minVal > im -> data[__x_0__][__y_1__][__c_2__]?im -> data[__x_0__][__y_1__][__c_2__] : minVal);
          maxVal = (maxVal < im -> data[__x_0__][__y_1__][__c_2__]?im -> data[__x_0__][__y_1__][__c_2__] : maxVal);
          totalPixels += 1;
        }
         else {
        }
      }
    }
  }
  
#pragma endscop
  x = __x_0__;
  y = __y_1__;
  c = __c_2__;
  return 0;
}
