
int main()
{
  double c1[500][500];
  int counts[500];
  double c[500][500];
  int m;
  int j;
  int k;
  int i;
  
#pragma scop
  for (i = 0; i < 500; i++) {
    for (j = 0; j < 500; j++) {
      c[i][j] = c1[i][j] / counts[i];
    }
  }
  
#pragma endscop
  return 0;
}
