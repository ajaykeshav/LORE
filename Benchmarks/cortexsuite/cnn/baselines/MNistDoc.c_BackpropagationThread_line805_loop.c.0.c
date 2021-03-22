#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
extern int ii;

struct Preferences 
{
  unsigned int m_nItemsTrainingLabels;
  unsigned int m_nItemsTrainingImages;
  unsigned int m_nItemsTestingLabels;
  unsigned int m_nItemsTestingImages;
  int g_cImageSize;
  int m_nRowsImages;
  int m_nColsImages;
  int m_nMagWindowSize;
  int m_nMagWindowMagnification;
  double m_dInitialEtaLearningRate;
  double m_dLearningRateDecay;
  double m_dMinimumEtaLearningRate;
  unsigned int m_nAfterEveryNBackprops;
  double m_dMicronLimitParameter;
  unsigned int m_nNumHessianPatterns;
  double m_dMaxScaling;
  double m_dMaxRotation;
  double m_dElasticSigma;
  double m_dElasticScaling;
}
;
typedef struct Preferences Preferences;
extern Preferences * __restrict__ p;
extern int jj;
extern double inputVector[841];
extern unsigned char grayLevels[784];

void loop()
{
  int __ii_0__ = ii;
  int __jj_1__ = jj;
  
#pragma scop
  for (__ii_0__ = 0; __ii_0__ <= p -> g_cImageSize - 1; __ii_0__ += 1) {
    for (__jj_1__ = 0; __jj_1__ <= p -> g_cImageSize - 1; __jj_1__ += 1) {
      inputVector[1 + __jj_1__ + 29 * (__ii_0__ + 1)] = ((double )((int )((unsigned char )grayLevels[__jj_1__ + p -> g_cImageSize * __ii_0__]))) / 128.0 - 1.0;
    }
  }
  
#pragma endscop
  ii = __ii_0__;
  jj = __jj_1__;
}
