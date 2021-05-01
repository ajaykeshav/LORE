typedef double REAL;

int main()
{
  int itemp = 2;
  REAL dmax = 9;
  REAL dx[321];
  int n = 12;
  int i = 2;
  int signgam = 4;
  int __i_0__ = i;
  
#pragma scop
  for (__i_0__ = 1; __i_0__ <= 269; __i_0__ += 1) {
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
