#include <iostream>
using namespace std;

#define DIM 100

void read_matrix( float** M, int* n )
{
    cout << "Enter matrix size \n (positive number less than " << DIM + 1 << ")\n";
    do {
        cin >> *n;
    } while ( *n < 1 || *n > 100 );
    cout << "Enter matrix elements\n";
    for (int i = 0; i < *n; ++i) {
        cout << "Row " << i << endl;
        for (int j = 0; j < *n; ++j) {
            cin >> M[i][j];
        }
    }
}

void show_matrix( float** M, int n )
{
    cout << "==== MATRIX ====\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cout << M[i][j] << "  ";
        cout << "\n";
    }
}

void count_avg( float** M, int n )
{
    long count, i, j;
    float avg;

    // диагонали выше главной + сама главная
    for (int x = n - 1; x >= 0; --x) {
        avg = count = 0;
        j = x;
        i = 0;
        for ( ; j < n; j++, i++, count++ ) {
            avg += M[i][j];
        }
        avg /= count;
        cout << "Average diagonal value is " << avg << endl;
    }

    // диагонали ниже главной
    for (int x = 1; x < n; x++) {
        avg = count = 0;
        i = x;
        j = 0;
        for ( ; i < n; j++, i++, count++ ) {
            avg += M[i][j];
        }
        avg /= count;
        cout << "Average diagonal value is " << avg << endl;
    }
}


int main() {
    int n;
    auto ** A = new float*[DIM];
    for (long x = 0; x < DIM; x++)
        A[x] = new float[DIM];

    read_matrix(A, &n);
    show_matrix(A, n);
    count_avg(A, n);

    getchar();
}