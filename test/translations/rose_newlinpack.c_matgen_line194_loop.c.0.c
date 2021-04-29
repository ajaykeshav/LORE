typedef double REAL;

int main()
{
  int lda = 14;
  REAL *a = 5;
  REAL *b = 5;
  int i = 9;
  int n = 18;
  int j = 8;
  int __j_0__ = j;
  int __i_1__ = i;
  
#pragma scop
  for (__j_0__ = 0; __j_0__ <= 6; __j_0__ += 1) {
    for (__i_1__ = 0; __i_1__ <= 358; __i_1__ += 1) {
      b[__i_1__] = b[__i_1__] + a[lda * __j_0__ + __i_1__];
    }
  }
  
#pragma endscop
  j = __j_0__;
  i = __i_1__;
  return 0;
}
