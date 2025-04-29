#include "5_6.h"
#include <cassert>

void Multiply(double **res, double **A, double **B,
              int ARows, int ACols, int BRows, int BCols) {
    assert(ACols == BRows);
    for (int i = 0; i < ARows; ++i) {
        for (int j = 0; j < BCols; ++j) {
            double sum = 0.0;
            for (int k = 0; k < ACols; ++k) {
                sum += A[i][k] * B[k][j];
            }
            res[i][j] = sum;
        }
    }
}

void Multiply(double *res, double *A, double **B,
              int ACols, int BRows, int BCols) {
    assert(ACols == BRows);
    for (int j = 0; j < BCols; ++j) {
        double sum = 0.0;
        for (int k = 0; k < ACols; ++k) {
            sum += A[k] * B[k][j];
        }
        res[j] = sum;
    }
}

void Multiply(double *res, double **A, double *B,
              int ARows, int ACols, int BRows) {
    assert(ACols == BRows);
    for (int i = 0; i < ARows; ++i) {
        double sum = 0.0;
        for (int k = 0; k < ACols; ++k) {
            sum += A[i][k] * B[k];
        }
        res[i] = sum;
    }
}

void Multiply(double **res, double scalar, double **B,
              int BRows, int BCols) {
    for (int i = 0; i < BRows; ++i) {
        for (int j = 0; j < BCols; ++j) {
            res[i][j] = scalar * B[i][j];
        }
    }
}

void Multiply(double **res, double **B, double scalar,
              int BRows, int BCols) {
    for (int i = 0; i < BRows; ++i) {
        for (int j = 0; j < BCols; ++j) {
            res[i][j] = B[i][j] * scalar;
        }
    }
}
