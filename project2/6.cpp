#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

const int m = 100, n = 100;

void read_M_N(int *p_M, int *p_N)
{
	do
	{
		printf("M ="); scanf("%d", p_M);
	} while ((*p_M > m) || (*p_M<0));
	do
	{
		printf("N ="); scanf("%d", p_N);
	} while ((*p_N > n) || (*p_N<0));
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

void sort(int a[m][n], int M,int N, int help[m][n])
{
	for (int i = 0;i < M;i++)
		for (int j = 0;j < N;j++)
		{
			if (i == 0)
			{
				if ((j == 0) && (a[i][j] < a[i][j + 1]) && (a[i][j] < a[i + 1][j]) && (a[i][j]<a[i+1][j+1])) help[i][j] = a[i][j];
				else
					if ((j == N-1) && (a[i][j] < a[i][j - 1]) && (a[i][j] < a[i + 1][j])&& (a[i][j]<a[i+1][j-1])) help[i][j] = a[i][j];
					else if ((a[i][j] < a[i][j + 1]) && (a[i][j] < a[i][j - 1]) && (a[i][j] < a[i + 1][j])&&(a[i][j]<a[i+1][j-1])&&(a[i][j]<a[i+1][j+1])) help[i][j] = a[i][j];
			}
			else
				if (i == M-1)
				{
					if ((j == 0) && (a[i][j] < a[i][j + 1]) && (a[i][j] < a[i - 1][j])&&(a[i][j]<a[i-1][j+1])) help[i][j] = a[i][j];
					else
						if ((j == N-1) && (a[i][j] < a[i][j - 1]) && (a[i][j] < a[i - 1][j])&&(a[i][j]<a[i-1][j-1])) help[i][j] = a[i][j];
						else if ((a[i][j] < a[i][j + 1]) && (a[i][j] < a[i][j - 1]) && (a[i][j] < a[i - 1][j])&&(a[i][j]<a[i-1][j+1])&&(a[i][j]<a[i-1][j-1])) help[i][j] = a[i][j];
				}
				else
					if ((j == 0) && (i > 0) && (i < M) && (a[i][j] < a[i][j + 1]) && (a[i][j] < a[i + 1][j]) && (a[i][j]<a[i - 1][j])&&(a[i][j]<a[i-1][j+1])&&(a[i][j]<a[i+1][j+1])) help[i][j] = a[i][j];
					else
						if ((j == N-1) && (i >= 1) && (i <= M - 1) && (a[i][j] < a[i][j - 1]) && (a[i][j] < a[i + 1][j]) && (a[i][j]<a[i - 1][j])&&(a[i][j]<a[i+1][j-1])&&(a[i][j]<a[i-1][j-1])) help[i][j] = a[i][j];
						else if ((a[i][j] < a[i + 1][j]) && (a[i][j] < a[i - 1][j]) && (a[i][j] < a[i][j + 1]) && (a[i][j] < a[i][j - 1])&&(a[i][j]<a[i-1][j-1])&&(a[i][j]<a[i-1][j+1])&&(a[i][j]<a[i+1][j-1])&&(a[i][j]<a[i+1][j+1])) help[i][j] = a[i][j];
		}
}

void end_a(int a[m][n], int help[m][n], int M, int N)
{
	for (int i = 0;i < M;i++)
	{
		for (int j = 0;j < N;j++)
		{
			if (a[i][j] == help[i][j]) a[i][j] = 0;
			printf("  %d  ", a[i][j]);
		}
		printf("\n");
	}
}
int main()
{

	int i, j, M, N;
	int a[m][n] = {0}, help[m][n] = { INT_MIN };
	
	read_M_N(&M, &N);
	read(a, M, N);
	sort(a, M, N, help);
	end_a(a, help, M, N);
	
	return 0;
}
