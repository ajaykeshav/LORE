#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
extern int i;
extern int m;
extern int j;
extern float ** __restrict__ symmat2;
extern float ** __restrict__ symmat;

void loop()
{
  int __i_0__ = i;
  int __j_1__ = j;
  
#pragma scop
{
    for (__i_0__ = 1; __i_0__ <= m; __i_0__ += 1) {
      for (__j_1__ = 1; __j_1__ <= m; __j_1__ += 1) {
        symmat2[__i_0__][__j_1__] = symmat[__i_0__][__j_1__];
      }
    }
  }
  
#pragma endscop
  i = __i_0__;
  j = __j_1__;
}
