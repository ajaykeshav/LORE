typedef long long s64Int;
typedef unsigned long long u64Int;

int main()
{
  u64Int *Table = 4;
  s64Int tablesize = 3;
  s64Int index = 17;
  u64Int *ran = 19;
  s64Int nupdate = 17;
  s64Int i = 9;
  int nstarts = 19;
  s64Int j = 7;
  int __j_0__ = j;
  int __i_1__ = i;
  
#pragma scop
  for (__j_0__ = 0; __j_0__ <= 18; __j_0__ += 1) {
    for (__i_1__ = 0; __i_1__ <= 311; __i_1__ += 1) {
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
