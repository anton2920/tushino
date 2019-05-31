#include <iostream>
#include <time.h>
#define _CRT_SECURE_NO_WARNINGS
#define SIZE 100

void output(int a[SIZE][SIZE], int m, int n)
{
    printf("=== MATRIX ===\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d\t", a[i][j]);
        printf("\n");
    }
}

void key( int a[SIZE][SIZE], int* m, int *n )
{
    printf("Insert N\n");
    do {
        scanf("%d", n);
    } while ( *n < 1 || *n > SIZE );

    printf("Insert M\n");
    do {
        scanf("%d", m);
    } while ( *m < 1 || *m > SIZE );

    for (int i = 0; i < *m; i++)
        for (int j = 0; j < *n; j++)
        {
            printf(" a[%d;%d]= ", i, j);
            scanf("%d", &a[i][j]);
        }
}

void downup(int a[SIZE][SIZE], int m, int n)
{
    int t;
    for (int j = 0; j < n; j++)
    {
        if (j % 2 != 0)

            for (int i = 0; i < m/2; i++)
            {
                t = a[i][j];
                a[i][j] = a[m - i-1][j];
                a[m - i-1][j] = t;
            }
    }
}

int main()
{
    setlocale(LC_ALL, "rus");
    int a[SIZE][SIZE], m, n;

    key(a, &m, &n);
    output(a, m, n);
    printf("\n\n");
    downup(a, m, n);
    output(a, m, n);

    getchar();
}