#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
extern int k;
typedef short word;
extern word * __restrict__ s;
typedef long longword;

void loop()
{
  int __k_0__ = k;
  
#pragma scop
{
    for (__k_0__ = 0; __k_0__ <= 159; __k_0__ += 1) {
      s[__k_0__] = (((longword )s[__k_0__]) * ((longword )(16384 >> 1 - 1)) + 16384 >> 15);
    }
  }
  
#pragma endscop
  k = __k_0__;
}
