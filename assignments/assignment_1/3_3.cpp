#include "3_3.h"
#include <fstream>
#include <cassert>

void implicit_Euler(int n) {
    assert(n > 1);
    double h = 1.0/(n-1), y_prev = 1.0;
    std::ofstream out("xy.dat");
    assert(out);
    for (int i = 0; i < n; ++i) {
        double x = i*h;
        double y = (i==0 ? y_prev : y_prev/(1.0+h));
        out << x << "," << y << "\n";
        y_prev = y;
    }
}