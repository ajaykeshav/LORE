
int main()
{
  int firstcol = 12;
  int colidx[2198001];
  int rowstr[14002];
  int k = 7;
  int firstrow = 6;
  int lastrow = 5;
  int j = 10;
  int __j_0__ = j;
  int __k_1__ = k;
  
#pragma scop
  for (__j_0__ = 1; __j_0__ <= 299; __j_0__ += 1) {
    for (__k_1__ = rowstr[__j_0__]; __k_1__ <= 231; __k_1__ += 1) {
      colidx[__k_1__] = colidx[__k_1__] - firstcol + 1;
    }
  }
  
#pragma endscop
  j = __j_0__;
  k = __k_1__;
  return 0;
}
