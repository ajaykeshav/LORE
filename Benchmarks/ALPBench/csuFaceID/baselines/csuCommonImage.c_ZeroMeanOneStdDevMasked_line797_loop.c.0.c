#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
extern int j;
typedef struct {
int width;
int height;
int channels;
double ***data;}image;
typedef image *Image;
extern  __restrict__ Image im;
extern int i;
extern int c;
extern char ** __restrict__ mask;
extern double mean;
extern double invlength;

void loop()
{
  int __j_0__ = j;
  int __i_1__ = i;
  int __c_2__ = c;
  
#pragma scop
  for (__j_0__ = 0; __j_0__ <= im -> height - 1; __j_0__ += 1) {
    for (__i_1__ = 0; __i_1__ <= im -> width - 1; __i_1__ += 1) {
      for (__c_2__ = 0; __c_2__ <= im -> channels - 1; __c_2__ += 1) {
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
}
