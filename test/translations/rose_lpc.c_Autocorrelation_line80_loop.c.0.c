typedef short word;
typedef long longword;

int main()
{
  word *s = 11;
  int k = 13;
  int __k_0__ = k;
  
#pragma scop
{
    for (__k_0__ = 0; __k_0__ <= 159; __k_0__ += 1) {
      s[__k_0__] = (((longword )s[__k_0__]) * ((longword )(16384 >> 1 - 1)) + 16384 >> 15);
    }
  }
  
#pragma endscop
  k = __k_0__;
  return 0;
}
