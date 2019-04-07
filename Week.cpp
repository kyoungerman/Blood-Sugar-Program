//Kevin Youngerman
//Project1: Blood Sugar

#include "Week.h"
#include <iostream>

Week::Week() //constructor
{
    dayList = new Day[7]; //only need 7 days in our array
}
Week::~Week()
{
	delete this;
}

void Week::append(int index, double inputValue)
{
    dayList[index].append(inputValue);
}

////Calculation Functions//////

double Week::calcWeeklySum() //calculate the total sum of the week
{
	weeklySum = 0;
	for (int i = 0; i < 7; i++)
	{
		weeklySum = weeklySum + dayList[i].calcSum();
	}
	return weeklySum;
}

double Week::calcWeeklyMin() //calculate the minimum of the week
{
	weeklyMin = 99999999999999999;
	for (int i = 0; i < 7; i++)
	{
		double tempMin = dayList[i].calcMin();
		if (tempMin < weeklyMin && !dayList[i].isEmpty())
		{
			weeklyMin = tempMin;
		}
	}
	return weeklyMin;
}

double Week::calcWeeklyMax() //calculate the maximum of the week
{
	weeklyMax = -1;
	for (int i = 0; i < 7; i++)
	{
		double tempMax = dayList[i].calcMax();
		if (tempMax > weeklyMax)
		{
			weeklyMax = tempMax;
		}
	}
	return weeklyMax;
}

double Week::calcWeeklyCount() //calculate total number of data items for the week
{
	weeklyTotalCount = 0;
	for (int i = 0; i < 7; i++)
	{
		weeklyTotalCount += dayList[i].size();
	}
	return weeklyTotalCount;
}
int Week::calcNumOfDays() //calculate the number of days in the week. Ideally, this would always be 7,
{                         //but this function can make sure of that
    numOfDays = 0;
	for (int i = 0; i < 7; i++)
	{
		if(!dayList[i].isEmpty())
        {
            numOfDays++;
        }
	}
	return numOfDays;
}

double Week::calcWeekDelta() // calculate the largest delta |count
{
	largestDelta = 0;
	double tempDelta;
	double tempDelta2;
	for (int i = 0; i < 7; i++)
	{

		tempDelta = (dayList[i].size() - dayList[i + 1].size());    //having 2 temp deltas ensures that the largest value,
		tempDelta2 = (dayList[i+1].size() - dayList[i].size());     //positive or negative, is the largest delta
		if(tempDelta > largestDelta)
		{
			largestDelta = tempDelta;
			deltaHolder = i;
		}
		else if(tempDelta2 > largestDelta)
		{
			largestDelta = tempDelta2;
			deltaHolder = i;
		}
	}
	return largestDelta;
}

std::string Week::printDayName(int index) //just converts the array index into the name of a day
{
	if (index == 0) { return "Sunday"; }
	if (index == 1) { return "Monday"; }
	if (index == 2) { return "Tuesday"; }
	if (index == 3) { return "Wednesday"; }
	if (index == 4) { return "Thursday"; }
	if (index == 5) { return "Friday"; }
	if (index == 6) { return "Saturday"; }
}

void Week::printSummary()
{
    std::cout << std::endl << "-------Weekly Summary-----------" << std::endl << std::endl;
    std::cout << "The number of days is " << calcNumOfDays() << std::endl;
    std::cout << "The total number of valid inputs for the whole week is " << calcWeeklyCount() << std::endl;
    std::cout << "The total sum for the week is " << calcWeeklySum() << std::endl;
    std::cout << "The max for the week is " << calcWeeklyMax() << std::endl;
    std::cout << "The min for the week is " << calcWeeklyMin() << std::endl;
    std::cout << "The largest delta for the week is " << calcWeekDelta() << " and it occurs between the days " << printDayName(deltaHolder) << " and " << printDayName(deltaHolder + 1) << std::endl;
    std::cout << std::endl << "--------------------------" << std::endl << std::endl;
}

void Week::printDailySummary(int index) //prints the summary for a given day.
{                                       //not using print function by calling it on a day
	dayList[index].print();             //because doing that gave unexpected behavior under certain
}                                       //circumstances, and i could not fix it.




