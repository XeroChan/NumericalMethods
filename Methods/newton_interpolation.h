//
// Created by Maciej on 08.06.2024.
//

#ifndef NUMERICALMETHODS_NEWTON_INTERPOLATION_H
#define NUMERICALMETHODS_NEWTON_INTERPOLATION_H


#include <vector>

using namespace std;

vector<double> computeDividedDifferences(const vector<double>& x, const vector<double>& y);
double newtonInterpolation(const vector<double>& x, const vector<double>& b, double xi);


#endif //NUMERICALMETHODS_NEWTON_INTERPOLATION_H
