
int main()
{
  int imageIdx = 18;
  unsigned char bitmapImage[138];
  double grayscale[343][347];
  int x = 13;
  int j = 17;
  int y = 6;
  int i = 8;
  int __i_0__ = i;
  int __j_1__ = j;
  
#pragma scop
  for (__i_0__ = 0; __i_0__ <= 102; __i_0__ += 1) {
    for (__j_1__ = 0; __j_1__ <= 76; __j_1__ += 1) {
      grayscale[y - __i_0__ - 1][__j_1__] = ((double )(66 * bitmapImage[imageIdx + 2] + 129 * bitmapImage[imageIdx + 1] + 25 * bitmapImage[imageIdx] + 128 >> 8));
      imageIdx += 3;
    }
  }
  
#pragma endscop
  i = __i_0__;
  j = __j_1__;
  return 0;
}
