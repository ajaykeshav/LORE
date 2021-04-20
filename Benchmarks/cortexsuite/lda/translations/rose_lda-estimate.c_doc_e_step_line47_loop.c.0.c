//#include <inttypes.h>
//#include <stdio.h>
//#include <stdlib.h>
typedef struct {
int words[347];
int counts[343];
int length;
int total;}document;
typedef struct {
double alpha;
double log_prob_w[228][127];
int num_topics;
int num_terms;}lda_model;
typedef struct {
double class_word[341][321];
double class_total[347];
double alpha_suffstats;
int num_docs;}lda_suffstats;

int main()
{
  double phi[330][355];
  lda_suffstats ss[104];
  lda_model model[286];
  int k;
  document doc[138];
  int n;
  int __n_0__ = n;
  int __k_1__ = k;
  
#pragma scop
  for (__n_0__ = 0; __n_0__ <= 193; __n_0__ += 1) {
    for (__k_1__ = 0; __k_1__ <= 3; __k_1__ += 1) {
      ss -> class_word[__k_1__][doc -> words[__n_0__]] += doc -> counts[__n_0__] * phi[__n_0__][__k_1__];
      ss -> class_total[__k_1__] += doc -> counts[__n_0__] * phi[__n_0__][__k_1__];
    }
  }
  
#pragma endscop
  n = __n_0__;
  k = __k_1__;
  return 0;
}
