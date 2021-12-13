#include "../include/Figure.h"
#include <cmath>

void Figure::showName() {
    cout<<"Nazwa figury: "<<name<<"\nKolor figury: "<<color;
}

Square::Square(double a) : a(a) {}

double Square::getArea() {
    return a*a;
}

double Square::getCircuit() {
    return 4*a;
}

Rectangle::Rectangle(double a, double b) : a(a), b(b) {}

double Rectangle::getArea() {
    return a*b;
}

Circle::Circle(double r) : r(r) {}

double Circle::getArea() {
    return 3.14*pow(r, 2);
}


