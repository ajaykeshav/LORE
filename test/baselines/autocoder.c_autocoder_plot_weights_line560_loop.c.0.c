#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
extern int img_ty;
extern int img_by;
extern int patch_width;
extern int img_y_range;
extern int img_tx;
extern int img_bx;
extern int img_x_range;
extern int img_width;
extern int patch_depth;

typedef struct autocode 
{
  unsigned int random_seed;
  int NoOfInputs;
  int NoOfHiddens;
  float DropoutPercent;
  float *inputs;
  float *hiddens;
  float *outputs;
  float *weights;
  float *lastWeightChange;
  float *bias;
  float *lastBiasChange;
  float *bperr;
  float BPerror;
  float BPerrorPercent;
  float BPerrorAverage;
  float learningRate;
  float noise;
  unsigned int itterations;
}ac;

extern ac * __restrict__ autocoder;
extern int start_index;
extern unsigned char * __restrict__ img;
extern float min_weight;
extern float weight_range;

void loop()
{
  int y;
  int __y_0__ = y;
  int __patch_y_1__;
  int __x_2__;
  int __patch_x_3__;
  int __img_n_4__;
  int __patch_n_5__;
  int __c_6__;
  float __w_7__;
  int ____x_2___8__ = __x_2__;
  int ____c_6___9__ = __c_6__;
  
#pragma scop
  for (__y_0__ = img_ty; __y_0__ <= img_by - 1; __y_0__ += 1) {{
      __patch_y_1__ = (__y_0__ - img_ty) * patch_width / img_y_range;
    }
    for (____x_2___8__ = img_tx; ____x_2___8__ <= img_bx - 1; ____x_2___8__ += 1) {{
        __patch_x_3__ = (____x_2___8__ - img_tx) * patch_width / img_x_range;
        __img_n_4__ = (__y_0__ * img_width + ____x_2___8__) * 3;
        __patch_n_5__ = (__patch_y_1__ * patch_width + __patch_x_3__) * patch_depth;
      }
      for (____c_6___9__ = 0; ____c_6___9__ <= 2; ____c_6___9__ += 1) {
        __w_7__ = autocoder -> weights[start_index + __patch_n_5__ + ____c_6___9__ * patch_depth / 3];
        img[__img_n_4__ + ____c_6___9__] = ((unsigned char )((__w_7__ - min_weight) * 255 / weight_range));
      }
    }
  }
  
#pragma endscop
  y = __y_0__;
  __x_2__ = ____x_2___8__;
  __c_6__ = ____c_6___9__;
}
