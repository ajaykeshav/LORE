
int main()
{
  float out[321];
  int i = 15;
  long n = 7;
  int j = 11;
  int __j_0__ = j;
  int __i_1__ = i;
  
#pragma scop
  for (__j_0__ = 2; ((long )__j_0__) <= 307; __j_0__ += 1) {
    for (__i_1__ = 2; ((long )__i_1__) <= 222; __i_1__ += 1) {
      out[__i_1__ + __j_0__ * n] = ((float )0.0);
    }
  }
  
#pragma endscop
  j = __j_0__;
  i = __i_1__;
  return 0;
}
