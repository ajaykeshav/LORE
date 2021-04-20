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
double log_prob_w[127][138];
int num_topics;
int num_terms;}lda_model;
typedef struct {
double class_word[286][228];
double class_total[321];
double alpha_suffstats;
int num_docs;}lda_suffstats;

int main()
{
  double phi[347][341];
  lda_suffstats *ss;
  lda_model *model;
  int k;
  document *doc;
  int n;
  int __n_0__ = n;
  int __k_1__ = k;
  
#pragma scop
  for (__n_0__ = 0; __n_0__ <= 133; __n_0__ += 1) {
    for (__k_1__ = 0; __k_1__ <= 162; __k_1__ += 1) {
      ss -> class_word[__k_1__][doc -> words[__n_0__]] += doc -> counts[__n_0__] * phi[__n_0__][__k_1__];
      ss -> class_total[__k_1__] += doc -> counts[__n_0__] * phi[__n_0__][__k_1__];
    }
  }
  
#pragma endscop
  n = __n_0__;
  k = __k_1__;
  return 0;
}
