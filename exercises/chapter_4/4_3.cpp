#include <iostream>
#include <cstdint>

int main() {
    const std::int64_t N = 1000000000LL;

    for (std::int64_t iter = 0; iter < N; ++iter) {
        double* v1 = new double[3];
        double* v2 = new double[3];

        v1[0] = 1.0;  v1[1] = 2.0;  v1[2] = 3.0;
        v2[0] = 4.0;  v2[1] = 5.0;  v2[2] = 6.0;

        double dot = v1[0]*v2[0]
                   + v1[1]*v2[1]
                   + v1[2]*v2[2];

        std::cout << "dot = " << dot << "\n";

        delete[] v1;
        delete[] v2;
    }

    return 0;
}