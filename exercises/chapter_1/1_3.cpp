#include <iostream>
#include <cmath>

int main()
{
    /* Declare and initialize two 3‑element vectors */
    double v1[3] = { 1.0, -2.5, 4.2 };
    double v2[3] = { 0.5, 3.1, -1.0 };

    /* Compute the dot product of the two vectors */
    double dot = 0.0;
    for (int i = 0; i < 3; ++i)
    {
        dot += v1[i] * v2[i];
    }

    /* Compute the Euclidean norms */
    double sumsq1 = 0.0, sumsq2 = 0.0;
    for (int i = 0; i < 3; ++i)
    {
        sumsq1 += v1[i] * v1[i];
        sumsq2 += v2[i] * v2[i];
    }

    double norm1 = std::sqrt(sumsq1);
    double norm2 = std::sqrt(sumsq2);

    /* Print results */
    std::cout << "Vector v1: { " 
              << v1[0] << ", " << v1[1] << ", " << v1[2] 
              << " }\n";
    std::cout << "Vector v2: { " 
              << v2[0] << ", " << v2[1] << ", " << v2[2] 
              << " }\n\n";
    
    std::cout << "Dot product of v1 and v2: " << dot << "\n";
    std::cout << "||v1|| = " << norm1 << "\n";
    std::cout << "||v2|| = " << norm2 << "\n";

    return 0;
}