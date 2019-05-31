#include <iostream>
#include <time.h>
#define N 100

void output(int a[][N], int m)
{
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++)
            printf("a[%d;%d]= %d\t", i, j, a[i][j]);
        printf("\n");
    }
}

void key(int a[][N], int* m)
{
    printf("Insert matrix size \n");
    do {
        scanf("%d", m);

    } while( *m < 1 || *m > N );

    for (int i = 0; i < *m; i++)
        for (int j = 0; j < *m; j++) {
            printf(" a[%d;%d]= ", i, j);
            scanf("%d", &a[i][j]);
        }
}


void clean(int a[][N], int m)
{
    for (int i = 0;i < m - 1;i++)
        for (int j = i + 1;j < m - i - 1;j++)
            a[i][j] = 0;
}

int main()
{
    setlocale(LC_ALL, "rus");
    int a[N][N], m;

    key(a, &m);
    printf("\n\n");

    clean(a, m);
    output(a, m);

}
