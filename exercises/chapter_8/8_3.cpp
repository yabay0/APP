#include <iostream>
#include <vector>
#include <cassert>

class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    Complex(const Complex& other) {
        real = other.real;
        imag = other.imag;
        std::cout << "Copy constructor called!" << std::endl;
    }

    double getReal() const { return real; }
    double getImag() const { return imag; }

    void display() const {
        std::cout << real << " + " << imag << "i" << std::endl;
    }
};

int main() {
    std::vector<Complex> complexNumbers;

    Complex c1(3.0, 4.0);
    Complex c2(5.0, 6.0);

    complexNumbers.push_back(c1);
    complexNumbers.push_back(c2);

    for (std::vector<Complex>::const_iterator it = complexNumbers.begin(); it != complexNumbers.end(); ++it) {
        it->display();
    }

    return 0;
}
