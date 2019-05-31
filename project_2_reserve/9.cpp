#include <iostream>
using namespace std;

#define DIM 512

void read_matrix( float** M, int* m, int* n )
{
    cout << "Enter matrix height\n";
    do {
        cin >> *m;
    } while ( *m < 1 || *m > 100 );

    cout << "Enter matrix width\n";
    do {
        cin >> *n;
    } while ( *n < 1 || *n > 100 );

    cout << "Enter matrix elements\n";
    for (int i = 0; i < *m; ++i) {
        cout << "Row " << i << endl;
        for (int j = 0; j < *n; ++j) {
            cin >> M[i][j];
        }
    }
}

void show_matrix( float** M, int m, int n )
{
    cout << "==== MATRIX ====\n";
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j)
            cout << M[i][j] << "  ";
        cout << "\n";
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort( float** M, int m, int n )
{
   int i, j;
   for (i = 0; i < m; i++)
       for (j = 0; j < m-i-1; j++)
           if (M[j][0] > M[j+1][0])
              swap(M[j], M[j+1]);
}

int main() {
    int m, n;
    float ** A = new float*[DIM];
    for (long x = 0; x < DIM; x++)
        A[x] = new float[DIM];

    read_matrix(A, &m, &n);
    show_matrix(A, m, n);

    bubble_sort(A, m, n);
    show_matrix(A, m, n);

    getchar();
}