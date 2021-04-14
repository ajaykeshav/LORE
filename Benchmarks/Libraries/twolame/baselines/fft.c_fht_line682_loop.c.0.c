#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
extern int i;
extern int kx;
extern double c1;
extern double t_c;
extern double s1;
extern double t_s;
extern double * __restrict__ fn;
extern double * __restrict__ fz;
extern double * __restrict__ fi;
extern double * __restrict__ gi;
extern int k1;
extern int k3;
extern int k2;
extern int k4;

void loop()
{
  int __i_0__ = i;
  double __c2_1__;
  double __s2_2__;
  double __t_3__;
  double __a_4__;
  double __b_5__;
  double __g0_6__;
  double __f0_7__;
  double __f1_8__;
  double __g1_9__;
  double __f2_10__;
  double __g2_11__;
  double __f3_12__;
  double __g3_13__;
  
#pragma scop
  for (__i_0__ = 1; __i_0__ <= kx - 1; __i_0__ += 1) {
    __t_3__ = c1;
    c1 = __t_3__ * t_c - s1 * t_s;
    s1 = __t_3__ * t_s + s1 * t_c;
    __c2_1__ = c1 * c1 - s1 * s1;
    __s2_2__ = 2 * (c1 * s1);
    fn = fz + 1024;
    fi = fz + __i_0__;
    gi = fz + k1 - __i_0__;
    do {
      __b_5__ = __s2_2__ * fi[k1] - __c2_1__ * gi[k1];
      __a_4__ = __c2_1__ * fi[k1] + __s2_2__ * gi[k1];
      __f1_8__ = fi[0] - __a_4__;
      __f0_7__ = fi[0] + __a_4__;
      __g1_9__ = gi[0] - __b_5__;
      __g0_6__ = gi[0] + __b_5__;
      __b_5__ = __s2_2__ * fi[k3] - __c2_1__ * gi[k3];
      __a_4__ = __c2_1__ * fi[k3] + __s2_2__ * gi[k3];
      __f3_12__ = fi[k2] - __a_4__;
      __f2_10__ = fi[k2] + __a_4__;
      __g3_13__ = gi[k2] - __b_5__;
      __g2_11__ = gi[k2] + __b_5__;
      __b_5__ = s1 * __f2_10__ - c1 * __g3_13__;
      __a_4__ = c1 * __f2_10__ + s1 * __g3_13__;
      fi[k2] = __f0_7__ - __a_4__;
      fi[0] = __f0_7__ + __a_4__;
      gi[k3] = __g1_9__ - __b_5__;
      gi[k1] = __g1_9__ + __b_5__;
      __b_5__ = c1 * __g2_11__ - s1 * __f3_12__;
      __a_4__ = s1 * __g2_11__ + c1 * __f3_12__;
      gi[k2] = __g0_6__ - __a_4__;
      gi[0] = __g0_6__ + __a_4__;
      fi[k3] = __f1_8__ - __b_5__;
      fi[k1] = __f1_8__ + __b_5__;
      gi += k4;
      fi += k4;
    }while (fi < fn);
  }
  
#pragma endscop
  i = __i_0__;
}
