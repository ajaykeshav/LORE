#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
typedef long long s64Int;
extern s64Int j;
extern int nstarts;
extern s64Int i;
extern s64Int nupdate;
typedef unsigned long long u64Int;
extern u64Int * __restrict__ ran;
extern s64Int index;
extern s64Int tablesize;
extern u64Int * __restrict__ Table;

void loop()
{
  int __j_0__ = j;
  int __i_1__ = i;
  
#pragma scop
  for (__j_0__ = 0; __j_0__ <= ((long long )nstarts) - 1; __j_0__ += 1) {
    for (__i_1__ = 0; __i_1__ <= nupdate / ((long long )(nstarts * 2)) - 1; __i_1__ += 1) {
      ran[__j_0__] = ran[__j_0__] << 1 ^ ((((s64Int )ran[__j_0__]) < 0?0x0000000000000007ULL : 0));
      index = (ran[__j_0__] & (tablesize - 1));
      Table[index] ^= ran[__j_0__];
    }
  }
  
#pragma endscop
  j = __j_0__;
  i = __i_1__;
}
