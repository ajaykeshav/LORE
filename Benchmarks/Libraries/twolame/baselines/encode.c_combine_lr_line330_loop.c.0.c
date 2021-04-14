#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
extern int sb;
extern int sblimit;
extern int sample;
extern int gr;
extern double joint_sample[3][12][32];
extern double sb_sample[2][3][12][32];

void loop()
{
  int __sb_0__ = sb;
  int __sample_1__ = sample;
  int __gr_2__ = gr;
  
#pragma scop
{
    for (__sb_0__ = 0; __sb_0__ <= sblimit - 1; __sb_0__ += 1) {
      for (__sample_1__ = 0; __sample_1__ <= 11; __sample_1__ += 1) {
        for (__gr_2__ = 0; __gr_2__ <= 2; __gr_2__ += 1) {
          joint_sample[__gr_2__][__sample_1__][__sb_0__] = .5 * (sb_sample[0][__gr_2__][__sample_1__][__sb_0__] + sb_sample[1][__gr_2__][__sample_1__][__sb_0__]);
        }
      }
    }
  }
  
#pragma endscop
  sb = __sb_0__;
  sample = __sample_1__;
  gr = __gr_2__;
}
