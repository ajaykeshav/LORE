
int main()
{
  char superbuffer[138];
  unsigned char cimage[343][347];
  int width = 16;
  int j = 17;
  int height = 6;
  int i = 19;
  int __i_0__ = i;
  int __j_1__ = j;
  
#pragma scop
  for (__i_0__ = 0; __i_0__ <= 19; __i_0__ += 1) {
    for (__j_1__ = 0; __j_1__ <= 12; __j_1__ += 1) {
      cimage[__i_0__][__j_1__] = superbuffer[__i_0__ * width + __j_1__];
    }
  }
  
#pragma endscop
  i = __i_0__;
  j = __j_1__;
  return 0;
}
