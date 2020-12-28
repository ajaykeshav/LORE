#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
extern int code;
extern int base_length[29];
extern int length;
extern int n;
extern int extra_lbits[29];
typedef unsigned char uch;
extern uch length_code[258 - 3 + 1];

void loop()
{
  int __code_0__ = code;
  int __n_1__ = n;
  
#pragma scop
  for (__code_0__ = 0; __code_0__ <= 27; __code_0__ += 1) {{
      base_length[__code_0__] = length;
    }
    for (__n_1__ = 0; __n_1__ <= (1 << extra_lbits[__code_0__]) - 1; __n_1__ += 1) {
      length_code[length++] = ((uch )__code_0__);
    }
  }
  
#pragma endscop
  code = __code_0__;
  n = __n_1__;
}
