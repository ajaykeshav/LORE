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
  double elasticScale;
  double uniformV[500];
  double uniformH[500];
  double fSampleV;
  double fSampleH;
  int yyyDisp;
  int iiMid;
  int xxxDisp;
  int yyy;
  int xxx;
  double fConvolvedV;
  double fConvolvedH;
  int row;
  CMNistDoc cmnistdoc[500];
  int col;
  FILE stderr[500];
  FILE stdout[500];
  FILE stdin[500];
  int __col_0__ = col;
  int __location_1__;
  int __location_2__;
  int __row_3__ = row;
  int __xxx_4__ = xxx;
  int __yyy_5__ = yyy;
  
#pragma scop
  for (__col_0__ = 0; __col_0__ <= 21; __col_0__ += 1) {
    for (__row_3__ = 0; __row_3__ <= 21; __row_3__ += 1) {{
        fConvolvedH = 0.0;
        fConvolvedV = 0.0;
      }
      for (__xxx_4__ = 0; __xxx_4__ <= 20; __xxx_4__ += 1) {
        for (__yyy_5__ = 0; __yyy_5__ <= 20; __yyy_5__ += 1) {
          xxxDisp = __col_0__ - iiMid + __xxx_4__;
          yyyDisp = __row_3__ - iiMid + __yyy_5__;
          if (xxxDisp < 0 || xxxDisp >= cmnistdoc -> m_cCols || yyyDisp < 0 || yyyDisp >= cmnistdoc -> m_cRows) {
            fSampleH = 0.0;
            fSampleV = 0.0;
          }
           else {
            __location_1__ = yyyDisp * cmnistdoc -> m_cCols + xxxDisp;
            fSampleH = uniformH[__location_1__];
            fSampleV = uniformV[__location_1__];
          }
          fConvolvedH += fSampleH * cmnistdoc -> m_GaussianKernel[__yyy_5__][__xxx_4__];
          fConvolvedV += fSampleV * cmnistdoc -> m_GaussianKernel[__yyy_5__][__xxx_4__];
        }
      }
      __location_2__ = __row_3__ * cmnistdoc -> m_cCols + __col_0__;
      cmnistdoc -> m_DispH[__location_2__] = elasticScale * fConvolvedH;
      cmnistdoc -> m_DispV[__location_2__] = elasticScale * fConvolvedV;
    }
  }
  
#pragma endscop
  col = __col_0__;
  row = __row_3__;
  xxx = __xxx_4__;
  yyy = __yyy_5__;
  return 0;
}
