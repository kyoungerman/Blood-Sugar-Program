//Kevin Youngerman
//Project1: Blood Sugar

#ifndef LLIST_H
#define LLIST_H
#include "Node.h"


class LList: public Node
{
public:
    Node* head;             //head =  start of the list

    LList();                //constructor
    virtual ~LList();       //destructor

    bool isEmpty();         //checks if the list is empty
    void append(double);       //adds to the end of the list, creates head if list = empty
    void removeHead();      //removes the first element
};

#endif // LLIST_H
