//Kevin Youngerman
//Project1: Blood Sugar

#include "Day.h"
#include <iostream>

 Day::Day() // Default constructor. Doesn't need to do anything special.
 {

 }

Day::~Day() //destructor
{
	delete this;
}


int Day::size() //returns the number of elements in the linked list for this day
{
    int size = 0;
	if (!userInputData.isEmpty())
	{
		Node* ptr = userInputData.head;
		while (ptr != 0)
		{
			size += 1;
			ptr = ptr->next;
		}
	}

	return size;
}

double Day::calcSum() //calculates the sum for all elements in the linked list
{
    sum = 0;
	if (!userInputData.isEmpty())
	{
		Node *ptr = userInputData.head;
		while (ptr != 0)
		{
			sum += ptr->getData();
			ptr = ptr->next;
		}
	}
	return sum;

}

double Day::calcMax()  //calculates the maximum value
{
    max = -10; //maximum is set to a negative number initally, since blood sugar can't be negative
	if (!userInputData.isEmpty())
	{
		Node *ptr = userInputData.head; //ptr is the first element (the head)
		if(ptr->getData() > max) //if ptr > current maximum, then new maximum = ptr
            {
                max = ptr->getData();
            }
		while (ptr->next != 0) //while not at end of list
		{
		    ptr = ptr->next;
			int tempMax = ptr->getData(); 
			if(tempMax > max) //if ptr > max, new max = ptr
            {
                max = tempMax;
            }

		}
	}
	return max;
}

double Day::calcMin()  //calculates the minimum value
{
    min = 99999999999; // the default min is set to a high number, so that the usual inputs will be lower than it
	if (!userInputData.isEmpty())
	{
		Node *ptr = userInputData.head; //this function works the same as calcMax, 
		if(ptr->getData() < min)		//only it checks if ptr < min 
            {
                min = ptr->getData();
            }
		while (ptr->next != 0)
		{
			int tempMin = ptr->getData();
			if(tempMin < min)
            {
                min = tempMin;
            }
            ptr = ptr->next;
		}
	}
	return min;
}


void Day::removeHead()                      //These functions are just copies of the ones in LList
{                                           //calling those functions directly did not give correct results,
	userInputData.removeHead();             //however, the solution here works
}
bool Day::isEmpty()
{
   return userInputData.isEmpty();
}
void Day::append(double input)
{
    userInputData.append(input);
}
void Day::print()   //prints the summary of the whole day
{
     std::cout << std::endl << "-------Daily Summary-----------" << std::endl << std::endl;
    std::cout << "The total number of valid inputs for the day is " << size() << std::endl;
    std::cout << "The total sum for the day is " << calcSum() << std::endl;
    std::cout << "The max for the day is " << calcMax() << std::endl;
    std::cout << "The min for the day is " << calcMin() << std::endl;
    std::cout << std::endl << "--------------------------" << std::endl << std::endl;
}

