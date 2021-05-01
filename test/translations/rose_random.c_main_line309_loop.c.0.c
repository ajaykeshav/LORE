typedef long long s64Int;
typedef unsigned long long u64Int;

int main()
{
  u64Int Table[341];
  s64Int tablesize = 4;
  s64Int index = 14;
  u64Int ran[321];
  s64Int nupdate = 15;
  s64Int i = 11;
  int nstarts = 18;
  s64Int j = 18;
  int __j_0__ = j;
  int __i_1__ = i;
  
#pragma scop
  for (__j_0__ = 0; __j_0__ <= 219; __j_0__ += 1) {
    for (__i_1__ = 0; __i_1__ <= 21; __i_1__ += 1) {
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
