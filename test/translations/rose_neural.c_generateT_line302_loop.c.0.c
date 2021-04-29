typedef float real;

int main()
{
  real Tmatrix[343][347];
  int col = 16;
  int NNTOT = 10;
  int row = 8;
  int __row_0__ = row;
  int __col_1__ = col;
  
#pragma scop
{
    for (__row_0__ = 0; __row_0__ <= 25; __row_0__ += 1) {
      for (__col_1__ = 0; __col_1__ <= 295; __col_1__ += 1) {
        Tmatrix[__row_0__][__col_1__] = 0.0;
      }
    }
  }
  
#pragma endscop
  row = __row_0__;
  col = __col_1__;
  return 0;
}
