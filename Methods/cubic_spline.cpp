//
// Created by Maciej on 08.06.2024.
//

#include "cubic_spline.h"

using namespace std;

void cubic_spline(vector<double>& x, vector<double>& y, vector<double>& a, vector<double>& b, vector<double>& c, vector<double>& d) {
    int n = x.size();
    vector<double> h(n - 1), alpha(n - 1), l(n), mu(n - 1), z(n);
    for (int i = 0; i < n - 1; i++) {
        h[i] = x[i + 1] - x[i];
        alpha[i] = 3.0 * (y[i + 1] - y[i]) / h[i];
    }
    l[0] = 1.0;
    mu[0] = 0.0;
    z[0] = 0.0;
    for (int i = 1; i < n - 1; i++) {
        l[i] = 2.0 * (x[i + 1] - x[i - 1]) - h[i - 1] * mu[i - 1];
        mu[i] = h[i] / l[i];
        z[i] = (alpha[i - 1] - h[i - 1] * z[i - 1]) / l[i];
    }
    l[n - 1] = 1.0;
    z[n - 1] = 0.0;
    c[n - 1] = 0.0;
    for (int j = n - 2; j >= 0; j--) {
        c[j] = z[j] - mu[j] * c[j + 1];
        b[j] = (y[j + 1] - y[j]) / h[j] - h[j] * (c[j + 1] + 2.0 * c[j]) / 3.0;
        d[j] = (c[j + 1] - c[j]) / (3.0 * h[j]);
        a[j] = y[j];
    }
}

double cubic_spline_interpolate(double x, vector<double>& xs, vector<double>& ys, vector<double>& a, vector<double>& b, vector<double>& c, vector<double>& d) {
    int i = 0;
    while (xs[i + 1] < x) {
        i++;
    }
    double dx = x - xs[i];
    return a[i] + b[i] * dx + c[i] * dx * dx + d[i] * dx * dx * dx;
}

