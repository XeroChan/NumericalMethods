// Created by Maciej on 08.06.2024.
#include <iostream>
#include <vector>
#include <iomanip>
#include <valarray>
#include "functions.h"
#include "lagrange.h"
#include "newton_interpolation.h"
#include "cubic_spline.h"
#include "falsi.h"
#include "muller.h"
#include "newton_raphson.h"
#include "golden_ratio.h"
#include "bisection.h"
#include "gauss.h"

using namespace std;

int main() {
    // Przyk³ad u¿ycia Lagrange oraz Newton interpolation
    vector<double> x = {-2.0, -1.0, 0.0, 1.0, 2.0, 3.0};
    vector<double> y(x.size());
    for (size_t i = 0; i < x.size(); ++i) {
        y[i] = exp(-x[i] * x[i]);
    }

    vector<double> b = computeDividedDifferences(x, y);

    cout << "Wspó³czynniki b_k:\n";
    for (size_t i = 0; i < b.size(); ++i) {
        cout << "b[" << i << "] = " << b[i] << endl;
    }

    vector<double> points = {-1.0, -0.5, 0.0, 0.5, 1.0};
    cout << fixed << setprecision(6);
    cout << "\n x\t\tf(x)\t\tLagrange(x)\tNewton(x)\n";
    cout << "-------------------------------------------------------\n";

    for (double xi : points) {
        double fxi = exp(-xi * xi);
        double lagrange = lagrangeInterpolation(x, y, xi);
        double newton = newtonInterpolation(x, b, xi);

        cout << xi << "\t\t" << fxi << "\t\t" << lagrange << "\t\t" << newton << endl;
    }

    // Przyk³ad u¿ycia Cubic Spline
    x = { 0.0, 1.0, 2.0, 3.0, 4.0 };
    y = { 0.0, 1.0, 0.0, 1.0, 0.0 };
    vector<double> a(x.size()), b_spline(x.size()), c(x.size()), d(x.size());
    cubic_spline(x, y, a, b_spline, c, d);
    for (double xi = 0.0; xi <= 4.0; xi += 0.1) {
        cout << xi << "\t" << cubic_spline_interpolate(xi, x, y, a, b_spline, c, d) << endl;
    }

    // Przyk³ad u¿ycia Falsi i Muller
    double g = -2; // lewy kraniec
    double h = 2; // prawy kraniec
    double epsilon = 1e-5;
    double x0 = 0;
    double x1 = 5;
    double x2 = 2;

    double mZ_falsi = falsi(g, h, epsilon);
    double mZ_muller = muller(x0, x1, x2, epsilon);

    cout << "Metoda falsi miejsce zerowe: " << mZ_falsi << " wartosc f(x): " << f(mZ_falsi) << endl;
    cout << "Metoda Mullera miejsce zerowe: " << mZ_muller << " wartosc f(x): " << f(mZ_muller) << " .Punkty pocz¹tkowe (x0,x1,x2) = " << x0 << " " << x1 << " " << x2 << endl;

    // Przyk³ad u¿ycia Newton-Raphson, Golden Ratio, Bisection i Gauss
    double x_init = 10; // Initial values assumed
    cout << "Rhapson x " << x_init << " Rhapson final x " << newtonRaphson(x_init) << " Rhapson f(x) " << func(newtonRaphson(x_init));

    return 0;
}
