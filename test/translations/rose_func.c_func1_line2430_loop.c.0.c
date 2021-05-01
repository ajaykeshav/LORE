
int main()
{
  int a[10][10];
  int b[10][10];
  int i = 6;
  int j = 10;
  int __j_0__ = j;
  int __i_1__ = i;
  
#pragma scop
{
    for (__j_0__ = 0; __j_0__ <= 9; __j_0__ += 1) {
      for (__i_1__ = 0; __i_1__ <= 9; __i_1__ += 1) {
        b[__j_0__][__i_1__] = (a[__i_1__][__j_0__] + a[__j_0__][__i_1__]) / 2;
      }
    }
  }
  
#pragma endscop
  j = __j_0__;
  i = __i_1__;
  return 0;
}
