#include <iostream>

void changeValue(int* p) {
    *p = 99;
}

int main() {
    int x = 42;
    changeValue(&x);
    std::cout << x << std::endl;
    return 0;
}