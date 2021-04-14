#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
typedef long long s64Int;
typedef unsigned long long u64Int;

int main()
{
  u64Int Table[228];
  s64Int tablesize;
  s64Int index;
  u64Int ran[127];
  s64Int nupdate;
  s64Int i;
  int nstarts;
  s64Int j;
  FILE stderr[138];
  FILE stdout[343];
  FILE stdin[347];
  int __j_0__ = j;
  int __i_1__ = i;
  
#pragma scop
  for (__j_0__ = 0; __j_0__ <= 84; __j_0__ += 1) {
    for (__i_1__ = 0; __i_1__ <= 12; __i_1__ += 1) {
      ran[__j_0__] = ran[__j_0__] << 1 ^ ((((s64Int )ran[__j_0__]) < 0?0x0000000000000007ULL : 0));
      index = (ran[__j_0__] & (tablesize - 1));
      Table[index] ^= ran[__j_0__];
    }
  }
  
#pragma endscop
  j = __j_0__;
  i = __i_1__;
  return 0;
}
