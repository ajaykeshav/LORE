typedef double REAL;

int main()
{
  int lda = 2;
  REAL a[341];
  REAL b[321];
  int i = 15;
  int n = 10;
  int j = 11;
  int __j_0__ = j;
  int __i_1__ = i;
  
#pragma scop
  for (__j_0__ = 0; __j_0__ <= 220; __j_0__ += 1) {
    for (__i_1__ = 0; __i_1__ <= 200; __i_1__ += 1) {
      b[__i_1__] = b[__i_1__] + a[lda * __j_0__ + __i_1__];
    }
  }
  
#pragma endscop
  j = __j_0__;
  i = __i_1__;
  return 0;
}
