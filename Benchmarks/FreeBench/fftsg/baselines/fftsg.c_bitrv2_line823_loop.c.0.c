#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
extern int k;
extern int m;
extern int j;
extern int j1;
extern int * __restrict__ ip;
extern int k1;
extern double xr;
extern double * __restrict__ a;
extern double xi;
extern double yr;
extern double yi;
extern int m2;

void loop()
{
  int __k_0__ = k;
  int __j_1__ = j;
  
#pragma scop
  for (__k_0__ = 0; __k_0__ <= m - 1; __k_0__ += 1) {
    for (__j_1__ = 0; __j_1__ <= __k_0__ - 1; __j_1__ += 1) {
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
      k1 += 2 * m2;
      xr = a[j1];
      xi = a[j1 + 1];
      yr = a[k1];
      yi = a[k1 + 1];
      a[j1] = yr;
      a[j1 + 1] = yi;
      a[k1] = xr;
      a[k1 + 1] = xi;
      j1 += m2;
      k1 -= m2;
      xr = a[j1];
      xi = a[j1 + 1];
      yr = a[k1];
      yi = a[k1 + 1];
      a[j1] = yr;
      a[j1 + 1] = yi;
      a[k1] = xr;
      a[k1 + 1] = xi;
      j1 += m2;
      k1 += 2 * m2;
      xr = a[j1];
      xi = a[j1 + 1];
      yr = a[k1];
      yi = a[k1 + 1];
      a[j1] = yr;
      a[j1 + 1] = yi;
      a[k1] = xr;
      a[k1 + 1] = xi;
    }
{
      j1 = 2 * __k_0__ + m2 + ip[__k_0__];
      k1 = j1 + m2;
    }
{
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
}
