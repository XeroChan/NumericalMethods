//
// Created by Maciej on 08.06.2024.
//

#include "golden_ratio.h"
#include "functions.h"
#include <cmath>

double golden_ratio(double a, double b, double epsilon) {
    double phi = (1 + sqrt(5)) / 2;
    double c = b - (b - a) / phi;
    double d = a + (b - a) / phi;
    while (fabs(b - a) > epsilon) {
        if (f(c) < f(d))
            b = d;
        else
            a = c;
        c = b - (b - a) / phi;
        d = a + (b - a) / phi;
    }
    return (a + b) / 2;
}

