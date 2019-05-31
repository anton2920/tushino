#include <stdio.h>


void read(double Matrix[][100],int m,int n);
int SeekColumn(double Matrix[][100],int m,int n);
void write(double Matrix[][100],int m,int n);

int main() {
    int p;//number of column
    int col,i;
    double temp;
    int m,n;
    double Matrix[100][100];

    do{
        printf("Enter the number of rows\n");
        scanf("%d",&m);
    }while(m > 100 || m < 0);
    do{
        printf("Enter the number of columns\n");
        scanf("%d",&n);
    }while(n > 100 || n < 0);
    read(Matrix,m,n);
    write(Matrix,m,n);
    do{
        printf("Enter the number of column\n");
        scanf("%d",&p);
    }while(p > n-1 || p < 0);
    col = SeekColumn(Matrix,m,n);
    if(col != -1) {
        for (i = 0; i < m; i++) {
            temp = Matrix[i][col];
            Matrix[i][col] = Matrix[i][p];
            Matrix[i][p] = temp;
//        Matrix[i][col] += Matrix[i][p];
//        Matrix[i][p] = Matrix[i][col] - Matrix[i][p];
//        Matrix[i][col] -= Matrix[i][p];
        }
    }
    write(Matrix,m,n);

    return 0;

}

void read(double Matrix[][100],int m,int n)
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
void write(double Matrix[][100],int m,int n)
{
    int i,j;
    for(i = 0;i < m;i++)
    {
        for(j = 0;j < n;j++)
        {
            printf("%lf ",Matrix[i][j]);
        }
        printf("\n");
    }
}
int SeekColumn(double Matrix[][100],int m,int n)
{
    int i,j,f;
    int col = -1;
    f = 0;
    for(i = 0;i < n;i++)
    {
        for(j = 0; j < m; j++)
        {
            if(Matrix[j][i] > 0 || f == 1)
                f = 1;
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
