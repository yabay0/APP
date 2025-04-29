#include "5_4.h"
#include <cmath>

double calc_mean(double a[], int length) {
    if (length <= 0) return 0.0;
    double sum = 0.0;
    for (int i = 0; i < length; ++i) sum += a[i];
    return sum / length;
}

double calc_std(double a[], int length) {
    if (length <= 1) return 0.0;
    double mu = calc_mean(a, length);
    double sumsq = 0.0;
    for (int i = 0; i < length; ++i) {
        double diff = a[i] - mu;
        sumsq += diff * diff;
    }
    return std::sqrt(sumsq / (length - 1));
}