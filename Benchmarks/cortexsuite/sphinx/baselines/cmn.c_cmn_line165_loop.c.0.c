#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
typedef int int32;
extern int32 f;
extern int32 n_frame;
typedef float float32;
typedef float32 mfcc_t;
extern mfcc_t * __restrict__ mfcp;
extern mfcc_t ** __restrict__ mfc;
extern int32 i;
typedef struct {
mfcc_t *cmn_mean;
mfcc_t *cmn_var;
mfcc_t *sum;
int32 nframe;
int32 veclen;}cmn_t;
extern cmn_t * __restrict__ cmn;

void loop()
{
  int __f_0__ = f;
  int __i_1__ = i;
  
#pragma scop
  for (__f_0__ = 0; __f_0__ <= n_frame - 1; __f_0__ += 1) {{
      mfcp = mfc[__f_0__];
    }
    for (__i_1__ = 0; __i_1__ <= cmn -> veclen - 1; __i_1__ += 1) {
      cmn -> cmn_mean[__i_1__] += mfcp[__i_1__];
    }
  }
  
#pragma endscop
  f = __f_0__;
  i = __i_1__;
}
