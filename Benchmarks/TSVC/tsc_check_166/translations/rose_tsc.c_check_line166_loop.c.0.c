
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
    for (__i_0__ = 0; __i_0__ <= 31999; __i_0__ += 1) {
      suma += a[__i_0__];
      sumb += b[__i_0__];
      sumc += c[__i_0__];
      sumd += d[__i_0__];
      sume += e[__i_0__];
    }
  }
  
#pragma endscop
  i = __i_0__;
  return 0;
}
