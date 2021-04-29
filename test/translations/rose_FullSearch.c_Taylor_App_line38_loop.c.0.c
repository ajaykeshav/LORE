
int main()
{
  double z[138];
  double rhs[2];
  double dfy[343];
  double dfx[347];
  double A[4];
  int j = 4;
  int BlockSize = 13;
  int i = 15;
  int __i_0__ = i;
  int __j_1__ = j;
  
#pragma scop
  for (__i_0__ = 0; __i_0__ <= 1; __i_0__ += 1) {
    for (__j_1__ = 0; __j_1__ <= 1; __j_1__ += 1) {
      A[0] += dfx[__i_0__ * BlockSize + __j_1__] * dfx[__i_0__ * BlockSize + __j_1__];
      A[1] += dfx[__i_0__ * BlockSize + __j_1__] * dfy[__i_0__ * BlockSize + __j_1__];
      A[2] = A[1];
      A[3] += dfy[__i_0__ * BlockSize + __j_1__] * dfy[__i_0__ * BlockSize + __j_1__];
      rhs[0] += z[__i_0__ * BlockSize + __j_1__] * dfx[__i_0__ * BlockSize + __j_1__];
      rhs[1] += z[__i_0__ * BlockSize + __j_1__] * dfy[__i_0__ * BlockSize + __j_1__];
    }
  }
  
#pragma endscop
  i = __i_0__;
  j = __j_1__;
  return 0;
}
