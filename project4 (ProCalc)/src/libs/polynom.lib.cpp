/*
ProCalc — powerful multifunctional calculator
Copyright © 2019 Tushino Software LLC

This file is part of ProCalc.

ProCalc is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

ProCalc is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with ProCalc. If not, see <https://www.gnu.org/licenses/>.
*/

#include "../headers/header.h"

void mult_p(const double * P, const int P_deg, const double * Q, const int Q_deg, double * R )
{
    for (int i = 0; i <= P_deg; i++)
        for (int j = 0; j <= Q_deg; j++)
            R[i + j] += P[i] * Q[j];
}

void mult_number(double *P, int P_deg, double *R, double n)
{
    for (int i = 0; i <= P_deg; i++)
        R[i] = n * P[i];
}

void derivative_p(double *P, int P_deg, double *R, int R_deg)
{
    for (int i = 0; i <= R_deg; i++)
        R[i] = (i+1) * P[i+1];
}

void add_p(const double * P, const int P_deg, const double * Q, const int Q_deg, double * R )
{
    int max_deg = (P_deg > Q_deg) ? P_deg : Q_deg;
    for (int i = 0; i <= max_deg; i++)
        R[i] = P[i] + Q[i];
}

void substr_p(const double * P, const int P_deg, const double * Q, const int Q_deg, double * R )
{
    int max_deg = (P_deg > Q_deg) ? P_deg : Q_deg;
    for (int i = 0; i <= max_deg; i++)
        R[i] = P[i] - Q[i];
}

void substr_this( double * P, int P_deg, const double * Q, int Q_deg )
{
    int max_deg = (P_deg > Q_deg) ? P_deg : Q_deg;
    for (int i = 0; i <= max_deg; i++) {
        P[i] -= Q[i];
        if ( abs(P[i]) < 1e-6 )
            P[i] = 0;
    }
}

void copy_p(double * to, const double * from)
{
    for(int i = 0; i < MAX_DEG; i++)
        to[i] = from[i];
}

void zero_p(double * P)
{
    for(int i = 0; i < MAX_DEG; i++)
        P[i] = 0;
}

// returns polynom degree
int get_p( double * P )
{
    int deg;

    do {
        printf("| Insert polynomial degree                                   |\n");
        prt_ln();
        printf("| For example:                                               |\n"
"| If P(x) = 1*x^5 + 6*x^3 - 2*x^2 + 5*x - 13                 |\n"
"| then degree = 5                                            |\n");
        prt_ln();
        cout << "| Answer: ";
        cin >> deg;
        prt_ln();
    } while( deg <= 0 || deg >= MAX_DEG );

    printf("| Insert polynomial coefficients                             |\n");
    prt_ln();
    printf("| For example:                                               |\n"
"| If P(x) = 1*x^5 + 6*x^3 - 2*x^2 + 5*x - 13                 |\n"
"| then coefficients is = -13 5 -2 6 0 1                      |\n");
    prt_ln();
    for (int i = 0; i <= deg; i++) {
        cin >> P[i];
    }
    prt_ln();

    return deg;
}

void show_p( const double * P, const int deg )
{
    // вывести результат в виде многочлена
    // сам уже не понимаю как это работает
    for(int i = deg; i >= 0; i-- ) {
        if ( P[i] == 0 )
            continue;

        if ( P[i] < 0 )
            cout << " - ";
        else if ( i != deg )
            cout << " + ";

        if ( !(P[i] == 1 && i != 0)  )
            cout << abs(P[i]);

        if ( i != 0 )
            cout << "x";

        if ( i != 1 && i != 0 )
            cout << "^" << i;
    }
    cout << endl;
}
