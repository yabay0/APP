#include "ComplexNumber.hpp"
#include "CalculateExponential.hpp"
#include <iostream>

constexpr int SIZE = 3;

static double factorial(int n) {
    double result = 1.0;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

static void multiplyMatrices(const ComplexNumber M1[][SIZE],
                             ComplexNumber **M2,
                             ComplexNumber result[][SIZE])
{
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            ComplexNumber sum(0.0);
            for (int k = 0; k < SIZE; ++k) {
                sum = sum + (M1[i][k] * M2[k][j]);
            }
            result[i][j] = sum;
        }
    }
}

void CalculateExponential(ComplexNumber **A, int nMax, ComplexNumber **res)
{
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
            res[i][j] = ComplexNumber(0.0);

    ComplexNumber power[SIZE][SIZE];
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
            power[i][j] = (i == j ? ComplexNumber(1.0) : ComplexNumber(0.0));

    ComplexNumber temp[SIZE][SIZE];

    for (int n = 0; n <= nMax; ++n) {
        double fact = factorial(n);
        ComplexNumber scale(1.0 / fact);

        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                res[i][j] = res[i][j] + (power[i][j] * scale);
            }
        }

        if (n < nMax) {
            multiplyMatrices(power, A, temp);
            for (int i = 0; i < SIZE; ++i)
                for (int j = 0; j < SIZE; ++j)
                    power[i][j] = temp[i][j];
        }
    }
}

void printMatrix(ComplexNumber **A, int rows, int cols)
{
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << A[i][j] << "  ";
        }
        std::cout << "\n";
    }
}
