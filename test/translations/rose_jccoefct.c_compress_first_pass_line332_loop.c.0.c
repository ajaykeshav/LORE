typedef unsigned int JDIMENSION;
typedef short JCOEF;
typedef JCOEF JBLOCK[64];
typedef JBLOCK *JBLOCKROW;

int main()
{
  JBLOCK *thisblockrow = 15;
  int bi = 18;
  int h_samp_factor = 18;
  JBLOCK *lastblockrow = 10;
  JCOEF lastDC = 5;
  JDIMENSION MCUs_across = 8;
  JDIMENSION MCUindex = 9;
  int __MCUindex_0__ = MCUindex;
  int __bi_1__ = bi;
  
#pragma scop
{
    for (__MCUindex_0__ = 0; __MCUindex_0__ <= 173; __MCUindex_0__ += 1) {
      lastDC = lastblockrow[h_samp_factor - 1][0];
      for (__bi_1__ = 0; __bi_1__ <= 86; __bi_1__ += 1) {
        thisblockrow[__bi_1__][0] = lastDC;
      }
      thisblockrow += h_samp_factor;
      lastblockrow += h_samp_factor;
    }
  }
  
#pragma endscop
  MCUindex = __MCUindex_0__;
  bi = __bi_1__;
  return 0;
}
