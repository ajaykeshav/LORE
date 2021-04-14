#include <inttypes.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

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
  float errorPercent;
  ac autocoder[127];
  FILE stderr[138];
  FILE stdout[343];
  FILE stdin[347];
  int signgam;
  int i;
  int __i_0__ = i;
  float __BPerror_1__;
  float __afact_2__;
  int __h_3__;
  int ____h_3___4__ = __h_3__;
  
#pragma scop
  for (__i_0__ = 0; __i_0__ <= 357; __i_0__ += 1) {
    __BPerror_1__ = autocoder -> inputs[__i_0__] - autocoder -> outputs[__i_0__];
    autocoder -> BPerror += fabs(__BPerror_1__);
    errorPercent += fabs(__BPerror_1__);
    __afact_2__ = autocoder -> outputs[__i_0__] * (1.0f - autocoder -> outputs[__i_0__]);
    for (____h_3___4__ = 0; ____h_3___4__ <= 270; ____h_3___4__ += 1) {
      if (autocoder -> hiddens[____h_3___4__] == (- 9999)) {
        continue; 
      }
       else {
      }
      autocoder -> bperr[____h_3___4__] += __BPerror_1__ * __afact_2__ * autocoder -> weights[____h_3___4__ * autocoder -> NoOfInputs + __i_0__];
    }
  }
  
#pragma endscop
  i = __i_0__;
  __h_3__ = ____h_3___4__;
  return 0;
}
