#include <iostream>

void printValue(int* p) {
    std::cout << *p << std::endl;
}

int main() {
    int x = 42;
    printValue(&x);
    return 0;
}