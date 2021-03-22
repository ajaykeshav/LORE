#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
extern int k;
typedef struct {
double alpha;
double **log_prob_w;
int num_topics;
int num_terms;}lda_model;
extern lda_model * __restrict__ model;
typedef struct {
double **class_word;
double *class_total;
double alpha_suffstats;
int num_docs;}lda_suffstats;
extern lda_suffstats * __restrict__ ss;
extern int w;

void loop()
{
  int __k_0__ = k;
  int __w_1__ = w;
  
#pragma scop
  for (__k_0__ = 0; __k_0__ <= model -> num_topics - 1; __k_0__ += 1) {
    ss -> class_total[__k_0__] = 0;
    for (__w_1__ = 0; __w_1__ <= model -> num_terms - 1; __w_1__ += 1) {
      ss -> class_word[__k_0__][__w_1__] = 0;
    }
  }
  
#pragma endscop
  k = __k_0__;
  w = __w_1__;
}
