//Kevin Youngerman
//Project1: Blood Sugar

#include <iostream>
#include "LList.h"
#include "DAY.H"
#include "Week.h"
#include <string>
#include <cstdlib>

using namespace std;


bool isNumber(string input)                             //determines if a string is a number or not. this function
{                                                       //is defined up here to try to make int main more readable.
    for (int i = 0; i < input.length(); i++)
    {
        if (!isdigit(input[i])) //check if the current character is a digit
        {
            if (input[i] != '.' && input[i] != '\0') //a . is valid, and the null terminator \0 is also valid
            {
                return false;   //if it is anything other than those two, the string is not a number
            }                   //however, this functions allows more than one decimal point, which we correct
        }                       //for in main()
    }
        return true;
}



int main()
{
	double bloodSugar;
	string userInput;
	int currentDay = 0;
	bool week1Complete = false, week2Complete = false;

	Week* week1 = new Week();
	Week* week2 = new Week();
	Week* currentWeek = week1;

	while (week2Complete == false) //loop until all data has been filled out
	{
		if (week1Complete == true)
		{
			currentWeek = week2;
		}
		currentDay = 0; //0 =  sunday

		//This is the driver for the program. It ends when the last day of the week has been passed
		while (currentDay < 7)
		{
		    cout << "Current day is: " << currentWeek->printDayName(currentDay) << endl << endl;
			cout << "D or Day = daily summary \nW or Week = Weekly summary\nN or Next = next day\nOr simply input a blood sugar number" << endl;
			cin >> userInput;
			cout << endl;
			cout << endl;
			char *tempArray = const_cast<char*>(userInput.c_str()); //turn the string into a char array, for use in the strtod() function

			if (isNumber(userInput) == true)
			{
				int dotCount = 0;   //we need to count the number of decimal points to make sure that number is still valid
				for (int i = 0; i < userInput.length(); i++)
				{
					if (!isdigit(userInput[i]))
					{
						if (userInput[i] == '.')
						{
							dotCount++;
						}
					}
				}
				if (dotCount < 2 && strtod(tempArray, '\0') > 0) //strtod() converts a string to a double
				{
					bloodSugar = strtod(tempArray, '\0');
					currentWeek->append(currentDay, bloodSugar);
				}
			}
			else
			{
				for (unsigned int i = 0; i < userInput.length(); i++)
				{
					userInput[i] = tolower(userInput[i]); //turns user input into lowercase, so that any combination of upper and lower works
				}
				userInput = tempArray;

				if (userInput == "d" || userInput == "day") //if the user enters 'd' or 'day', print daily summary
				{
					currentWeek->printDailySummary(currentDay);
;				}

				else if (userInput == "w" || userInput == "week") //if the user enters 'w' or 'week', print weekly summary
				{
					currentWeek->printSummary();
				}

				else if (userInput == "n" || userInput == "next") //if the user enters 'n' or 'next', move onto the next day
				{
					currentDay++;
				}

			}

		}

		if(currentWeek->calcNumOfDays() == 7 && week1Complete == false) //if num of days = 7, the week is complete
        {
            week1 = currentWeek; //store week 1
            currentWeek = week2; //move to week 2
            week1Complete = true;
            cout << endl << "--------Week 2----------" << endl << endl;
        }
        if(currentWeek->calcNumOfDays() == 7 && week1Complete == true)
        {
            week2 = currentWeek; //store week 2
            week2Complete = true; //exit loop, complete program
        }
	}
	//after the user steps through week 1 & 2, print a summary of both weeks
	cout << "*********Max Input Reached. Showing Week 1 and Week 2 summary**********" << endl << endl;
	week1->printSummary();
	week2->printSummary();

    delete week1;
    delete week2;
    return 0;



}

