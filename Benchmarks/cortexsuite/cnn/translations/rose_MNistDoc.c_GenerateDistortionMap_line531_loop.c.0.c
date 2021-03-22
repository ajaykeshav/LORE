#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

struct vector 
{
  void **items;
  int capacity;
  int total;
}
;
typedef struct vector vector;

struct VectorLayers 
{
  vector *Layers;
}
;

struct NeuralNetwork 
{
  volatile double m_etaLearningRatePrevious;
  volatile double m_etaLearningRate;
  volatile unsigned int m_cBackprops;
  struct VectorLayers *m_Layers;
}
;
typedef struct NeuralNetwork NeuralNetwork;
typedef struct {
double *m_DispH;
double *m_DispV;
double m_GaussianKernel[21][21];
int m_cCols;
int m_cRows;
int m_cCount;
volatile unsigned int m_cBackprops;
volatile _Bool m_bNeedHessian;
unsigned int m_nAfterEveryNBackprops;
double m_dEtaDecay;
double m_dMinimumEta;
volatile double m_dEstimatedCurrentMSE;
FILE *m_fileTrainingLabels;
FILE *m_fileTrainingImages;
FILE *m_fileTestingLabels;
FILE *m_fileTestingImages;
_Bool m_bDistortTrainingPatterns;
volatile unsigned int m_iNextTrainingPattern;
volatile unsigned int m_iRandomizedTrainingPatternSequence[60000];
int g_cImageSize;
_Bool m_bDistortTestingPatterns;
unsigned int m_iWhichImageSet;
unsigned int m_nItemsTrainingImages;
unsigned int m_nItemsTestImages;
volatile unsigned int m_iNextTestingPattern;
NeuralNetwork *m_NN;}CMNistDoc;

int main()
{
  double dSFVert;
  int iMid;
  double dSFHoriz;
  int col;
  CMNistDoc cmnistdoc[500];
  int row;
  FILE stderr[500];
  FILE stdout[500];
  FILE stdin[500];
  int __row_0__ = row;
  int __location_1__;
  int __col_2__ = col;
  
#pragma scop
  for (__row_0__ = 0; __row_0__ <= 500; __row_0__ += 1) {
    for (__col_2__ = 0; __col_2__ <= 500; __col_2__ += 1) {
      __location_1__ = __row_0__ * cmnistdoc -> m_cCols + __col_2__;
      cmnistdoc -> m_DispH[__location_1__] += dSFHoriz * (__col_2__ - iMid);
      cmnistdoc -> m_DispV[__location_1__] -= dSFVert * (iMid - __row_0__);
    }
  }
  
#pragma endscop
  row = __row_0__;
  col = __col_2__;
  return 0;
}
