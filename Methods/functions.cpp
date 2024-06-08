//
// Created by Maciej on 08.06.2024.
//

#include "functions.h"
#include <cmath>

double f(double x) {
    return exp(-x * x);
}

double func(double x) {
    return x * x * x - x * x - 3.75 * x + 4.5;
}

double derivFunc(double x) {
    return 3 * x * x - 2 * x - 3.5;
}
