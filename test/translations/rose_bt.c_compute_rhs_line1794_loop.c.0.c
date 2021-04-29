
int main()
{
  double forcing[65][65][65][6];
  double rhs[65][65][65][5];
  int m = 13;
  int k = 12;
  int j = 3;
  int grid_points[3];
  int i = 5;
  int __arr_sub_0__ = grid_points[0];
  int __arr_sub_1__ = grid_points[1];
  int __arr_sub_2__ = grid_points[2];
  int __i_3__ = i;
  int __j_4__ = j;
  int __k_5__ = k;
  int __m_6__ = m;
  
#pragma scop
{
    for (__i_3__ = 0; __i_3__ <= 4; __i_3__ += 1) {
      for (__j_4__ = 0; __j_4__ <= 4; __j_4__ += 1) {
        for (__k_5__ = 0; __k_5__ <= 3; __k_5__ += 1) {
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
  return 0;
}
