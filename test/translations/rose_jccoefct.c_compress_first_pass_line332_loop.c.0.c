typedef unsigned int JDIMENSION;
typedef short JCOEF;
typedef JCOEF JBLOCK[64];
typedef JBLOCK *JBLOCKROW;

int main()
{
  JBLOCK thisblockrow[341];
  int bi = 4;
  int h_samp_factor = 6;
  JBLOCK lastblockrow[321];
  JCOEF lastDC = 12;
  JDIMENSION MCUs_across = 11;
  JDIMENSION MCUindex = 9;
  int __MCUindex_0__ = MCUindex;
  int __bi_1__ = bi;
  
#pragma scop
{
    for (__MCUindex_0__ = 0; __MCUindex_0__ <= 194; __MCUindex_0__ += 1) {
      lastDC = lastblockrow[h_samp_factor - 1][0];
      for (__bi_1__ = 0; __bi_1__ <= 53; __bi_1__ += 1) {
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
