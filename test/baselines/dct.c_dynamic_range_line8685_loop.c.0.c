#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
extern int u;
extern int n;
extern int v;
typedef int32_t od_coeff;
extern od_coeff x[64 * 2][64 * 2];
extern int i;
extern int j;

void loop()
{
  int __u_0__ = u;
  int __v_1__ = v;
  
#pragma scop
{
    for (__u_0__ = 0; __u_0__ <= n * 2 - 1; __u_0__ += 1) {
      for (__v_1__ = 0; __v_1__ <= n * 2 - 1; __v_1__ += 1) {
        x[__u_0__][__v_1__] = (__u_0__ == i && __v_1__ == j) << 8 + 4;
      }
    }
  }
  
#pragma endscop
  u = __u_0__;
  v = __v_1__;
}
