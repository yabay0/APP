#include <iostream>

int main() {
    /* Record counts for five consecutive days */
    int cars[5] = { 34, 58, 57, 32, 43 };

    /* Compute the sum */
    int sum = 0;
    for (int i = 0; i < 5; ++i) {
        sum += cars[i];
    }

    /* Compute the average */
    double average = sum / 5.0;

    /* Print result */
    std::cout << "Counts: ";
    for (int i = 0; i < 5; ++i) {
        std::cout << cars[i] << (i<4 ? ", " : "\n");
    }
    std::cout << "Average over 5 days: " << average << std::endl;

    return 0;
}