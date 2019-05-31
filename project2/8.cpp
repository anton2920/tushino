#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

const int m = 100, n = 100;

void read_M_N(int *p_M, int *p_N)
{
	do
	{
		printf("M ="); scanf("%d", p_M);
	} while ((*p_M > m) || (*p_M < 0));
	do
	{
		printf("N ="); scanf("%d", p_N);
	} while ((*p_N > n) || (*p_N < 0));
}

void read(int a[m][n], int M, int N)
{
	for (int i = 0;i < M;i++)
	{
		for (int j = 0;j < N;j++)
		{
			printf("\n a[%d][%d] = ", i, j);
			scanf("%d", &a[i][j]);
		}
	}
}

void sort_a(int a[m][n], int M, int N, int max[n], int help[m][n])
{
	int temp, max_total= INT_MIN, count =0;
	for (int i = 0;i < M;i++)
		for (int j = 0;j < N;j++)
		{
			if (a[i][j]>max[j]) max[j] = a[i][j];
		}

	while (count < N)
	{
		for (int j = 0;j < N;j++)
			if (max_total < max[j]) { max_total = max[j]; temp = j; }
		max[temp] = INT_MIN; max_total = INT_MIN;
		for (int i = 0;i < N;i++)
			help[i][N - 1 - count] = a[i][temp];
		count++;
	}
}

void end_a(int help[m][n], int M, int N)
{
	for (int i = 0;i < M;i++)
	{
		for (int j = 0;j < N;j++)
		{
			printf("  %d  ", help[i][j]);
		}
		printf("\n");
	}
}
int main()
{

	int i, j, M, N;
	int a[m][n] = { 0 }, max[n] = { INT_MIN }, help[m][n];

	read_M_N(&M, &N);
	read(a, M, N);
	sort_a(a, M, N, max, help);
	end_a(help, M, N);

	return 0;
}
