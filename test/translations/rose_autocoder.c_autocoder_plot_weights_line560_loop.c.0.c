
struct autocode 
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
}
;
typedef struct autocode ac;

int main()
{
  float weight_range = 9;
  float min_weight = 13;
  unsigned char img[341];
  int start_index = 5;
  ac autocoder[321];
  int patch_depth = 14;
  int img_width = 18;
  int img_x_range = 6;
  int img_bx = 6;
  int img_tx = 5;
  int img_y_range = 5;
  int patch_width = 3;
  int img_by = 15;
  int img_ty = 9;
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
  for (__y_0__ = img_ty; __y_0__ <= 194; __y_0__ += 1) {{
      __patch_y_1__ = (__y_0__ - img_ty) * patch_width / img_y_range;
    }
    for (____x_2___8__ = img_tx; ____x_2___8__ <= 173; ____x_2___8__ += 1) {{
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
  return 0;
}
