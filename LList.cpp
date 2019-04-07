//Kevin Youngerman
//Project1: Blood Sugar

#include "LList.h"
#include <iostream>

LList::LList() //default constructor
{
    head = NULL;
}

LList::~LList() //destructor
{
    while(!isEmpty())
    {
        removeHead();
    }
}

bool LList::isEmpty() // checks if the list is empty
{
    return head == NULL;
}


void LList::append(double data) //append is tho only way to add to the list
{                            //it is also the only way we need since data order won't
    if(isEmpty())            //matter for our purposes
    {
        head = new Node(data);
        head->next = NULL;
    }
    else{
		Node *tempPointer = head;           //temp pointer = current node
		Node *lastPointer = tempPointer;    //last pointer = previous node
		tempPointer = tempPointer->next;

		while (tempPointer != NULL)
		{

			lastPointer = tempPointer;
			tempPointer = tempPointer->next;
		}
		lastPointer->next = new Node(data,tempPointer);
    }
}

void LList::removeHead()  //removes the head, an makes head->next the new head of the list
{

	Node * tempPtr = head;
	head = head->next;
	delete tempPtr;
}




