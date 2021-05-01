
int main()
{
  char superbuffer[347];
  unsigned char cimage[341][321];
  int width = 2;
  int j = 17;
  int height = 19;
  int i = 12;
  int __i_0__ = i;
  int __j_1__ = j;
  
#pragma scop
  for (__i_0__ = 0; __i_0__ <= 139; __i_0__ += 1) {
    for (__j_1__ = 0; __j_1__ <= 49; __j_1__ += 1) {
      cimage[__i_0__][__j_1__] = superbuffer[__i_0__ * width + __j_1__];
    }
  }
  
#pragma endscop
  i = __i_0__;
  j = __j_1__;
  return 0;
}
