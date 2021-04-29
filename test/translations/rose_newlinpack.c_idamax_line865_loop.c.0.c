typedef double REAL;

int main()
{
  int itemp = 8;
  REAL dmax = 9;
  REAL *dx = 12;
  int n = 5;
  int i = 7;
  int signgam = 7;
  int __i_0__ = i;
  
#pragma scop
  for (__i_0__ = 1; __i_0__ <= 136; __i_0__ += 1) {
    if (fabs((double )dx[__i_0__]) > dmax) {
      itemp = __i_0__;
      dmax = fabs((double )dx[__i_0__]);
    }
     else {
    }
  }
  
#pragma endscop
  i = __i_0__;
  return 0;
}
