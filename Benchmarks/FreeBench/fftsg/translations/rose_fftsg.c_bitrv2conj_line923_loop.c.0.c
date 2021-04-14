#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
  int m2;
  double yi;
  double yr;
  double xi;
  double a[228];
  double xr;
  int k1;
  int ip[127];
  int j1;
  int j;
  int m;
  int k;
  FILE stderr[138];
  FILE stdout[343];
  FILE stdin[347];
  int __k_0__ = k;
  int __j_1__ = j;
  
#pragma scop
  for (__k_0__ = 0; __k_0__ <= 125; __k_0__ += 1) {
    for (__j_1__ = 0; __j_1__ <= 7; __j_1__ += 1) {
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
