#include "5_10.h"
#include <cassert>
#include <cmath>

void guassian_elimination(double **A, double *b, double *u, int n) {
    assert(A && b && u && n > 0);
    for (int k = 0; k < n; ++k) {
        int pivot = k;
        double maxv = std::fabs(A[k][k]);
        for (int i = k + 1; i < n; ++i) {
            double val = std::fabs(A[i][k]);
            if (val > maxv) {
                maxv = val;
                pivot = i;
            }
        }
        assert(maxv != 0.0);
        if (pivot != k) {
            double *tmp = A[k]; A[k] = A[pivot]; A[pivot] = tmp;
            double tb = b[k]; b[k] = b[pivot]; b[pivot] = tb;
        }
        for (int i = k + 1; i < n; ++i) {
            double factor = A[i][k] / A[k][k];
            for (int j = k; j < n; ++j) {
                A[i][j] -= factor * A[k][j];
            }
            b[i] -= factor * b[k];
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        double sum = b[i];
        for (int j = i + 1; j < n; ++j) {
            sum -= A[i][j] * u[j];
        }
        u[i] = sum / A[i][i];
    }
}
