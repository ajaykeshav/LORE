
int main()
{
  int m2 = 11;
  double yi = 6;
  double yr = 4;
  double xi = 15;
  double a[343];
  double xr = 17;
  int k1 = 10;
  int ip[347];
  int j1 = 19;
  int j = 8;
  int m = 2;
  int k = 14;
  int __k_0__ = k;
  int __j_1__ = j;
  
#pragma scop
  for (__k_0__ = 1; __k_0__ <= 123; __k_0__ += 1) {
    for (__j_1__ = 0; __j_1__ <= 238; __j_1__ += 1) {
      j1 = 2 * __j_1__ + ip[__k_0__];
      k1 = 2 * __k_0__ + ip[__j_1__];
      xr = a[j1];
      xi = a[j1 + 1];
      yr = a[k1];
      yi = a[k1 + 1];
      a[j1] = yr;
      a[j1 + 1] = yi;
      a[k1] = xr;
      a[k1 + 1] = xi;
      j1 += m2;
      k1 += m2;
      xr = a[j1];
      xi = a[j1 + 1];
      yr = a[k1];
      yi = a[k1 + 1];
      a[j1] = yr;
      a[j1 + 1] = yi;
      a[k1] = xr;
      a[k1 + 1] = xi;
    }
  }
  
#pragma endscop
  k = __k_0__;
  j = __j_1__;
  return 0;
}
