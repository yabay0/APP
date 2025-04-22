#include <iostream>
#include <iomanip>
#include <cassert>
using namespace std;

int main() {
    double A[2][2] = {{4.0, 10.0},
                      {1.0,  1.0}};

    // Compute determinant
    double det = A[0][0] * A[1][1] - A[0][1] * A[1][0];

    // 3) Assert that determinant is non-zero
    assert(det != 0.0 && "Matrix determinant must be non-zero");

    // 1) Compute inverse of A:  A^{-1} = (1/det) * [d, -b; -c, a]
    double inv[2][2];
    inv[0][0] =  A[1][1] / det;
    inv[0][1] = -A[0][1] / det;
    inv[1][0] = -A[1][0] / det;
    inv[1][1] =  A[0][0] / det;

    // 2) Print the computed inverse (for comparison with the direct formula)
    cout << "Inverse of A:" << endl;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            cout << setw(8) << inv[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}