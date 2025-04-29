#include <iostream>

double Determinant(double** M, int n) {
    if (n == 1) {
        return M[0][0];
    }
    if (n == 2) {
        return M[0][0] * M[1][1] - M[0][1] * M[1][0];
    }
    double det = 0.0;
    for (int j = 0; j < n; ++j) {
        int sign = (j % 2 == 0 ? 1 : -1);
        int m = n - 1;
        double** minor = new double*[m];
        for (int i = 0; i < m; ++i)
            minor[i] = new double[m];
        for (int r = 1; r < n; ++r) {
            int cidx = 0;
            for (int c = 0; c < n; ++c) {
                if (c == j) continue;
                minor[r - 1][cidx++] = M[r][c];
            }
        }
        det += sign * M[0][j] * Determinant(minor, m);
        for (int i = 0; i < m; ++i) delete[] minor[i];
        delete[] minor;
    }
    return det;
}

double** AllocateMatrix(int n) {
    double** A = new double*[n];
    for (int i = 0; i < n; ++i)
        A[i] = new double[n];
    return A;
}

void DeleteMatrix(double** A, int n) {
    for (int i = 0; i < n; ++i)
        delete[] A[i];
    delete[] A;
}

int main() {
    // Test 2×2
    int n2 = 2;
    double** A2 = AllocateMatrix(n2);
    A2[0][0] = 1;  A2[0][1] = 2;
    A2[1][0] = 3;  A2[1][1] = 4;
    std::cout << "det(2×2) = " << Determinant(A2, n2) << "\n";
    DeleteMatrix(A2, n2);

    // Test 3×3
    int n3 = 3;
    double** A3 = AllocateMatrix(n3);
    A3[0][0] = 1;  A3[0][1] = 2;  A3[0][2] = 3;
    A3[1][0] = 0;  A3[1][1] = 4;  A3[1][2] = 5;
    A3[2][0] = 1;  A3[2][1] = 0;  A3[2][2] = 6;
    std::cout << "det(3×3) = " << Determinant(A3, n3) << "\n";
    DeleteMatrix(A3, n3);

    return 0;
}