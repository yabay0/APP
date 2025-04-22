#include <iostream>
#include <fstream>

int main() {
    std::ifstream read_file("x_and_y.dat");
    if (!read_file.is_open()) {
        std::cerr << "Failed to open x_and_y.dat\n";
        return 1;
    }

    int number_of_rows = 0;
    double d1, d2, d3, d4;

    while (read_file >> d1 >> d2 >> d3 >> d4) {
        ++number_of_rows;
    }

    std::cout << "Number of rows = " << number_of_rows << '\n';
    return 0;
}