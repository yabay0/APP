#include "5_9.h"
#include <cassert>

static double det3x3(double m[3][3]) {
    return m[0][0]*(m[1][1]*m[2][2] - m[1][2]*m[2][1])
         - m[0][1]*(m[1][0]*m[2][2] - m[1][2]*m[2][0])
         + m[0][2]*(m[1][0]*m[2][1] - m[1][1]*m[2][0]);
}

void solve3by3(double **A, double *b, double *u) {
    assert(A != nullptr && b != nullptr && u != nullptr);
    double M[3][3];
    for(int i = 0; i < 3; ++i)
        for(int j = 0; j < 3; ++j)
            M[i][j] = A[i][j];
    double detA = det3x3(M);
    assert(detA != 0.0);
    double C[3][3];
    for(int col = 0; col < 3; ++col) {
        for(int i = 0; i < 3; ++i)
            for(int j = 0; j < 3; ++j)
                C[i][j] = A[i][j];
        for(int i = 0; i < 3; ++i)
            C[i][col] = b[i];
        double detC = det3x3(C);
        u[col] = detC / detA;
    }
}