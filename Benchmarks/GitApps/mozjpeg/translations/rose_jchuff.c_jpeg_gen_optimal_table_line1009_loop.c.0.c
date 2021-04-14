#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
typedef unsigned char UINT8;
typedef int boolean;
typedef struct {
UINT8 bits[17];
UINT8 huffval[256];
boolean sent_table;}JHUFF_TBL;

int main()
{
  int p;
  JHUFF_TBL htbl[127];
  int codesize[257];
  int j;
  int i;
  FILE stderr[138];
  FILE stdout[343];
  FILE stdin[347];
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
  return 0;
}
