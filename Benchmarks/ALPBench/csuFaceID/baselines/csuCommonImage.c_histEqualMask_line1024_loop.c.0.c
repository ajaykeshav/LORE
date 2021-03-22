extern int x;
typedef struct {
int width;
int height;
int channels;
double ***data;}image;
typedef image *Image;
extern  __restrict__ Image im;
extern int y;
extern int c;
extern char ** __restrict__ mask;
extern double minVal;
extern double maxVal;
extern double totalPixels;

void loop()
{
  int __x_0__ = x;
  int __y_1__ = y;
  int __c_2__ = c;
  
#pragma scop
  for (__x_0__ = 0; __x_0__ <= im -> width - 1; __x_0__ += 1) {
    for (__y_1__ = 0; __y_1__ <= im -> height - 1; __y_1__ += 1) {
      for (__c_2__ = 0; __c_2__ <= im -> channels - 1; __c_2__ += 1) {
        if (!mask || mask[__x_0__][__y_1__]) {
          minVal = (minVal > im -> data[__x_0__][__y_1__][__c_2__]?im -> data[__x_0__][__y_1__][__c_2__] : minVal);
          maxVal = (maxVal < im -> data[__x_0__][__y_1__][__c_2__]?im -> data[__x_0__][__y_1__][__c_2__] : maxVal);
          totalPixels += 1;
        }
         else {
        }
      }
    }
  }
  
#pragma endscop
  x = __x_0__;
  y = __y_1__;
  c = __c_2__;
}
