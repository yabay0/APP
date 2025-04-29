#include <iostream>

int main() {
    int x = 5;
    int y = 10;

    int* p = &x;
    int* q = &y;

    std::cout << "Before swap: x = " << x << ", y = " << y << "\n";

    int* temp = new int;

    *temp = *p; 
    *p    = *q; 
    *q    = *temp; 

    delete temp;

    std::cout << "After  swap: x = " << x << ", y = " << y << "\n";
    return 0;
}
