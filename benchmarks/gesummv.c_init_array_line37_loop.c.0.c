extern int i;
extern int n;
extern double x[1300 + 0];
extern int j;
extern double A[1300 + 0][1300 + 0];
extern double B[1300 + 0][1300 + 0];

void loop()
{
  int __i_0__ = i;
  int __j_1__ = j;
  
#pragma scop
{
    for (__i_0__ = 0; __i_0__ <= n - 1; __i_0__ += 1) {
      x[__i_0__] = ((double )(__i_0__ % n)) / n;
      for (__j_1__ = 0; __j_1__ <= n - 1; __j_1__ += 1) {
        A[__i_0__][__j_1__] = ((double )(__i_0__ * __j_1__ % n)) / n;
        B[__i_0__][__j_1__] = ((double )(__i_0__ * __j_1__ % n)) / n;
      }
    }
  }
  
#pragma endscop
  i = __i_0__;
  j = __j_1__;
}
