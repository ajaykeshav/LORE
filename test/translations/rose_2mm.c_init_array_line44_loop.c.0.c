
int main()
{
  double C[900][1200];
  int nl = 14;
  int j = 16;
  int nj = 2;
  int i = 10;
  int __i_0__ = i;
  int __j_1__ = j;
  
#pragma scop
{
    for (__i_0__ = 0; __i_0__ <= 77; __i_0__ += 1) {
      for (__j_1__ = 0; __j_1__ <= 301; __j_1__ += 1) {
        C[__i_0__][__j_1__] = ((double )(__i_0__ * (__j_1__ + 3) % nl)) / nl;
      }
    }
  }
  
#pragma endscop
  i = __i_0__;
  j = __j_1__;
  return 0;
}
