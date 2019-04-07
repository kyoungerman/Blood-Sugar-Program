//Kevin Youngerman
//Project1: Blood Sugar

#ifndef DAY_H
#define DAY_H
#include "LList.h"

class Day: public LList
{
private:
	LList userInputData; //A linked list to store the blood sugar data for each day

    double sum = 0;
    double min = 0;
    double max = 0;
    int count = 0;

public:
    Day();
    ~Day();

    int size();
    double calcSum();
    double calcMax();
    double calcMin();

    void removeHead();
    bool isEmpty();
    void append(double); //add to the end of the list
    void print();
};



#endif // DAY_H
