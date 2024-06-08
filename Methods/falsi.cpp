//
// Created by Maciej on 08.06.2024.
//

#include "falsi.h"
#include "functions.h"
#include <cmath>

double falsi(double a, double b, double epsilon) {
    double fa = f(a);
    double fb = f(b);
    double c = a;
    double fc = fa;

    while (fabs(fc) > epsilon) {
        c = a - fa * (a - b) / (fa - fb);
        fc = f(c);
        if (fc * fa < 0) {
            b = c;
            fb = fc;
        } else if (fc * fb < 0) {
            a = c;
            fa = fc;
        }
    }
    return c;
}

