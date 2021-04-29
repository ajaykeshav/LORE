typedef struct {
int row_dim;
int col_dim;
double data[347];
double cols[138][343];}matrix;
typedef matrix *Matrix;

int main()
{
  matrix *T = 4;
  int j = 16;
  matrix *A = 5;
  int i = 7;
  int __i_0__ = i;
  int __j_1__ = j;
  
#pragma scop
  for (__i_0__ = 0; __i_0__ <= 61; __i_0__ += 1) {
    for (__j_1__ = 0; __j_1__ <= 105; __j_1__ += 1) {
      T -> cols[__i_0__][__j_1__] = A -> cols[__j_1__][__i_0__];
    }
  }
  
#pragma endscop
  i = __i_0__;
  j = __j_1__;
  return 0;
}
