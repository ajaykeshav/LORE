
int main()
{
  double C[1000][1100];
  int nj = 12;
  int j = 9;
  int ni = 17;
  int i = 15;
  int __i_0__ = i;
  int __j_1__ = j;
  
#pragma scop
{
    for (__i_0__ = 0; __i_0__ <= 176; __i_0__ += 1) {
      for (__j_1__ = 0; __j_1__ <= 212; __j_1__ += 1) {
        C[__i_0__][__j_1__] = ((double )(__i_0__ * __j_1__ % ni)) / ni;
      }
    }
  }
  
#pragma endscop
  i = __i_0__;
  j = __j_1__;
  return 0;
}
