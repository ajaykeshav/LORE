#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
extern int i;
extern int grid_points[3];
extern int j;
extern int k;
extern int m;
extern double rhs[64 / 2 * 2 + 1][64 / 2 * 2 + 1][64 / 2 * 2 + 1][5];
extern double forcing[64 / 2 * 2 + 1][64 / 2 * 2 + 1][64 / 2 * 2 + 1][5 + 1];

void loop()
{
  int __arr_sub_0__ = grid_points[0];
  int __arr_sub_1__ = grid_points[1];
  int __arr_sub_2__ = grid_points[2];
  int __i_3__ = i;
  int __j_4__ = j;
  int __k_5__ = k;
  int __m_6__ = m;
  
#pragma scop
{
    for (__i_3__ = 0; __i_3__ <= __arr_sub_0__ - 1; __i_3__ += 1) {
      for (__j_4__ = 0; __j_4__ <= __arr_sub_1__ - 1; __j_4__ += 1) {
        for (__k_5__ = 0; __k_5__ <= __arr_sub_2__ - 1; __k_5__ += 1) {
          for (__m_6__ = 0; __m_6__ <= 4; __m_6__ += 1) {
            rhs[__i_3__][__j_4__][__k_5__][__m_6__] = forcing[__i_3__][__j_4__][__k_5__][__m_6__];
          }
        }
      }
    }
  }
  
#pragma endscop
  i = __i_3__;
  j = __j_4__;
  k = __k_5__;
  m = __m_6__;
}
