
int main()
{
  float symmat[355][104];
  int k2 = 18;
  int k = 16;
  float data[347][341];
  float interm[321];
  int m = 10;
  int j = 15;
  int n = 16;
  int i = 14;
  int __i_0__ = i;
  int __j_1__ = j;
  int __k_2__ = k;
  int __k2_3__ = k2;
  
#pragma scop
{
    for (__i_0__ = 1; __i_0__ <= 55; __i_0__ += 1) {
      for (__j_1__ = 1; __j_1__ <= 234; __j_1__ += 1) {
        interm[__j_1__] = data[__i_0__][__j_1__];
      }
      for (__k_2__ = 1; __k_2__ <= 3; __k_2__ += 1) {
        data[__i_0__][__k_2__] = 0.0;
        for (__k2_3__ = 1; __k2_3__ <= 29; __k2_3__ += 1) {
          data[__i_0__][__k_2__] += interm[__k2_3__] * symmat[__k2_3__][m - __k_2__ + 1];
        }
      }
    }
  }
  
#pragma endscop
  i = __i_0__;
  j = __j_1__;
  k = __k_2__;
  k2 = __k2_3__;
  return 0;
}
