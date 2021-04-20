#include <inttypes.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct {
double alpha;
double log_prob_w[343][347];
int num_topics;
int num_terms;}lda_model;
typedef struct {
double class_word[127][138];
double class_total[228];
double alpha_suffstats;
int num_docs;}lda_suffstats;

int main()
{
  lda_suffstats *ss;
  int w;
  lda_model *model;
  int k;
  FILE *stderr;
  FILE *stdout;
  FILE *stdin;
  int signgam;
  int __k_0__ = k;
  int __w_1__ = w;
  
#pragma scop
  for (__k_0__ = 0; __k_0__ <= 22; __k_0__ += 1) {
    for (__w_1__ = 0; __w_1__ <= 45; __w_1__ += 1) {
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
