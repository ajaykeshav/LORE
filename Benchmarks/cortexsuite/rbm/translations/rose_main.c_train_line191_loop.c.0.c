#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
  int neg[501][301];
  int pos[501][301];
  double edges[501][301];
  int v;
  FILE stderr[500];
  FILE stdout[500];
  FILE stdin[500];
  int __v_0__ = v;
  int __h_1__;
  int ____h_1___2__ = __h_1__;
  
#pragma scop
{
    for (__v_0__ = 0; __v_0__ <= 500; __v_0__ += 1) {
      for (____h_1___2__ = 0; ____h_1___2__ <= 300; ____h_1___2__ += 1) {
        edges[__v_0__][____h_1___2__] = edges[__v_0__][____h_1___2__] + 0.1 * (pos[__v_0__][____h_1___2__] - neg[__v_0__][____h_1___2__]);
      }
    }
  }
  
#pragma endscop
  v = __v_0__;
  __h_1__ = ____h_1___2__;
  return 0;
}
