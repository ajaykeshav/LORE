//#include <inttypes.h>
//#include <stdio.h>
//#include <stdlib.h>
extern int n;
typedef struct {
int *words;
int *counts;
int length;
int total;}document;
extern document * __restrict__ doc;
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
extern double ** __restrict__ phi;

void loop()
{
  int __n_0__ = n;
  int __k_1__ = k;
  
#pragma scop
  for (__n_0__ = 0; __n_0__ <= doc -> length - 1; __n_0__ += 1) {
    for (__k_1__ = 0; __k_1__ <= model -> num_topics - 1; __k_1__ += 1) {
      ss -> class_word[__k_1__][doc -> words[__n_0__]] += doc -> counts[__n_0__] * phi[__n_0__][__k_1__];
      ss -> class_total[__k_1__] += doc -> counts[__n_0__] * phi[__n_0__][__k_1__];
    }
  }
  
#pragma endscop
  n = __n_0__;
  k = __k_1__;
}
