
int main()
{
  double sb_sample[2][3][12][32];
  double joint_sample[3][12][32];
  int gr = 10;
  int sample = 14;
  int sblimit = 5;
  int sb = 19;
  int __sb_0__ = sb;
  int __sample_1__ = sample;
  int __gr_2__ = gr;
  
#pragma scop
{
    for (__sb_0__ = 0; __sb_0__ <= 2; __sb_0__ += 1) {
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
  return 0;
}
