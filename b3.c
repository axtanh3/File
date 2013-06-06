#include <stdio.h>
#include <conio.h>
typedef int matran[100][100];

void nhapMT(matran MT, int m, int n);
void tichMT(matran MT1, matran MT2, matran MT3, int m, int n, int k);
void inMT(matran MT, int m, int n, FILE* f);

int main(void)
{
	int i, m, n, k;
	matran MT1, MT2, MT3;
	FILE *out = fopen("file1.txt", "a");
	m = 3; n = 2; k = 3;
  
	//nhap
	nhapMT(MT1, m, n);
	nhapMT(MT2, n, k);
  
	//tinh tich
	tichMT(MT1, MT2, MT3, m, n, k);
  
	//in MT ra file
	inMT(MT1, m, n, out);
	inMT(MT2, n, k, out);
	inMT(MT3, m, k, out);
	printf("\n");
  
	//dong file
	fclose(out);
	getch();
	return 0;
}

void nhapMT(matran MT, int m, int n)
{
	int i, j;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("MT[%d,%d]= ", i, j);
			scanf("%d", &MT[i][j]);
		}

	}
}

void tichMT(matran MT1, matran MT2, matran MT3, int m, int n, int k)
{
	int i, j, t;
	for (i = 0; i < m; i++)
		for (j = 0; j < k; j++)
		{
			MT3[i][j] = 0;
			for (t = 0; t < n; t++)
				MT3[i][j] += MT2[t][i] * MT1[j][t];
		}
					
}

void inMT(matran MT, int m, int n, FILE *f)
{
	int i, j;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
			fprintf(f, "%4d", MT[i][j]);
		fprintf(f, "\n");
	}
	fprintf(f, "\n");
}
