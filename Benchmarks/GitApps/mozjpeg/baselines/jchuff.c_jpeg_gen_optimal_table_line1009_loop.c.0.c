#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
extern int i;
extern int j;
extern int codesize[257];
typedef unsigned char UINT8;
typedef int boolean;
typedef struct {
UINT8 bits[17];
UINT8 huffval[256];
boolean sent_table;}JHUFF_TBL;
extern JHUFF_TBL * __restrict__ htbl;
extern int p;

void loop()
{
  int __i_0__ = i;
  int __j_1__ = j;
  
#pragma scop
  for (__i_0__ = 1; __i_0__ <= 32; __i_0__ += 1) {
    for (__j_1__ = 0; __j_1__ <= 255; __j_1__ += 1) {
      if (codesize[__j_1__] == __i_0__) {
        htbl -> huffval[p] = ((UINT8 )__j_1__);
        p++;
      }
       else {
      }
    }
  }
  
#pragma endscop
  i = __i_0__;
  j = __j_1__;
}
