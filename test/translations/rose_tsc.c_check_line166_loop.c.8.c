
int main()
{
  float e[32000];
  float sume = 4;
  float d[32000];
  float sumd = 19;
  float c[32000];
  float sumc = 15;
  float b[32000];
  float sumb = 3;
  float a[32000];
  float suma = 16;
  int i;
  int __i_0__ = i;
  
#pragma scop
{
    int _lt_var___i_0__;
    for (_lt_var___i_0__ = 0; _lt_var___i_0__ <= 31999; _lt_var___i_0__ += 8) {
      for (__i_0__ = _lt_var___i_0__; __i_0__ <= 315; __i_0__ += 1) {
        suma += a[__i_0__];
        sumb += b[__i_0__];
        sumc += c[__i_0__];
        sumd += d[__i_0__];
        sume += e[__i_0__];
      }
    }
  }
  
#pragma endscop
  i = __i_0__;
  return 0;
}
