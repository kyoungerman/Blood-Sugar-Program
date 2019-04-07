//Kevin Youngerman
//Project1: Blood Sugar

#ifndef WEEK_H
#define WEEK_H
#include "Day.h"
#include <string>

class Week: public Day
{
private:
    Day* dayList;

    double weeklySum = 0;
    double weeklyMin = 0;
    double weeklyMax = 0;
    double weeklyTotalCount = 0;
	double largestDelta = 0;
	int numOfDays = 0;
	int deltaHolder = 0; //deltaHolder's only function is to hold the array index that the largest delta for
                        //the week occurs at, so that we can print to the user the days that it occurs on
public:
    Week();
    ~Week();

    void append(int, double);

    double calcWeeklySum();
    double calcWeeklyMin();
    double calcWeeklyMax();
    double calcWeeklyCount();
    int calcNumOfDays();
	double calcWeekDelta();

	std::string printDayName(int);
	void printSummary();
	void printDailySummary(int index);

};

#endif
