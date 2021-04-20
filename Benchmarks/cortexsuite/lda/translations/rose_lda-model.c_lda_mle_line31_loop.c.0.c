#include <inttypes.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct {
double alpha;
double log_prob_w[341][321];
int num_topics;
int num_terms;}lda_model;
typedef struct {
double class_word[355][104];
double class_total[330];
double alpha_suffstats;
int num_docs;}lda_suffstats;

int main()
{
  lda_suffstats ss[317];
  int w;
  lda_model model[347];
  int k;
  FILE stderr[138];
  FILE stdout[343];
  FILE stdin[347];
  int signgam;
  int __k_0__ = k;
  int __w_1__ = w;
  
#pragma scop
  for (__k_0__ = 0; __k_0__ <= 45; __k_0__ += 1) {
    for (__w_1__ = 0; __w_1__ <= 6; __w_1__ += 1) {
      if (ss -> class_word[__k_0__][__w_1__] > 0) {
        model -> log_prob_w[__k_0__][__w_1__] = log(ss -> class_word[__k_0__][__w_1__]) - log(ss -> class_total[__k_0__]);
      }
       else {
        model -> log_prob_w[__k_0__][__w_1__] = (- 100);
      }
    }
  }
  
#pragma endscop
  k = __k_0__;
  w = __w_1__;
  return 0;
}
