//
// Created by Maciej on 08.06.2024.
//

#include "bisection.h"
#include "functions.h"
#include <cmath>

double bisection(double a, double b, double epsilon) {
    double c = (a + b) / 2;
    while (fabs(b - a) > epsilon) {
        if (f(c) == 0.0)
            return c;
        else if (f(c) * f(a) < 0.0)
            b = c;
        else
            a = c;
        c = (a + b) / 2;
    }
    return c;
}

