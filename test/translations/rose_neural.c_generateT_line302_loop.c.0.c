typedef float real;

int main()
{
  real Tmatrix[341][321];
  int col = 11;
  int NNTOT = 19;
  int row = 15;
  int __row_0__ = row;
  int __col_1__ = col;
  
#pragma scop
{
    for (__row_0__ = 0; __row_0__ <= 318; __row_0__ += 1) {
      for (__col_1__ = 0; __col_1__ <= 79; __col_1__ += 1) {
        Tmatrix[__row_0__][__col_1__] = 0.0;
      }
    }
  }
  
#pragma endscop
  row = __row_0__;
  col = __col_1__;
  return 0;
}
