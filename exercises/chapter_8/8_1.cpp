#include <iostream>
#include <iomanip> 

template <typename T>
T check_probability(T value) {
    if (value >= 0 && value <= 1) {
        return value;
    }
    else if (value >= -1e-6 && value < 0) {
        return 0;
    }
    else if (value > 1 && value <= 1 + 1e-6) {
        return 1;
    } 
    else {
        std::cerr << "Warning: Probability value " << value
                  << " is out of range and will be corrected." << std::endl;
        return (value < 0) ? 0 : 1;
    }
}

int main() {
    double probabilities[] = {0.5, -1e-7, 1.0000002, 1.2, -0.5, 0.9999999};
    size_t N = sizeof(probabilities) / sizeof(probabilities[0]);

    for (size_t i = 0; i < N; ++i) {
        double corrected_value = check_probability(probabilities[i]);
        std::cout << "Original: " << std::fixed << std::setprecision(8) << probabilities[i] 
                  << " Corrected: " << corrected_value << std::endl;
    }

    return 0;
}
