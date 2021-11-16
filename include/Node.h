//
// Created by wiktor on 16.11.2021.
//

#ifndef LAB6_NODE_H
#define LAB6_NODE_H

class Node {
private:
    double x, y;
    friend double pointsDistance(Node, Node);

public:
    Node();
    Node(double x, double y);

    void display();

    void updateValue(double x, double y);
   // friend double
};

double pointsDistance(Node a, Node b);

#endif //LAB6_NODE_H
