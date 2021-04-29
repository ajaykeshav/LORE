
int main()
{
  double c1[228][127];
  int counts[138];
  double c[343][347];
  int m = 17;
  int j = 10;
  int k = 7;
  int i = 12;
  int __i_0__ = i;
  int __j_1__ = j;
  
#pragma scop
{
    for (__i_0__ = 0; __i_0__ <= 72; __i_0__ += 1) {
      for (__j_1__ = 0; __j_1__ <= 85; __j_1__ += 1) {
        c[__i_0__][__j_1__] = (counts[__i_0__]?c1[__i_0__][__j_1__] / counts[__i_0__] : c1[__i_0__][__j_1__]);
      }
    }
  }
  
#pragma endscop
  i = __i_0__;
  j = __j_1__;
  return 0;
}
