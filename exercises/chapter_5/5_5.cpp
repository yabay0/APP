#include <iostream>
#include <cstddef>
#include <cassert>

double** Multiply(double** A, std::size_t Arows, std::size_t Acols,
                  double** B, std::size_t Brows, std::size_t Bcols)
{
    assert(Acols == Brows);
    double** C = new double*[Arows];
    for (std::size_t i = 0; i < Arows; ++i) {
        C[i] = new double[Bcols];
        for (std::size_t j = 0; j < Bcols; ++j) {
            C[i][j] = 0.0;
            for (std::size_t k = 0; k < Acols; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

void DeleteMatrix(double** M, std::size_t rows)
{
    for (std::size_t i = 0; i < rows; ++i)
        delete[] M[i];
    delete[] M;
}

int main()
{
    const std::size_t R1 = 2, C1 = 3;
    const std::size_t R2 = 3, C2 = 2;

    double** A = new double*[R1];
    for (std::size_t i = 0; i < R1; ++i)
        A[i] = new double[C1];

    double** B = new double*[R2];
    for (std::size_t i = 0; i < R2; ++i)
        B[i] = new double[C2];

    for (std::size_t i = 0; i < R1; ++i)
        for (std::size_t j = 0; j < C1; ++j)
            A[i][j] = i + j;

    for (std::size_t i = 0; i < R2; ++i)
        for (std::size_t j = 0; j < C2; ++j)
            B[i][j] = i * j;

    double** C = Multiply(A, R1, C1, B, R2, C2);

    for (std::size_t i = 0; i < R1; ++i) {
        for (std::size_t j = 0; j < C2; ++j)
            std::cout << C[i][j] << ' ';
        std::cout << '\n';
    }

    DeleteMatrix(A, R1);
    DeleteMatrix(B, R2);
    DeleteMatrix(C, R1);

    return 0;
}
