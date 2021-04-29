
int main()
{
  float out[347];
  int i = 19;
  long n = 16;
  int j = 17;
  int __j_0__ = j;
  int __i_1__ = i;
  
#pragma scop
  for (__j_0__ = 2; ((long )__j_0__) <= 320; __j_0__ += 1) {
    for (__i_1__ = 2; ((long )__i_1__) <= 155; __i_1__ += 1) {
      out[__i_1__ + __j_0__ * n] = ((float )0.0);
    }
  }
  
#pragma endscop
  j = __j_0__;
  i = __i_1__;
  return 0;
}
