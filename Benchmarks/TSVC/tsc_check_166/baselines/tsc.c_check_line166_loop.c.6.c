#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
extern float suma;
extern float a[32000];
extern float sumb;
extern float b[32000];
extern float sumc;
extern float c[32000];
extern float sumd;
extern float d[32000];
extern float sume;
extern float e[32000];

void loop()
{
  int i;
  int __i_0__ = i;
  
#pragma scop
{
    for (__i_0__ = 0; __i_0__ <= 31999; __i_0__ += 4) {
      suma += a[__i_0__];
{
        suma += a[__i_0__ + 1];
      }
{
        suma += a[__i_0__ + 2];
      }
{
        suma += a[__i_0__ + 3];
      }
    }
    for (__i_0__ = 0; __i_0__ <= 31999; __i_0__ += 4) {
      sumb += b[__i_0__];
{
        sumb += b[__i_0__ + 1];
      }
{
        sumb += b[__i_0__ + 2];
      }
{
        sumb += b[__i_0__ + 3];
      }
    }
    for (__i_0__ = 0; __i_0__ <= 31999; __i_0__ += 4) {
      sumc += c[__i_0__];
{
        sumc += c[__i_0__ + 1];
      }
{
        sumc += c[__i_0__ + 2];
      }
{
        sumc += c[__i_0__ + 3];
      }
    }
    for (__i_0__ = 0; __i_0__ <= 31999; __i_0__ += 4) {
      sumd += d[__i_0__];
{
        sumd += d[__i_0__ + 1];
      }
{
        sumd += d[__i_0__ + 2];
      }
{
        sumd += d[__i_0__ + 3];
      }
    }
    for (__i_0__ = 0; __i_0__ <= 31999; __i_0__ += 4) {
      sume += e[__i_0__];
{
        sume += e[__i_0__ + 1];
      }
{
        sume += e[__i_0__ + 2];
      }
{
        sume += e[__i_0__ + 3];
      }
    }
  }
  
#pragma endscop
  i = __i_0__;
}
