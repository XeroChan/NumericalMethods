//
// Created by Maciej on 08.06.2024.
//

#include "lagrange.h"

double lagrangeInterpolation(const std::vector<double>& x, const std::vector<double>& y, double xi) {
    double L0 = ((xi - x[1]) * (xi - x[2])) / ((x[0] - x[1]) * (x[0] - x[2]));
    double L1 = ((xi - x[0]) * (xi - x[2])) / ((x[1] - x[0]) * (x[1] - x[2]));
    double L2 = ((xi - x[0]) * (xi - x[1])) / ((x[2] - x[0]) * (x[2] - x[1]));

    double yi = L0 * y[0] + L1 * y[1] + L2 * y[2];

    return yi;
}

