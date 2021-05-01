
int main()
{
  int low = 2;
  int chan_width_x[347];
  float chanx_place_cost_fac[341][321];
  int ny = 9;
  int high = 13;
  int __high_0__ = high;
  int __low_1__ = low;
  
#pragma scop
{
    for (__high_0__ = 1; __high_0__ <= 50; __high_0__ += 1) {
      chanx_place_cost_fac[__high_0__][__high_0__] = chan_width_x[__high_0__];
      for (__low_1__ = 0; __low_1__ <= 56; __low_1__ += 1) {
        chanx_place_cost_fac[__high_0__][__low_1__] = chanx_place_cost_fac[__high_0__ - 1][__low_1__] + chan_width_x[__high_0__];
      }
    }
  }
  
#pragma endscop
  high = __high_0__;
  low = __low_1__;
  return 0;
}
