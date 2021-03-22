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
  double invlength;
  double mean;
  char mask[500][500];
  int c;
  int i;
  image im[500];
  int j;
  FILE stderr[500];
  FILE stdout[500];
  FILE stdin[500];
  int __j_0__ = j;
  int __i_1__ = i;
  int __c_2__ = c;
  
#pragma scop
  for (__j_0__ = 0; __j_0__ <= 500; __j_0__ += 1) {
    for (__i_1__ = 0; __i_1__ <= 500; __i_1__ += 1) {
      for (__c_2__ = 0; __c_2__ <= 500; __c_2__ += 1) {
        if (!mask || mask[__i_1__][__j_0__]) {
          im -> data[__i_1__][__j_0__][__c_2__] = (im -> data[__i_1__][__j_0__][__c_2__] - mean) * invlength;
        }
         else {
          im -> data[__i_1__][__j_0__][__c_2__] = 0.0;
        }
      }
    }
  }
  
#pragma endscop
  j = __j_0__;
  i = __i_1__;
  c = __c_2__;
  return 0;
}
