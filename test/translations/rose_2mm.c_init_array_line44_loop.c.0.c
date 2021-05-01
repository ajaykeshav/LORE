
int main()
{
  double C[900][1200];
  int nl = 5;
  int j = 19;
  int nj = 17;
  int i = 5;
  int __i_0__ = i;
  int __j_1__ = j;
  
#pragma scop
{
    for (__i_0__ = 0; __i_0__ <= 210; __i_0__ += 1) {
      for (__j_1__ = 0; __j_1__ <= 277; __j_1__ += 1) {
        C[__i_0__][__j_1__] = ((double )(__i_0__ * (__j_1__ + 3) % nl)) / nl;
      }
    }
  }
  
#pragma endscop
  i = __i_0__;
  j = __j_1__;
  return 0;
}
