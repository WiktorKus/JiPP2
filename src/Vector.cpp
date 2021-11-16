#include <cmath>
#include <iostream>
#include "Vector.h"


    Vector::Vector(double x, double y) : x(x), y(y) {}

    double Vector::length() {
        return sqrt(x * x + y * y);
    }




