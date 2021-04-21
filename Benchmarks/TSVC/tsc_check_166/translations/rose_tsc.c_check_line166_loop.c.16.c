
int main()
{
  float e[32000];
  float sume;
  float d[32000];
  float sumd;
  float c[32000];
  float sumc;
  float b[32000];
  float sumb;
  float a[32000];
  float suma;
  int i;
  int __i_0__ = i;
  
#pragma scop
{
    int _lt_var___i_0__;
    for (_lt_var___i_0__ = 0; _lt_var___i_0__ <= 31999; _lt_var___i_0__ += 16) {
      for (__i_0__ = _lt_var___i_0__; __i_0__ <= 71; __i_0__ += 1) {
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
