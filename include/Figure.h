#ifndef LAB7_FIGURE_H
#define LAB7_FIGURE_H

#include <iostream>

using namespace std;

class Figure {
protected:
    string name;
    string color;

public:
    void showName();
    virtual double getArea() = 0;
};

class Square : public Figure {
protected:
    double a;
public:
    Square(double a);
    double getArea() override;
    double getCircuit();
};

class Rectangle : public Figure {
protected:
    double a, b;
public:
    Rectangle(double a, double b);
    double getArea() override;
};

class Circle : public Figure{
protected:
    double r;
public:
    Circle(double r);
    double getArea() override;
};
#endif //LAB7_FIGURE_H
