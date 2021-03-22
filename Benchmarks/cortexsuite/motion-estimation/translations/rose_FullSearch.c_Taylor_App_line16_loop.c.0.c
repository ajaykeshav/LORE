#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct {
double *data;
int x_length;
int y_length;}Image;

int main()
{
  Image block[500];
  double z[500];
  double dfy[500];
  Image block_ref[500];
  double dfx[500];
  int j;
  int BlockSize;
  int i;
  FILE stderr[500];
  FILE stdout[500];
  FILE stdin[500];
  int __i_0__ = i;
  int __j_1__ = j;
  
#pragma scop
  for (__i_0__ = 0; __i_0__ <= 500; __i_0__ += 1) {
    for (__j_1__ = 0; __j_1__ <= 500; __j_1__ += 1) {
      if (__j_1__ == 0) {
        dfx[__i_0__ * BlockSize + __j_1__] = block_ref -> data[__i_0__ * block_ref -> x_length + __j_1__ + 1] - block_ref -> data[__i_0__ * block_ref -> x_length + __j_1__];
      }
       else {
        if (__j_1__ == BlockSize - 1) {
          dfx[__i_0__ * BlockSize + __j_1__] = block_ref -> data[__i_0__ * block_ref -> x_length + __j_1__] - block_ref -> data[__i_0__ * block_ref -> x_length + __j_1__ - 1];
        }
         else {
          dfx[__i_0__ * BlockSize + __j_1__] = (block_ref -> data[__i_0__ * block_ref -> x_length + __j_1__ + 1] - block_ref -> data[__i_0__ * block_ref -> x_length + __j_1__ - 1]) / 2;
        }
      }
      if (__i_0__ == 0) {
        dfy[__i_0__ * BlockSize + __j_1__] = block_ref -> data[(__i_0__ + 1) * block_ref -> x_length + __j_1__] - block_ref -> data[__i_0__ * block_ref -> x_length + __j_1__];
      }
       else {
        if (__i_0__ == BlockSize - 1) {
          dfy[__i_0__ * BlockSize + __j_1__] = block_ref -> data[__i_0__ * block_ref -> x_length + __j_1__] - block_ref -> data[(__i_0__ - 1) * block_ref -> x_length + __j_1__];
        }
         else {
          dfy[__i_0__ * BlockSize + __j_1__] = (block_ref -> data[(__i_0__ + 1) * block_ref -> x_length + __j_1__] - block_ref -> data[(__i_0__ - 1) * block_ref -> x_length + __j_1__]) / 2;
        }
      }
      z[__i_0__ * BlockSize + __j_1__] = block -> data[__i_0__ * block -> x_length + __j_1__] - block_ref -> data[__i_0__ * block_ref -> x_length + __j_1__];
    }
  }
  
#pragma endscop
  i = __i_0__;
  j = __j_1__;
  return 0;
}
