#include <stdio.h>
#include <conio.h>
typedef int matran[100][100];

void nhapMT(matran MT, int m, int n);
void tongMT(matran MT1, matran MT2, matran MT3, int m, int n);
void inMT(matran MT, int m, int n, FILE* f);

int main(void)
{
  	int i, m, n;
	matran MT1, MT2, MT3;
	FILE *out = fopen("file.txt", "a");
	m = 3; n = 2;
	
	//nhap
	nhapMT(MT1, m, n);
	nhapMT(MT2, m, n);
	
	//tinh tong
	tongMT(MT1, MT2, MT3, m, n);
	
	//in MT ra file
	inMT(MT1, m, n, out);
	inMT(MT2, m, n, out);
	inMT(MT3, m, n, out);
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

void tongMT(matran MT1, matran MT2, matran MT3, int m, int n)
{
	int i, j;
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			MT3[i][j] = MT2[i][j] + MT1[i][j];
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
