
int main()
{
  float e[32000];
  float sume;
  float d[32000];
  float sumd;
  float c[32000];
  float sumc;
  float b[32000];
  float sumb;
  float a[32000];
  float suma;
  int i;
  int __i_0__ = i;
  
#pragma scop
{
    int _lt_var___i_0__;
    for (_lt_var___i_0__ = 0; _lt_var___i_0__ <= 31999; _lt_var___i_0__ += 8) {
/* iter_count = (ub-lb+1)%step ==0?(ub-lb+1)/step: (ub-lb+1)/step+1; */
/* fringe = iter_count%unroll_factor==0 ? 0:unroll_factor*step */
      int _lu_fringe_27 = (((((31999 < _lt_var___i_0__ + 8 - 1?31999 : _lt_var___i_0__ + 8 - 1)) + 1 - _lt_var___i_0__) % 1 == 0?(((31999 < _lt_var___i_0__ + 8 - 1?31999 : _lt_var___i_0__ + 8 - 1)) + 1 - _lt_var___i_0__) / 1 : (((31999 < _lt_var___i_0__ + 8 - 1?31999 : _lt_var___i_0__ + 8 - 1)) + 1 - _lt_var___i_0__) / 1 + 1)) % 4 == 0?0 : 4;
      for (__i_0__ = _lt_var___i_0__; __i_0__ <= 75; __i_0__ += 4) {
        suma += a[__i_0__];
{
          suma += a[__i_0__ + 1];
        }
{
          suma += a[__i_0__ + 2];
        }
{
          suma += a[__i_0__ + 3];
        }
      }
      for (; __i_0__ <= 25; __i_0__ += 1) {
        suma += a[__i_0__];
      }
/* iter_count = (ub-lb+1)%step ==0?(ub-lb+1)/step: (ub-lb+1)/step+1; */
/* fringe = iter_count%unroll_factor==0 ? 0:unroll_factor*step */
      int _lu_fringe_28 = (((((31999 < _lt_var___i_0__ + 8 - 1?31999 : _lt_var___i_0__ + 8 - 1)) + 1 - _lt_var___i_0__) % 1 == 0?(((31999 < _lt_var___i_0__ + 8 - 1?31999 : _lt_var___i_0__ + 8 - 1)) + 1 - _lt_var___i_0__) / 1 : (((31999 < _lt_var___i_0__ + 8 - 1?31999 : _lt_var___i_0__ + 8 - 1)) + 1 - _lt_var___i_0__) / 1 + 1)) % 4 == 0?0 : 4;
      for (__i_0__ = _lt_var___i_0__; __i_0__ <= 228; __i_0__ += 4) {
        sumb += b[__i_0__];
{
          sumb += b[__i_0__ + 1];
        }
{
          sumb += b[__i_0__ + 2];
        }
{
          sumb += b[__i_0__ + 3];
        }
      }
      for (; __i_0__ <= 159; __i_0__ += 1) {
        sumb += b[__i_0__];
      }
/* iter_count = (ub-lb+1)%step ==0?(ub-lb+1)/step: (ub-lb+1)/step+1; */
/* fringe = iter_count%unroll_factor==0 ? 0:unroll_factor*step */
      int _lu_fringe_29 = (((((31999 < _lt_var___i_0__ + 8 - 1?31999 : _lt_var___i_0__ + 8 - 1)) + 1 - _lt_var___i_0__) % 1 == 0?(((31999 < _lt_var___i_0__ + 8 - 1?31999 : _lt_var___i_0__ + 8 - 1)) + 1 - _lt_var___i_0__) / 1 : (((31999 < _lt_var___i_0__ + 8 - 1?31999 : _lt_var___i_0__ + 8 - 1)) + 1 - _lt_var___i_0__) / 1 + 1)) % 4 == 0?0 : 4;
      for (__i_0__ = _lt_var___i_0__; __i_0__ <= 106; __i_0__ += 4) {
        sumc += c[__i_0__];
{
          sumc += c[__i_0__ + 1];
        }
{
          sumc += c[__i_0__ + 2];
        }
{
          sumc += c[__i_0__ + 3];
        }
      }
      for (; __i_0__ <= 311; __i_0__ += 1) {
        sumc += c[__i_0__];
      }
/* iter_count = (ub-lb+1)%step ==0?(ub-lb+1)/step: (ub-lb+1)/step+1; */
/* fringe = iter_count%unroll_factor==0 ? 0:unroll_factor*step */
      int _lu_fringe_30 = (((((31999 < _lt_var___i_0__ + 8 - 1?31999 : _lt_var___i_0__ + 8 - 1)) + 1 - _lt_var___i_0__) % 1 == 0?(((31999 < _lt_var___i_0__ + 8 - 1?31999 : _lt_var___i_0__ + 8 - 1)) + 1 - _lt_var___i_0__) / 1 : (((31999 < _lt_var___i_0__ + 8 - 1?31999 : _lt_var___i_0__ + 8 - 1)) + 1 - _lt_var___i_0__) / 1 + 1)) % 4 == 0?0 : 4;
      for (__i_0__ = _lt_var___i_0__; __i_0__ <= 301; __i_0__ += 4) {
        sumd += d[__i_0__];
{
          sumd += d[__i_0__ + 1];
        }
{
          sumd += d[__i_0__ + 2];
        }
{
          sumd += d[__i_0__ + 3];
        }
      }
      for (; __i_0__ <= 318; __i_0__ += 1) {
        sumd += d[__i_0__];
      }
/* iter_count = (ub-lb+1)%step ==0?(ub-lb+1)/step: (ub-lb+1)/step+1; */
/* fringe = iter_count%unroll_factor==0 ? 0:unroll_factor*step */
      int _lu_fringe_31 = (((((31999 < _lt_var___i_0__ + 8 - 1?31999 : _lt_var___i_0__ + 8 - 1)) + 1 - _lt_var___i_0__) % 1 == 0?(((31999 < _lt_var___i_0__ + 8 - 1?31999 : _lt_var___i_0__ + 8 - 1)) + 1 - _lt_var___i_0__) / 1 : (((31999 < _lt_var___i_0__ + 8 - 1?31999 : _lt_var___i_0__ + 8 - 1)) + 1 - _lt_var___i_0__) / 1 + 1)) % 4 == 0?0 : 4;
      for (__i_0__ = _lt_var___i_0__; __i_0__ <= 312; __i_0__ += 4) {
        sume += e[__i_0__];
{
          sume += e[__i_0__ + 1];
        }
{
          sume += e[__i_0__ + 2];
        }
{
          sume += e[__i_0__ + 3];
        }
      }
      for (; __i_0__ <= 7; __i_0__ += 1) {
        sume += e[__i_0__];
      }
    }
  }
  
#pragma endscop
  i = __i_0__;
  return 0;
}
