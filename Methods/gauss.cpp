//
// Created by Maciej on 08.06.2024.
//

#include "gauss.h"
#include "functions.h"
#include <cmath>

double gauss(double x0, double epsilon) {
    double x1 = f(x0);
    while (fabs(x1 - x0) > epsilon) {
        x0 = x1;
        x1 = f(x0);
    }
    return x1;
}

