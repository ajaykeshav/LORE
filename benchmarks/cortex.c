extern int i;
extern int k;
extern int j;
extern int m;
extern double **c;
extern int *counts;
extern double **c1;

void loop()
{

#pragma scop
    for(i = 0; i < k; i++)
    {
        for(j = 0; j < m; j++)
        {
            c[i][j] = c1[i][j] / counts[i];
        }
    }
#pragma endscop
}
