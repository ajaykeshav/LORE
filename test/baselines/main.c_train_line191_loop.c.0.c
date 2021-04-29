#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
extern int v;
extern double edges[100 * 5 + 1][3 * 100 + 1];
extern int pos[500 + 1][300 + 1];
extern int neg[500 + 1][300 + 1];

void loop()
{
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
}
