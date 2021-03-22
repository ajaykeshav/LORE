#include <inttypes.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct {
double *data;
int x_length;
int y_length;}Image;

int main()
{
  double MVy_int;
  double MVx_int;
  int y_min;
  int x_min;
  double SADmin;
  Image block[500];
  int jj;
  int BlockSize;
  int ii;
  Image img_ref[500];
  double block_ref[500];
  int yc;
  int yt;
  int xc;
  int xt;
  int j;
  int SearchLimit;
  int i;
  FILE stderr[500];
  FILE stdout[500];
  FILE stdin[500];
  int signgam;
  int __i_0__ = i;
  double __SAD_1__;
  int __j_2__ = j;
  int __ii_3__ = ii;
  int __jj_4__ = jj;
  
#pragma scop
  for (__i_0__ = -SearchLimit; __i_0__ <= 500; __i_0__ += 1) {
    for (__j_2__ = -SearchLimit; __j_2__ <= 500; __j_2__ += 1) {{
        xt = xc + __j_2__;
        yt = yc + __i_0__;
      }
      block_ref = img_ref -> data + yt * img_ref -> x_length + xt;
{
        __SAD_1__ = ((double )0);
      }
      for (__ii_3__ = 0; __ii_3__ <= 500; __ii_3__ += 1) {
        for (__jj_4__ = 0; __jj_4__ <= 500; __jj_4__ += 1) {
          __SAD_1__ += (abs((block -> data[__ii_3__ * block -> x_length + __jj_4__] - block_ref[__ii_3__ * img_ref -> x_length + __jj_4__])));
        }
      }
{
        __SAD_1__ = __SAD_1__ / (BlockSize * BlockSize);
      }
      if (__SAD_1__ < SADmin) {
        SADmin = __SAD_1__;
        x_min = xt;
        y_min = yt;
      }
       else {
      }{
        MVx_int = (x_min - xc);
        MVy_int = (y_min - yc);
      }
    }
  }
  
#pragma endscop
  i = __i_0__;
  j = __j_2__;
  ii = __ii_3__;
  jj = __jj_4__;
  return 0;
}
