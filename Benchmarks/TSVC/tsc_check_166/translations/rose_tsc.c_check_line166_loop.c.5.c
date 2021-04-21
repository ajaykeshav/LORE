
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
    for (__i_0__ = 0; __i_0__ <= 31999; __i_0__ += 2) {
      suma += a[__i_0__];
{
        suma += a[__i_0__ + 1];
      }
    }
    for (__i_0__ = 0; __i_0__ <= 31999; __i_0__ += 2) {
      sumb += b[__i_0__];
{
        sumb += b[__i_0__ + 1];
      }
    }
    for (__i_0__ = 0; __i_0__ <= 31999; __i_0__ += 2) {
      sumc += c[__i_0__];
{
        sumc += c[__i_0__ + 1];
      }
    }
    for (__i_0__ = 0; __i_0__ <= 31999; __i_0__ += 2) {
      sumd += d[__i_0__];
{
        sumd += d[__i_0__ + 1];
      }
    }
    for (__i_0__ = 0; __i_0__ <= 31999; __i_0__ += 2) {
      sume += e[__i_0__];
{
        sume += e[__i_0__ + 1];
      }
    }
  }
  
#pragma endscop
  i = __i_0__;
  return 0;
}
