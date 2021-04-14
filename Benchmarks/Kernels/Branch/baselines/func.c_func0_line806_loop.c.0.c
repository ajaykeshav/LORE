#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
extern int j;
extern int i;
extern int b[10][10];
extern int a[10][10];

void loop()
{
  int __j_0__ = j;
  int __i_1__ = i;
  
#pragma scop
{
    for (__j_0__ = 0; __j_0__ <= 9; __j_0__ += 1) {
      for (__i_1__ = 0; __i_1__ <= 9; __i_1__ += 1) {
        b[__j_0__][__i_1__] = (a[__i_1__][__j_0__] + a[__j_0__][__i_1__]) / 2;
      }
    }
  }
  
#pragma endscop
  j = __j_0__;
  i = __i_1__;
}
