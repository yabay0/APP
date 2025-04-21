#include <iostream>

int main() {
    /* Declare and initialize A and B */
    double A[2][2] = { {1.0, 2.0},
                       {3.0, 4.0} };
    double B[2][2] = { {5.0, 6.0},
                       {7.0, 8.0} };

    /* Prepare C (sum) and D (product) */
    double C[2][2];
    double D[2][2];

    /* Compute C = A + B */
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    /* Compute D = A * B */
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            D[i][j] = 0.0;
            for (int k = 0; k < 2; ++k) {
                D[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    /* Print matrices C and D */
    std::cout << "Matrix C = A + B:\n";
    for (int i = 0; i < 2; ++i) {
        std::cout << "[ ";
        for (int j = 0; j < 2; ++j) {
            std::cout << C[i][j] << " ";
        }
        std::cout << "]\n";
    }

    std::cout << "\nMatrix D = A * B:\n";
    for (int i = 0; i < 2; ++i) {
        std::cout << "[ ";
        for (int j = 0; j < 2; ++j) {
            std::cout << D[i][j] << " ";
        }
        std::cout << "]\n";
    }

    return 0;
}