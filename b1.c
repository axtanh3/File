/*
 * Bai 1
 */
 
#include <stdio.h>
#include <conio.h>
typedef struct
{
	char hoten[30];
	unsigned int tuoi;	
}
people;
people aPeople;

int main(void)
{
	int i, n;
	FILE *inptr, *outptr;
	
	inptr = fopen("input", "wb");
	printf("So nguoi : ");
	scanf("%d", &n);
	
	//Nhap Ho ten, tuoi vao input
	for (i = 0; i < n; i++)
	{
		printf("Nguoi %d\n", i + 1);
		printf("Ho ten : ");
		fflush(stdin);
		gets(aPeople.hoten);
		printf("Tuoi   : ");
		scanf("%d", &aPeople.tuoi);
		fwrite(&aPeople, sizeof(people), 1, inptr);
	}
	fclose(inptr);
	
	//copy input ra output
	inptr = fopen("input", "rb");
	outptr = fopen("output", "wb");
	do
	{
		fread(&aPeople, sizeof(people), 1, inptr);
		fwrite(&aPeople, sizeof(people), 1, outptr);	
	}
	while (fread(&aPeople, sizeof(people), 1, inptr)!= NULL);
	
	//close all file
	fclose(inptr);
	fclose(outptr);
	
	getch();
	return 0;
}
