//
// Created by Maciej on 08.06.2024.
//

#ifndef NUMERICALMETHODS_CUBIC_SPLINE_H
#define NUMERICALMETHODS_CUBIC_SPLINE_H


#include <vector>

using namespace std;

void cubic_spline(vector<double>& x, vector<double>& y, vector<double>& a, vector<double>& b, vector<double>& c, vector<double>& d);
double cubic_spline_interpolate(double x, vector<double>& xs, vector<double>& ys, vector<double>& a, vector<double>& b, vector<double>& c, vector<double>& d);


#endif //NUMERICALMETHODS_CUBIC_SPLINE_H
