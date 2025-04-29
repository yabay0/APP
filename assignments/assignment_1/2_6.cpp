#include "2_6.h"
#include <cmath>

double newton_Raphson(double initialGuess, double epsilon) {
    double x_prev = initialGuess;
    double x_next;

    while (true) {
        double fx  = std::exp(x_prev) + x_prev*x_prev*x_prev - 5.0;
        double dfx = std::exp(x_prev) + 3.0*x_prev*x_prev;
        if (dfx == 0.0) {
            return x_prev;
        }
        x_next = x_prev - fx/dfx;
        if (std::fabs(x_next - x_prev) < epsilon) {
            break;
        }
        x_prev = x_next;
    }
    return x_next;
}