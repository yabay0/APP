#include <iostream>
#include <cmath>

double CalculateNorm(const double* x, int vecSize, int p = 2)
{
    double sum = 0.0;
    for (int i = 0; i < vecSize; ++i)
        sum += std::pow(std::fabs(x[i]), p);
    return std::pow(sum, 1.0 / p);
}

int main()
{
    double v[] = { 1.0, -2.0, 3.0, -4.0 };
    int n = sizeof(v) / sizeof(*v);

    std::cout << "2-norm: " << CalculateNorm(v, n)       << "\n";
    std::cout << "1-norm: " << CalculateNorm(v, n, 1)    << "\n";
    std::cout << "3-norm: " << CalculateNorm(v, n, 3)    << "\n";

    return 0;
}