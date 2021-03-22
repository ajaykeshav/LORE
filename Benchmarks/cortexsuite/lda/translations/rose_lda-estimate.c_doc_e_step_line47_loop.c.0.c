#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct {
int *words;
int *counts;
int length;
int total;}document;
typedef struct {
double alpha;
double **log_prob_w;
int num_topics;
int num_terms;}lda_model;
typedef struct {
double **class_word;
double *class_total;
double alpha_suffstats;
int num_docs;}lda_suffstats;

int main()
{
  double phi[500][500];
  lda_suffstats ss[500];
  lda_model model[500];
  int k;
  document doc[500];
  int n;
  FILE stderr[500];
  FILE stdout[500];
  FILE stdin[500];
  int __n_0__ = n;
  int __k_1__ = k;
  
#pragma scop
  for (__n_0__ = 0; __n_0__ <= 500; __n_0__ += 1) {
    for (__k_1__ = 0; __k_1__ <= 500; __k_1__ += 1) {
      ss -> class_word[__k_1__][doc -> words[__n_0__]] += doc -> counts[__n_0__] * phi[__n_0__][__k_1__];
      ss -> class_total[__k_1__] += doc -> counts[__n_0__] * phi[__n_0__][__k_1__];
    }
  }
  
#pragma endscop
  n = __n_0__;
  k = __k_1__;
  return 0;
}
