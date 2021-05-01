
int main()
{
  int m2 = 5;
  double yi = 14;
  double yr = 4;
  double xi = 11;
  double a[341];
  double xr = 6;
  int k1 = 16;
  int ip[321];
  int j1 = 6;
  int j = 8;
  int m = 9;
  int k = 7;
  int __k_0__ = k;
  int __j_1__ = j;
  
#pragma scop
  for (__k_0__ = 0; __k_0__ <= 161; __k_0__ += 1) {
    for (__j_1__ = 0; __j_1__ <= 50; __j_1__ += 1) {
      j1 = 2 * __j_1__ + ip[__k_0__];
      k1 = 2 * __k_0__ + ip[__j_1__];
      xr = a[j1];
      xi = -a[j1 + 1];
      yr = a[k1];
      yi = -a[k1 + 1];
      a[j1] = yr;
      a[j1 + 1] = yi;
      a[k1] = xr;
      a[k1 + 1] = xi;
      j1 += m2;
      k1 += 2 * m2;
      xr = a[j1];
      xi = -a[j1 + 1];
      yr = a[k1];
      yi = -a[k1 + 1];
      a[j1] = yr;
      a[j1 + 1] = yi;
      a[k1] = xr;
      a[k1 + 1] = xi;
      j1 += m2;
      k1 -= m2;
      xr = a[j1];
      xi = -a[j1 + 1];
      yr = a[k1];
      yi = -a[k1 + 1];
      a[j1] = yr;
      a[j1 + 1] = yi;
      a[k1] = xr;
      a[k1 + 1] = xi;
      j1 += m2;
      k1 += 2 * m2;
      xr = a[j1];
      xi = -a[j1 + 1];
      yr = a[k1];
      yi = -a[k1 + 1];
      a[j1] = yr;
      a[j1 + 1] = yi;
      a[k1] = xr;
      a[k1 + 1] = xi;
    }
{
      k1 = 2 * __k_0__ + ip[__k_0__];
    }
{
      a[k1 + 1] = -a[k1 + 1];
      j1 = k1 + m2;
    }
{
      k1 = j1 + m2;
      xr = a[j1];
      xi = -a[j1 + 1];
    }
{
      yr = a[k1];
      yi = -a[k1 + 1];
      a[j1] = yr;
      a[j1 + 1] = yi;
      a[k1] = xr;
      a[k1 + 1] = xi;
    }
{
      k1 += m2;
    }
{
      a[k1 + 1] = -a[k1 + 1];
    }
  }
  
#pragma endscop
  k = __k_0__;
  j = __j_1__;
  return 0;
}
