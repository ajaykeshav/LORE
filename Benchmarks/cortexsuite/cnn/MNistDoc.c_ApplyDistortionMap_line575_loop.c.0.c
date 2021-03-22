#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
extern int row;

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
extern CMNistDoc * __restrict__ cmnistdoc;
extern int col;
extern double sourceRow;
extern double sourceCol;
extern double fracRow;
extern double fracCol;
extern double w1;
extern double w2;
extern double w3;
extern double w4;
extern _Bool bSkipOutOfBounds;
extern int sRow;
extern int sCol;
extern int sRowp1;
extern int sColp1;
extern double sourceValue;
extern double * __restrict__ inputVector;
extern double ** __restrict__ mappedVector;

void loop()
{
  int __row_0__ = row;
  int __location_1__;
  int __loc1_2__;
  int __loc2_3__;
  int __loc3_4__;
  int __loc4_5__;
  int __col_6__ = col;
  
#pragma scop
  for (__row_0__ = 0; __row_0__ <= cmnistdoc -> m_cRows - 1; __row_0__ += 1) {
    for (__col_6__ = 0; __col_6__ <= cmnistdoc -> m_cCols - 1; __col_6__ += 1) {
      __location_1__ = __row_0__ * cmnistdoc -> m_cCols + __col_6__;
      sourceRow = ((double )__row_0__) - cmnistdoc -> m_DispV[__location_1__];
      sourceCol = ((double )__col_6__) - cmnistdoc -> m_DispH[__location_1__];
      fracRow = sourceRow - ((int )sourceRow);
      fracCol = sourceCol - ((int )sourceCol);
      w1 = (1.0 - fracRow) * (1.0 - fracCol);
      w2 = (1.0 - fracRow) * fracCol;
      w3 = fracRow * (1 - fracCol);
      w4 = fracRow * fracCol;
      bSkipOutOfBounds = 0;
      if (sourceRow + 1.0 >= (cmnistdoc -> m_cRows)) {
        bSkipOutOfBounds = 1;
      }
       else {
      }
      if (sourceRow < 0) {
        bSkipOutOfBounds = 1;
      }
       else {
      }
      if (sourceCol + 1.0 >= (cmnistdoc -> m_cCols)) {
        bSkipOutOfBounds = 1;
      }
       else {
      }
      if (sourceCol < 0) {
        bSkipOutOfBounds = 1;
      }
       else {
      }
      if (bSkipOutOfBounds == 0) {
        sRow = ((int )sourceRow);
        sCol = ((int )sourceCol);
        sRowp1 = sRow + 1;
        sColp1 = sCol + 1;
        while(sRowp1 >= cmnistdoc -> m_cRows){
          sRowp1 -= cmnistdoc -> m_cRows;
        }
        while(sRowp1 < 0){
          sRowp1 += cmnistdoc -> m_cRows;
        }
        while(sColp1 >= cmnistdoc -> m_cCols){
          sColp1 -= cmnistdoc -> m_cCols;
        }
        while(sColp1 < 0){
          sColp1 += cmnistdoc -> m_cCols;
        }
        __loc1_2__ = sRow * cmnistdoc -> m_cCols + sCol;
        __loc2_3__ = sRow * cmnistdoc -> m_cCols + sColp1;
        __loc3_4__ = sRowp1 * cmnistdoc -> m_cCols + sCol;
        __loc4_5__ = sRowp1 * cmnistdoc -> m_cCols + sColp1;
        sourceValue = w1 * inputVector[__loc1_2__] + w2 * inputVector[__loc2_3__] + w3 * inputVector[__loc3_4__] + w4 * inputVector[__loc4_5__];
      }
       else {
        sourceValue = 1.0;
      }
      mappedVector[__row_0__][__col_6__] = 0.5 * (1.0 - sourceValue);
    }
  }
  
#pragma endscop
  row = __row_0__;
  col = __col_6__;
}
