typedef struct {
int row_dim;
int col_dim;
double data[321];
double cols[347][341];}matrix;
typedef matrix *Matrix;

int main()
{
  matrix T[355];
  int j = 3;
  matrix A[104];
  int i = 18;
  int __i_0__ = i;
  int __j_1__ = j;
  
#pragma scop
  for (__i_0__ = 0; __i_0__ <= 290; __i_0__ += 1) {
    for (__j_1__ = 0; __j_1__ <= 69; __j_1__ += 1) {
      T -> cols[__i_0__][__j_1__] = A -> cols[__j_1__][__i_0__];
    }
  }
  
#pragma endscop
  i = __i_0__;
  j = __j_1__;
  return 0;
}
