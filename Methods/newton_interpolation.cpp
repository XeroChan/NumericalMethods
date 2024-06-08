//
// Created by Maciej on 08.06.2024.
//

#include "newton_interpolation.h"

std::vector<double> computeDividedDifferences(const std::vector<double>& x, const std::vector<double>& y) {
    int n = x.size();
    std::vector<double> b(n);

    for (int k = 0; k < n; ++k) {
        double numerator = y[k];
        double denominator = 1.0;

        for (int j = 0; j < k; ++j) {
            denominator *= (x[k] - x[j]);
        }

        b[k] = numerator / denominator;
    }

    return b;
}

double newtonInterpolation(const std::vector<double>& x, const std::vector<double>& b, double xi) {
    int n = x.size();
    double yi = 0.0;

    for (int k = 0; k < n; ++k) {
        double pk = 1.0;
        for (int j = 0; j < k; ++j) {
            pk *= (xi - x[j]);
        }
        yi += b[k] * pk;
    }

    return yi;
}

