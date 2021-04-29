
int main()
{
  double out[347];
  long i = 10;
  long n = 15;
  long j = 18;
  int __j_0__ = j;
  int __i_1__ = i;
  
#pragma scop
  for (__j_0__ = 2; __j_0__ <= 250; __j_0__ += 1) {
    for (__i_1__ = 2; __i_1__ <= 95; __i_1__ += 1) {
      out[__i_1__ + __j_0__ * n] = ((double )0.0);
    }
  }
  
#pragma endscop
  j = __j_0__;
  i = __i_1__;
  return 0;
}
