
int main()
{
  double C4[160][160];
  double A[150][140][160];
  int s = 15;
  double sum[160];
  int np = 15;
  int p = 14;
  int nq = 12;
  int q = 16;
  int nr = 9;
  int r = 10;
  int __r_0__ = r;
  int __q_1__ = q;
  int __p_2__ = p;
  int __s_3__ = s;
  
#pragma scop
{
    for (__r_0__ = 0; __r_0__ <= 45; __r_0__ += 1) {
      for (__q_1__ = 0; __q_1__ <= 135; __q_1__ += 1) {
        for (__p_2__ = 0; __p_2__ <= 127; __p_2__ += 1) {
          sum[__p_2__] = 0.0;
          for (__s_3__ = 0; __s_3__ <= 132; __s_3__ += 1) {
            sum[__p_2__] += A[__r_0__][__q_1__][__s_3__] * C4[__s_3__][__p_2__];
          }
        }
        for (__p_2__ = 0; __p_2__ <= 41; __p_2__ += 1) {
          A[__r_0__][__q_1__][__p_2__] = sum[__p_2__];
        }
      }
    }
  }
  
#pragma endscop
  r = __r_0__;
  q = __q_1__;
  p = __p_2__;
  s = __s_3__;
  return 0;
}
