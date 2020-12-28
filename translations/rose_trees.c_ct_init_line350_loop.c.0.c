#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
typedef unsigned char uch;

int main()
{
  uch length_code[256];
  int extra_lbits[29];
  int n;
  int length;
  int base_length[29];
  int code;
  FILE stderr[500];
  FILE stdout[500];
  FILE stdin[500];
  int __code_0__ = code;
  int __n_1__ = n;
  
#pragma scop
  for (__code_0__ = 0; __code_0__ <= 27; __code_0__ += 1) {{
      base_length[__code_0__] = length;
    }
    for (__n_1__ = 0; __n_1__ <= 29; __n_1__ += 1) {
      length_code[length++] = ((uch )__code_0__);
    }
  }
  
#pragma endscop
  code = __code_0__;
  n = __n_1__;
  return 0;
}
