#include <stdio.h>
//by Ilya Mirzazhanov BS20-06
int main()
{
  FILE *file = fopen("input.txt", "r");
  int n = 5, m = 3;
  int A[m], E[m];
  int C[n][m], R[n][m];
  for (int i = 0; i < m; i++)
    fscanf(file, "%1d", &A[i]);
  for (int i = 0; i < m; i++)
    fscanf(file, "%1d", &E[i]);

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      fscanf(file, "%1d", &C[i][j]);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      fscanf(file, "%1d", &R[i][j]);

  int i, j, k;
  int f[n];
  for (k = 0; k < n; k++)
  {
    f[k] = 0;
  }
     int change = 1;
	
	while(change){
		change = 0;
    for (i = 0; i < n; i++)
    {
      if (f[i] == 0)
      {
        int flag = 1;
        for (j = 0; j < m; j++)
        {
          if (R[i][j] > A[j])
          {
            flag = 0;
            break;
          }
        }

        if (flag)
        {
          change = 1; f[i] = 1;
          for (int y = 0; y < m; y++)
            A[y] += C[i][y]; C[i][j] = 0;
        }
      }
    }
  }
  for (i = 0; i < n; i++) {
  if(f[i]==0) {
    printf("Deadlock");
  }
  }
}
