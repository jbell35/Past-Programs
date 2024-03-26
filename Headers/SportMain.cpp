//****************************************************************************************************
//  File:           SportMain.cpp
//
//  Student:        Jamari Bell
//
//  Assignment:     Program #12
//
//  Course Name:    Computer Programming II
//
//  Course Number:  COSC 1560 - 01
//
//  Due:            December 8th, 2023
//
//  This program is the same as program 11, except this time we a header file, Sport.cpp to define 
//  the functions, use inline functions within the Sport.h file,  use a constructor, destructor, 
//  prompts the user for the number of Sports, and gives a preprogrammed date if user provides an
//  invalid one. 
//
//****************************************************************************************************

#include "Sport.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std; 

void sportOperations(Sport s[], int size);
void avgNumTeams(Sport s[], int size);
void displayEarliestSport(Sport s[], int size);
string findEarliestSport(Sport s[], int size);
void displaySports(const Sport s[], int size);

//****************************************************************************************************

int main()
{
    int size; 
    Sport * s;

    cout << " Enter how many sports you would like to process: ";
    cin >> size; 

    s = new Sport[size];

    sportOperations(s, size);

    delete [] s;
    s = nullptr; 

    return 0;
}

//****************************************************************************************************

void displayEarliestSport(Sport s[], int size)
{

    cout << "The sport with the earliest date is: " << findEarliestSport(s, size) << endl;
}

//****************************************************************************************************

string findEarliestSport(Sport s[], int size)
{
    Date orig,
         temp; 
    
    int tracker = 0; 

    for (int i = 1; i < size; i++)
    {
        orig = s[0].getDate();
        temp = s[i].getDate();

        if (temp.year < orig.year)
        {
            tracker = i;
        }
        else if (temp.month < orig.month)
        {
            tracker = i;
        }
        else if (temp.day < orig.day)
        {
            tracker = i;
        }
        
    }
    return s[tracker].getSportName();

}

//****************************************************************************************************

void sportOperations(Sport s[], int size)
{
    char choice,
         again;
    string name;

    do
    {
        cout << "\t\tHere are your options: " << endl
                << "=====================================================" << endl 
                << "a) Populate your sport(s) "  << endl
                << "b) Display all " << endl
                << "c) Update a particular sport" << endl
                << "d) Display a particular sport" << endl
                << "e) Display average number of teams " << endl
                << "f) Display sport scheduled at earliest date" << endl << endl;

        cin >> choice; 
        cin.ignore();
        choice = tolower(choice);

        switch (choice)
        {
            case 'a': 
                for (int i = 0; i < size; i++)
                {
                    s[i].populateArray();
                }
                break;
            case 'b':
                displaySports(s, size);
            /*
                for (int i = 0; i < 1; i++)
                {
                    s[i].displaySports(s, size); // if i put display sports back in Sport.h
                }
            */
                break;
            case 'c':
                cout << "Enter the name of the sport you would like to update: ";
                getline (cin, name); 

                for (int i = 0; i < size; i++)
                {
                    if (name == s[i].getSportName())
                    {
                        s[i].populateArray();
                    }
                }
                break;

            case 'd':
                cout << "Enter the name of the Sport you would like to display: ";
                getline(cin, name);

                for (int i = 0; i < size; i++)
                {
                    if (name == s[i].getSportName())
                    {
                        s[i].displaySpecific();
                    }
                }
                break;
            
            case 'e':
                avgNumTeams(s, size);
                break;
            
            case 'f':
                displayEarliestSport(s, size);
                break;
        }

        cout << "Would you like to choose another option? Enter 'y' for yes or 'n' for no: ";
        cin >> again; 
        again = tolower(again);

        if (again != 'y' && again != 'n')
        {
            cout << "Enter either 'y' for yes or 'n' for no: ";
            cin >> again;
        }
        else if (again == 'n')
        {
            cout << "This program has ended." << endl;
        }
    } 
    while (again == 'y');
    
}

//****************************************************************************************************

void avgNumTeams(Sport s[], int size)
{
    double avg;
    int total = 0;  

    for (int i = 0; i < size; i++)
    {
        total +=  s[i].getNumTeams();
    }

    avg = static_cast<double>(total/size); 

    cout << "The average number of teams is: " << avg << endl;

}

//****************************************************************************************************

void displaySports(const Sport s[], int size)
{
    for (int i = 0; i < size; i++)
    {
        s[i].displayAll();
    }

}

//****************************************************************************************************

/*
 Enter how many sports you would like to process: 4
                Here are your options: 
=====================================================
a) Populate your sport(s) 
b) Display all 
c) Update a particular sport
d) Display a particular sport
e) Display average number of teams 
f) Display sport scheduled at earliest date

a
Enter the name of the sport: Soccer
Enter the date for the scheduled game
(Note: the month, day, and year must be valid. Or else a default date will be set)
===================================================================================
Enter the month: 9
Enter the day: 2
Enter the year: 2024


Enter the number of teams for this sport: 
2
Enter team 1's name: St Louis 

Enter team 2's name: Jays

Enter the name of the sport: Basketball
Enter the date for the scheduled game
(Note: the month, day, and year must be valid. Or else a default date will be set)
===================================================================================
Enter the month: 3
Enter the day: 1
Enter the year: 2050


Enter the number of teams for this sport: 
3
Enter team 1's name: Heat

Enter team 2's name: Warriors

Enter team 3's name: Celtics

Enter the name of the sport: Football
Enter the date for the scheduled game
(Note: the month, day, and year must be valid. Or else a default date will be set)
===================================================================================
Enter the month: 0
Enter the day: 8
Enter the year: 1999


Enter the number of teams for this sport: 
1
Enter team 1's name: Chiefs

Enter the name of the sport: Hockey
Enter the date for the scheduled game
(Note: the month, day, and year must be valid. Or else a default date will be set)
===================================================================================
Enter the month: 3
Enter the day: 9
Enter the year: 2017


Enter the number of teams for this sport: 
2
Enter team 1's name: Blues

Enter team 2's name: Cardinals

Would you like to choose another option? Enter 'y' for yes or 'n' for no: y
                Here are your options: 
=====================================================
a) Populate your sport(s) 
b) Display all 
c) Update a particular sport
d) Display a particular sport
e) Display average number of teams 
f) Display sport scheduled at earliest date

b
All the information for the sport: Soccer
=======================================
The date scheduled: 9/2/2024

The number of teams in the sport: 2

The names of the teams: 
Team 1 : St Louis 
Team 2 : Jays

All the information for the sport: Basketball
=======================================
The date scheduled: 3/1/2050

The number of teams in the sport: 3

The names of the teams: 
Team 1 : Heat
Team 2 : Warriors
Team 3 : Celtics

All the information for the sport: Football
=======================================
The date scheduled: 1/1/2000

The number of teams in the sport: 1

The names of the teams: 
Team 1 : Chiefs

All the information for the sport: Hockey
=======================================
The date scheduled: 3/9/2017

The number of teams in the sport: 2

The names of the teams: 
Team 1 : Blues
Team 2 : Cardinals

Would you like to choose another option? Enter 'y' for yes or 'n' for no: y
                Here are your options: 
=====================================================
a) Populate your sport(s) 
b) Display all 
c) Update a particular sport
d) Display a particular sport
e) Display average number of teams 
f) Display sport scheduled at earliest date

d
Enter the name of the Sport you would like to display: Hockey
All the information for the sport: Hockey
=======================================
The date scheduled: 3/9/2017

The number of teams in the sport: 2

The names of the teams: 
Team 1 : Blues
Team 2 : Cardinals

Would you like to choose another option? Enter 'y' for yes or 'n' for no: y
                Here are your options: 
=====================================================
a) Populate your sport(s) 
b) Display all 
c) Update a particular sport
d) Display a particular sport
e) Display average number of teams 
f) Display sport scheduled at earliest date

e
The average number of teams is: 2
Would you like to choose another option? Enter 'y' for yes or 'n' for no: y
                Here are your options: 
=====================================================
a) Populate your sport(s) 
b) Display all 
c) Update a particular sport
d) Display a particular sport
e) Display average number of teams 
f) Display sport scheduled at earliest date

f
The sport with the earliest date is: Hockey
Would you like to choose another option? Enter 'y' for yes or 'n' for no: y
                Here are your options: 
=====================================================
a) Populate your sport(s) 
b) Display all 
c) Update a particular sport
d) Display a particular sport
e) Display average number of teams 
f) Display sport scheduled at earliest date

c
Enter the name of the sport you would like to update: Football
Enter the name of the sport: Football
Enter the date for the scheduled game
(Note: the month, day, and year must be valid. Or else a default date will be set)
===================================================================================
Enter the month: 2
Enter the day: 4
Enter the year: 2020


Enter the number of teams for this sport: 
1
Enter team 1's name: Chiefs

Would you like to choose another option? Enter 'y' for yes or 'n' for no: y
                Here are your options: 
=====================================================
a) Populate your sport(s) 
b) Display all 
c) Update a particular sport
d) Display a particular sport
e) Display average number of teams 
f) Display sport scheduled at earliest date

b
All the information for the sport: Soccer
=======================================
The date scheduled: 9/2/2024

The number of teams in the sport: 2

The names of the teams: 
Team 1 : St Louis 
Team 2 : Jays

All the information for the sport: Basketball
=======================================
The date scheduled: 3/1/2050

The number of teams in the sport: 3

The names of the teams: 
Team 1 : Heat
Team 2 : Warriors
Team 3 : Celtics

All the information for the sport: Football
=======================================
The date scheduled: 2/4/2020

The number of teams in the sport: 1

The names of the teams: 
Team 1 : Chiefs

All the information for the sport: Hockey
=======================================
The date scheduled: 3/9/2017

The number of teams in the sport: 2

The names of the teams: 
Team 1 : Blues
Team 2 : Cardinals

Would you like to choose another option? Enter 'y' for yes or 'n' for no: n
This program has ended.
*/
