#include <iostream>
#include "Node.h"

using namespace std;

int main() {

    double result;

    Node points1(3, 5), points2(1, 5);
    points1.display();
    points2.display();
    result = pointsDistance(points1, points2);


    cout<<"Odleglosc miedzy punktami = "<<result;

    return 0;
}
