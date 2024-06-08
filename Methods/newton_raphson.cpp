//
// Created by Maciej on 08.06.2024.
//

#include "newton_raphson.h"
#include "functions.h"
#include <cmath>

double newtonRaphson(double x) {
    double eps = pow(10, -5);
    double h = func(x) / derivFunc(x);
    while (fabs(h) >= eps) {
        h = func(x) / derivFunc(x);
        x = x - h;
    }
    return x;
}

