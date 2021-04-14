#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
  double ing_r[127];
  long ir;
  double yb;
  long jrb1;
  long expand;
  long jrb;
  long jb;
  double h_r;
  double yr;
  long n_r_true;
  long jr;
  FILE stderr[138];
  FILE stdout[343];
  FILE stdin[347];
  int __jr_0__ = jr;
  int __ir_1__ = ir;
  
#pragma scop
  for (__jr_0__ = 0; __jr_0__ <= 61; __jr_0__ += 1) {{
      yr = h_r * ((double )__jr_0__);
      jb = ((long )yr);
      jrb = jb * expand;
      jrb1 = (jb + 1) * expand;
      yb = ((double )jb);
    }
    for (__ir_1__ = 0; __ir_1__ <= 41; __ir_1__ += 1) {
      ing_r[__ir_1__ + __jr_0__ * n_r_true] = ing_r[__ir_1__ + jrb1 * n_r_true] * (yr - yb) + ing_r[__ir_1__ + jrb * n_r_true] * (yb + ((double )1.0) - yr);
    }
  }
  
#pragma endscop
  jr = __jr_0__;
  ir = __ir_1__;
  return 0;
}
