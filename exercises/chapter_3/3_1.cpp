#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

int main() {
    double x[4] = {0.0, 1.0, 1.0, 0.0};
    double y[4] = {0.0, 0.0, 1.0, 1.0};

    const std::string filename = "x_and_y.dat";

    // 4) Check for existing file
    std::ifstream infile(filename);
    bool exists = infile.good();
    infile.close();

    std::ios_base::openmode mode = std::ios::out;
    if (exists) {
        std::cout << "File '" << filename << "' already exists.\n";
        std::cout << "Enter 'e' to erase or 'a' to append: ";
        char choice;
        std::cin >> choice;
        if (choice == 'a' || choice == 'A') {
            mode |= std::ios::app;  // append
        } else {
            mode |= std::ios::trunc; // erase
        }
    } else {
        mode |= std::ios::trunc;
    }

    // Open the output file
    std::ofstream outfile(filename, mode);
    if (!outfile) {
        std::cerr << "Error opening '" << filename << "' for writing.\n";
        return 1;
    }

    // 3) Format: 10 significant figures, scientific, show plus signs
    outfile << std::scientific
            << std::showpos
            << std::setprecision(10);

    // 1 & 2) Write x array on first line, flush
    for (int i = 0; i < 4; ++i) {
        outfile << x[i] << (i < 3 ? ' ' : '\n');
    }
    outfile.flush();

    for (int i = 0; i < 4; ++i) {
        outfile << y[i] << (i < 3 ? ' ' : '\n');
    }
    outfile.flush();

    outfile.close();
    std::cout << "Data written to '" << filename << "'.\n";
    return 0;
}