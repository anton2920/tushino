#include <iostream>
#include <time.h>
#define N 100

void output(int a[][N], int m)
{
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++)
            printf("%d\t", a[i][j]);
        printf("\n");
    }
}

void key(int a[][N], int* m)
{
    printf("Insert matrix size: \n");
    do {
        scanf("%d", m);
    } while( *m < 1 || *m > N );

    for (int i = 0; i < *m; i++)
        for (int j = 0; j < *m; j++) {
            printf(" a[%d;%d]= ", i, j);
            scanf("%d", &a[i][j]);
        }

    output(a, *m);
}

void swap(int a[][N], int m)
{
    int t;
    for (int i = 0;i < m - 1;i++)
        for (int j = 0; j < m - i - 1; j++) {
            t = a[i][j];
            a[i][j] = a[m - j - 1][m - i - 1];
            a[m - j - 1][m - i - 1] = t;
        }
    output(a, m);
}

int main()
{
    setlocale(LC_ALL, "rus");
    int a[N][N], m;

    key(a, &m);
    printf("\n\n");
    swap(a, m);

}
