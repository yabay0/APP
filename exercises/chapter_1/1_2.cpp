#include <iostream>

int main(int argc, char* argv[])
{
    /* This program takes two integers as input from the user,
    calculates their product, and prints the result */

    int a, b;

    std::cout << "Enter two integers: ";
    std::cin >> a >> b;

    int product = a * b;

    std::cout << "The product of " << a << " and " << b << " is " << product << std::endl;

    return 0;
}