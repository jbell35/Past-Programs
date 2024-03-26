
#include "Sport.h"
#include <iostream>
#include <string>
using namespace std;

//****************************************************************************************************

Sport:: Sport(const string & n)
{
    setSportName(n);
    numTeams = 0;
    teamName = nullptr; 
}

//****************************************************************************************************

void Sport:: setDate(Date fullDate)
{

    
    if (fullDate.year < 2000 || fullDate.year > 2099)
    {
        dateSched.month = 1;
        dateSched.day = 1; 
        dateSched.year = 2000; 

    }
    else if (fullDate.month < 1 || fullDate.month > 12)
    {
        dateSched.month = 1;
        dateSched.day = 1; 
        dateSched.year = 2000; 
    }
    else if (fullDate.day < 1 || fullDate.day > 31)
    {
        dateSched.month = 1;
        dateSched.day = 1; 
        dateSched.year = 2000;
    }

/*  
    fullDate.month = dateSched.month; 
    fullDate.day = dateSched.day;
    fullDate.year = dateSched.year;
*/  

}

//****************************************************************************************************

void Sport::setNumTeams(int & num)
{
    if (num <= 0)
    {
        numTeams = 5;
        cout << "Invalid. The number of teams is set to 5" << endl << endl;
    }
    else
    {
        numTeams = num;
    }
    
}
 //****************************************************************************************************

void Sport:: populateArray() 
{
    teamName = nullptr;
    int month,
        day,
        year;
    
    cout << "Enter the name of the sport: ";
    getline(cin, sportName); 

    setSportName(sportName); 

    cout << "Enter the date for the scheduled game" << endl
         << "(Note: the month, day, and year must be valid. Or else a default date will be set)" << endl
         << "===================================================================================" << endl;
    
    cout << "Enter the month: ";
    cin >> month;
    cin.ignore();
    dateSched.month = month; 

    cout << "Enter the day: ";
    cin >> day; 
    cin.ignore();
    dateSched.day = day; 

    cout << "Enter the year: ";
    cin >> year; 
    cin.ignore();
    dateSched.year = year; 
    
    setDate(dateSched);
    
    cout << "\n\nEnter the number of teams for this sport: " << endl;
    cin >> numTeams; 
    cin.ignore(); 

    setNumTeams(numTeams); 

    teamName = new string[numTeams]; 

    for (int i = 0; i < numTeams; i++)
    {
        cout << "Enter team " << i + 1 << "'s name: ";
        getline(cin, teamName[i]);
        cout << endl;
    }
}

//****************************************************************************************************

void Sport:: displayAll() const
{

    cout << "All the information for the sport: " << getSportName() << endl
            << "=======================================" << endl;

    cout << "The date scheduled: " << dateSched.month << "/" << dateSched.day 
            << "/" << dateSched.year << endl << endl;

    cout << "The number of teams in the sport: " << getNumTeams() << endl << endl;

    cout << "The names of the teams: " << endl;

    for(int i = 0; i < getNumTeams(); i++)
    {
        cout << "Team " << i + 1 << " : " << teamName[i] << endl;
    }

    cout << endl;


}

//****************************************************************************************************

void Sport:: displaySpecific() const
{

    cout << "All the information for the sport: " << getSportName() << endl
             << "=======================================" << endl;

    cout << "The date scheduled: " << dateSched.month << "/" << dateSched.day 
            << "/" << dateSched.year << endl << endl;

    cout << "The number of teams in the sport: " << getNumTeams() << endl << endl;

    cout << "The names of the teams: " << endl;

    for(int i = 0; i < numTeams; i++)
    {
        cout << "Team " << i + 1 << " : " << teamName[i] << endl;
    }

    cout << endl;

}

//****************************************************************************************************
