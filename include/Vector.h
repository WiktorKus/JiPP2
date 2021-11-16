//
// Created by wiktor on 16.11.2021.
//

#ifndef LAB6_VECTOR_H
#define LAB6_VECTOR_H

class Vector {
private:
    double x, y;

public:
    Vector() {};

    Vector(double x, double y);

    double length();

    Vector operator+(const Vector &rhs) const {
        return {x + rhs.x, y + rhs.y};
    }

    Vector &operator+=(const Vector &rhs) {
        this->x = this->x + rhs.x;
        this->y = this->y + rhs.y;
        return *this;
    }


};

#endif //LAB6_VECTOR_H
