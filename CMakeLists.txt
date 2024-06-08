cmake_minimum_required(VERSION 3.28)
project(NumericalMethods)

set(CMAKE_CXX_STANDARD 26)

add_executable(NumericalMethods
        "Methods/Methods.cpp"
        Methods/functions.cpp
        Methods/functions.h
        Methods/lagrange.cpp
        Methods/lagrange.h
        Methods/newton_interpolation.cpp
        Methods/newton_interpolation.h
        Methods/cubic_spline.cpp
        Methods/cubic_spline.h
        Methods/falsi.cpp
        Methods/falsi.h
        Methods/muller.cpp
        Methods/muller.h
        Methods/newton_raphson.cpp
        Methods/newton_raphson.h
        Methods/golden_ratio.cpp
        Methods/golden_ratio.h
        Methods/bisection.cpp
        Methods/bisection.h
        Methods/gauss.cpp
        Methods/gauss.h
)
