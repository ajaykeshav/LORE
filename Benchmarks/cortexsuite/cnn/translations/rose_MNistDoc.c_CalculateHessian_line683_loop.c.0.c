#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

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

int main()
{
  unsigned char grayLevels[784];
  double inputVector[841];
  int jj;
  Preferences p[500];
  int ii;
  FILE stderr[500];
  FILE stdout[500];
  FILE stdin[500];
  int __ii_0__ = ii;
  int __jj_1__ = jj;
  
#pragma scop
  for (__ii_0__ = 0; __ii_0__ <= 500; __ii_0__ += 1) {
    for (__jj_1__ = 0; __jj_1__ <= 500; __jj_1__ += 1) {
      inputVector[1 + __jj_1__ + 29 * (__ii_0__ + 1)] = ((double )((int )((unsigned char )grayLevels[__jj_1__ + p -> g_cImageSize * __ii_0__]))) / 128.0 - 1.0;
    }
  }
  
#pragma endscop
  ii = __ii_0__;
  jj = __jj_1__;
  return 0;
}
