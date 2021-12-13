#include <iostream>
#include "../include/Figure.h"

using namespace std;

int main() {

    Figure *circle = new Circle(5);
    Figure *rectangle = new Rectangle(5, 18);
    Square *square = new Square(5);

    cout << "Circle area: " << circle->getArea() << endl;
    cout << "Rectangle area: " << rectangle->getArea() << endl;
    cout << "Square area: " << square->getArea() << endl;
    cout << "Square circuit: " << square->getCircuit() << endl;
}
