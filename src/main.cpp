#include <iostream>
#include "Node.h"
#include "Vector.h"
#include <cmath>

using namespace std;

int main() {

    double result;

    Node points1(3, 5), points2(1, 5);
    points1.display();
    points2.display();
    result = pointsDistance(points1, points2);

    cout<<"Odleglosc miedzy punktami = "<<result;

    Vector v1, v2(5,10);
    Vector v3 = v1 + v2;
    v3 = v1.operator+(v2);

    return 0;
}
