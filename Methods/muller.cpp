//
// Created by Maciej on 08.06.2024.
//

#include "muller.h"
#include "functions.h"
#include <cmath>
#include <iostream>

using namespace std;

double muller(double x0, double x1, double x2, double tol) {
    double h1 = x1 - x0;
    double h2 = x2 - x1;
    double d1 = (f(x1) - f(x0)) / h1;
    double d2 = (f(x2) - f(x1)) / h2;
    double d3, a, b, c, x3, err;

    for (int i = 0; i < 100; i++) {
        c = f(x2);
        a = (d2 - d1) / (h2 + h1);
        b = a * h2 + d2;
        x3 = x2 - 2 * c / (b + sqrt(b * b - 4 * a * c));
        err = fabs(x3 - x2);

        if (err < tol) {
            return x3;
        }

        x0 = x1;
        x1 = x2;
        x2 = x3;

        h1 = x1 - x0;
        h2 = x2 - x1;
        d1 = (f(x1) - f(x0)) / h1;
        d2 = (f(x2) - f(x1)) / h2;
    }

    cout << "Nie uda³o siê znaleŸæ miejsca zerowego w 100 iteracjach." << endl;
}

