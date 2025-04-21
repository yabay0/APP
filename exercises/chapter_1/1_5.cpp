#include <iostream>
#include <string>

int main() {
    std::string givenName;
    std::string familyName;

    /* Prompt for given name */
    std::cout << "Enter your given name: ";
    std::getline(std::cin, givenName);

    /* Prompt for family name */
    std::cout << "Enter your family name: ";
    std::getline(std::cin, familyName);

    /* Print full name */
    std::cout << "Your full name is: "
              << givenName << " " << familyName
              << std::endl;

    return 0;
}