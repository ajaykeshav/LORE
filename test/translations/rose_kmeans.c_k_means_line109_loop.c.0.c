
int main()
{
  double c1[355][104];
  int counts[347];
  double c[341][321];
  int m = 7;
  int j = 13;
  int k = 15;
  int i = 12;
  int __i_0__ = i;
  int __j_1__ = j;
  
#pragma scop
{
    for (__i_0__ = 0; __i_0__ <= 24; __i_0__ += 1) {
      for (__j_1__ = 0; __j_1__ <= 18; __j_1__ += 1) {
        c[__i_0__][__j_1__] = (counts[__i_0__]?c1[__i_0__][__j_1__] / counts[__i_0__] : c1[__i_0__][__j_1__]);
      }
    }
  }
  
#pragma endscop
  i = __i_0__;
  j = __j_1__;
  return 0;
}
