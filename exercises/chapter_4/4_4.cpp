#include <iostream>
#include <cstddef>

const std::size_t NROWS = 2;
const std::size_t NCOLS = 2;
const long        NITER = 1000000L;

int main() {
    for (long iter = 0; iter < NITER; ++iter) {
        double** A = new double*[NROWS];
        double** B = new double*[NROWS];
        double** C = new double*[NROWS];
        for (std::size_t i = 0; i < NROWS; ++i) {
            A[i] = new double[NCOLS];
            B[i] = new double[NCOLS];
            C[i] = new double[NCOLS];
        }

        A[0][0] = 1.0;  A[0][1] = 2.0;
        A[1][0] = 3.0;  A[1][1] = 4.0;
        B[0][0] = 5.0;  B[0][1] = 6.0;
        B[1][0] = 7.0;  B[1][1] = 8.0;

        for (std::size_t i = 0; i < NROWS; ++i) {
            for (std::size_t j = 0; j < NCOLS; ++j) {
                C[i][j] = A[i][j] + B[i][j];
            }
        }

        if (iter == 0) {
            std::cout << "C = A + B =\n";
            for (std::size_t i = 0; i < NROWS; ++i) {
                for (std::size_t j = 0; j < NCOLS; ++j) {
                    std::cout << C[i][j] << " ";
                }
                std::cout << "\n";
            }
        }

        for (std::size_t i = 0; i < NROWS; ++i) {
            delete[] A[i];
            delete[] B[i];
            delete[] C[i];
        }
        delete[] A;
        delete[] B;
        delete[] C;
    }

    return 0;
}