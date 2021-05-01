
int main()
{
  int imageIdx = 14;
  unsigned char bitmapImage[347];
  double grayscale[341][321];
  int x = 12;
  int j = 19;
  int y = 11;
  int i = 9;
  int __i_0__ = i;
  int __j_1__ = j;
  
#pragma scop
  for (__i_0__ = 0; __i_0__ <= 10; __i_0__ += 1) {
    for (__j_1__ = 0; __j_1__ <= 295; __j_1__ += 1) {
      grayscale[y - __i_0__ - 1][__j_1__] = ((double )(66 * bitmapImage[imageIdx + 2] + 129 * bitmapImage[imageIdx + 1] + 25 * bitmapImage[imageIdx] + 128 >> 8));
      imageIdx += 3;
    }
  }
  
#pragma endscop
  i = __i_0__;
  j = __j_1__;
  return 0;
}
