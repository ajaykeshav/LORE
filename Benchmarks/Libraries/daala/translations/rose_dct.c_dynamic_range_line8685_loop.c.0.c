#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
typedef int32_t od_coeff;

int main()
{
  int j;
  int i;
  od_coeff x[128][128];
  int v;
  int n;
  int u;
  FILE stderr[138];
  FILE stdout[343];
  FILE stdin[347];
  int __u_0__ = u;
  int __v_1__ = v;
  
#pragma scop
{
    for (__u_0__ = 0; __u_0__ <= 58; __u_0__ += 1) {
      for (__v_1__ = 0; __v_1__ <= 79; __v_1__ += 1) {
        x[__u_0__][__v_1__] = (__u_0__ == i && __v_1__ == j) << 8 + 4;
      }
    }
  }
  
#pragma endscop
  u = __u_0__;
  v = __v_1__;
  return 0;
}
