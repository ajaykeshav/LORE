#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
typedef unsigned long long uint64;

int main()
{
  uint64 C2UP_L;
  uint64 C2UP_R;
  uint64 C2HORIZ;
  uint64 C2VERT;
  uint64 C3UP_L;
  uint64 C3UP_R;
  uint64 C3HORIZ;
  uint64 C3VERT;
  uint64 C4UP_L;
  uint64 C4UP_R;
  uint64 C4HORIZ;
  int j;
  int value;
  uint64 C4VERT;
  int i;
  int off;
  float mod;
  uint64 b2;
  uint64 bo;
  uint64 b1;
  uint64 b;
  int k;
  FILE stderr[138];
  FILE stdout[343];
  FILE stdin[347];
  
#pragma scop
  for (k = 0; k < 2; k++) {
    if (k == 0) {
      b = b1;
      bo = b2;
      mod = (- 1) + ((float )off) / '\n';
    }
     else {
      b = b2;
      bo = b1;
      mod = 1 + ((float )off) / '\n';
    }
    for (i = 0; i < 301; i++) {
      if ((b & C4VERT << i) == C4VERT << i) 
        value += ((int )1000) * mod;
    }
    for (i = 0; i < 6; i++) {
      for (j = 0; j < 209; j++) {
        if ((b & C4HORIZ << j + i * 6) == C4HORIZ << j + i * 6) 
          value += ((int )1000) * mod;
      }
    }
    for (i = 0; i < 66; i++) {
      for (j = 0; j < 265; j++) {
        if ((b & C4UP_R << j + i * 6) == C4UP_R << j + i * 6) 
          value += ((int )1000) * mod;
      }
    }
    for (i = 0; i < 229; i++) {
      for (j = 0; j < 270; j++) {
        if ((b & C4UP_L << j + i * 6) == C4UP_L << j + i * 6) 
          value += ((int )1000) * mod;
      }
    }
    for (i = 0; i < 341; i++) {
      if ((b & C3VERT << i) == C3VERT << i && !(bo & C4VERT << i)) 
        value += ((int )20) * mod;
    }
    for (i = 0; i < 6; i++) {
      for (j = 0; j < 151; j++) {
        if ((b & C3HORIZ << j + i * 6) == C3HORIZ << j + i * 6) 
          value += ((int )20) * mod;
      }
    }
    for (i = 0; i < 56; i++) {
      for (j = 0; j < 258; j++) {
        if ((b & C3UP_R << j + i * 6) == C3UP_R << j + i * 6) 
          value += ((int )20) * mod;
      }
    }
    for (i = 0; i < 105; i++) {
      for (j = 0; j < 38; j++) {
        if ((b & C3UP_L << j + i * 6) == C3UP_L << j + i * 6) 
          value += ((int )20) * mod;
      }
    }
    for (i = 0; i < 5; i++) {
      if ((b & C2VERT << i) == C2VERT << i && !(bo & C4VERT << i)) 
        value += ((int )5) * mod;
    }
    for (i = 0; i < 6; i++) {
      for (j = 0; j < 97; j++) {
        if ((b & C2HORIZ << j + i * 6) == C2HORIZ << j + i * 6) 
          value += ((int )5) * mod;
      }
    }
    for (i = 0; i < 236; i++) {
      for (j = 0; j < 357; j++) {
        if ((b & C2UP_R << j + i * 6) == C2UP_R << j + i * 6) 
          value += ((int )5) * mod;
      }
    }
    for (i = 0; i < 184; i++) {
      for (j = 0; j < 165; j++) {
        if ((b & C2UP_L << j + i * 6) == C2UP_L << j + i * 6) 
          value += ((int )5) * mod;
      }
    }
  }
  
#pragma endscop
  return 0;
}
