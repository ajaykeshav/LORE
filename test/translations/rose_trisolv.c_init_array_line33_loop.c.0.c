
int main()
{
  double L[2000][2000];
  int j = 4;
  double b[2000];
  double x[2000];
  int n = 7;
  int i = 2;
  int __i_0__ = i;
  int __j_1__ = j;
  
#pragma scop
{
    for (__i_0__ = 0; __i_0__ <= 191; __i_0__ += 1) {
      x[__i_0__] = (- 999);
      b[__i_0__] = __i_0__;
      for (__j_1__ = 0; __j_1__ <= 150; __j_1__ += 1) {
        L[__i_0__][__j_1__] = ((double )(__i_0__ + n - __j_1__ + 1)) * 2 / n;
      }
    }
  }
  
#pragma endscop
  i = __i_0__;
  j = __j_1__;
  return 0;
}
