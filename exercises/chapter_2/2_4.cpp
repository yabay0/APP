#include <iostream>
#include <iomanip>
using namespace std;

void print_vector(const double v[3], const string &name) {
    cout << name << " = [ ";
    for (int i = 0; i < 3; ++i)
        cout << setw(6) << v[i] << " ";
    cout << "]\n";
}

void print_matrix(const double M[3][3], const string &name) {
    cout << name << " =\n";
    for (int i = 0; i < 3; ++i) {
        cout << "  [ ";
        for (int j = 0; j < 3; ++j)
            cout << setw(6) << M[i][j] << " ";
        cout << "]\n";
    }
}

int main(int argc, char *argv[]) 
{
    double u[3] = {1.0, 2.0, 3.0};
    double v[3] = {6.0, 5.0, 4.0};
    double A[3][3] = {{1.0, 5.0, 0.0},
                      {7.0, 1.0, 2.0},
                      {0.0, 0.0, 1.0}};
    double B[3][3] = {{-2.0, 0.0, 1.0},
                      { 1.0, 0.0, 0.0},
                      { 4.0, 1.0, 0.0}};

    double x[3], y[3], z[3];
    double C[3][3], D[3][3];

    // 1) x = u - v
    for (int i = 0; i < 3; ++i) {
        x[i] = u[i] - v[i];
    }

    // 2) y = A * u
    for (int i = 0; i < 3; ++i) {
        y[i] = 0.0;
        for (int j = 0; j < 3; ++j) {
            y[i] += A[i][j] * u[j];
        }
    }

    // 3) z = A*u - v = y - v
    for (int i = 0; i < 3; ++i) {
        z[i] = y[i] - v[i];
    }

    // 4) C = 4*A - 3*B
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            C[i][j] = 4.0 * A[i][j] - 3.0 * B[i][j];
        }
    }

    // 5) D = A * B
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            D[i][j] = 0.0;
            for (int k = 0; k < 3; ++k) {
                D[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    cout << fixed << setprecision(2);
    print_vector(u, "u");
    print_vector(v, "v");
    print_vector(x, "x = u - v");
    print_vector(y, "y = A * u");
    print_vector(z, "z = A*u - v");

    print_matrix(A, "A");
    print_matrix(B, "B");
    print_matrix(C, "C = 4*A - 3*B");
    print_matrix(D, "D = A * B");

    return 0;
}