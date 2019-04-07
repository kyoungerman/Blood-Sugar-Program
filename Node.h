//Kevin Youngerman
//Project1: Blood Sugar

#ifndef NODE_H
#define NODE_H
#include <iostream>

class Node
{
private:
    double data;  //the value to be stored
public:
    Node* next;
    Node();             // default constructor
    Node(double);       //constructor when only a data point is provided
    Node(double,Node*);  //constructor with a data point and a pointer to the next node
    double getData() const;  //retrieve the data
};

#endif
