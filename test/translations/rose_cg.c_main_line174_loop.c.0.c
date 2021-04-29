
int main()
{
  int firstcol = 17;
  int colidx[2198001];
  int rowstr[14002];
  int k = 19;
  int firstrow = 3;
  int lastrow = 10;
  int j = 7;
  int __j_0__ = j;
  int __k_1__ = k;
  
#pragma scop
  for (__j_0__ = 1; __j_0__ <= 97; __j_0__ += 1) {
    for (__k_1__ = rowstr[__j_0__]; __k_1__ <= 109; __k_1__ += 1) {
      colidx[__k_1__] = colidx[__k_1__] - firstcol + 1;
    }
  }
  
#pragma endscop
  j = __j_0__;
  k = __k_1__;
  return 0;
}
