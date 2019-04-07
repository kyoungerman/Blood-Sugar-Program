//Kevin Youngerman
//Project1: Blood Sugar

#include "Node.h"
#include <iostream>

//Default Constructor
Node::Node()
 {
     data = NULL;
     next = NULL;
 }


 //Constructor with a value , but no pointer to next
Node::Node(double newData)
{
    data =  newData;
    next = NULL;
}

 //Constructor with value and next pointer
Node::Node(double newData, Node* newNext)
{
    data =  newData;
    next = newNext;
}

//Accessors for node data
double Node::getData() const
{
    return data;
}

