#include <stdio.h>

#define row 100
#define co 101


void read(double Matrix[][co],int m,int n);
int SeekColumn(double Matrix[][co],int m,int n);
void write(double Matrix[][co],int m,int n);

void swap( double* a, double* b )
{
    double tmp = *a;
    *a = *b;
    *b = tmp;
}

int main() {
    int col,i,j;
    int m,n;
    double Matrix[row][co];

    do{
        printf("Enter the number of rows\n");
        scanf("%d",&m);
    }while(m > row || m < 1);
    do{
        printf("Enter the number of columns\n");
        scanf("%d",&n);
    }while(n > row || n < 1);
    read(Matrix, m, n);
    write(Matrix, m, n);
    col = SeekColumn(Matrix, m, n);

    if(col != -1) {
        for (i = 0; i < m; i++) {
            for (j = n; j >= col; j--) {
                if (j == col)
                    Matrix[i][j] = 1;
                else {
                    swap(&Matrix[i][j], &Matrix[i][j - 1]);
                }
            }
        }
        printf("\n");
        write(Matrix, m, n + 1);
    }else
    {
    	printf("\n");
        write(Matrix, m, n);
    }


    return 0;

}

void read(double Matrix[][co],int m,int n)
{
    int i,j;
    printf("Enter the array\n");
    for(i = 0;i < m;i++)
    {
        for(j = 0;j<n;j++)
        {
            scanf("%lf",&Matrix[i][j]);
        }
    }

}
void write(double Matrix[][co],int m,int n)
{
    int i, j;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%.2lf ", Matrix[i][j]);
        }
        printf("\n");
    }
}

int SeekColumn(double Matrix[][co],int m,int n)
{
    int i,j,f;
    int col = -1;
    f = 0;
    for(i = 0;i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            if(Matrix[j][i] < 0) {
                f = 1;
                break;
            }
        }
        if(f == 0)
        {
            col = i;
            break;
        }
        f = 0;
    }
    return col;
}
