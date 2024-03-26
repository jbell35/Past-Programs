
#ifndef SPORT_H
#define SPORT_H

//****************************************************************************************************

#include <iostream> 
#include <string> 

//****************************************************************************************************

struct Date
{
    int day;
    int month;
    int year;
};

class Sport
{
    private:
        std:: string sportName;
        int numTeams; 
        Date dateSched; 
        std:: string * teamName;
        
    public:
        std:: string getSportName() const; 
        void setSportName(const std::string & n); 

        int getDay() const;
        void setDay(int & da);
        int getMonth() const; 
        void setMonth(int & m);
        int getYear() const;
        void setYear(int & y);
        void setDate(Date fullDate);
        Date getDate() const;

        int getNumTeams() const; 
        void setNumTeams(int & num); 

        void populateArray();
        void displayAll() const;
        void displaySpecific() const;
        //void displaySports(const Sport s[], int size);
        
        Sport(const std::string & n =" ");
        ~Sport();
};

//****************************************************************************************************
inline
Sport:: ~Sport()
{
    delete [] teamName;
}

//****************************************************************************************************
inline
std:: string Sport:: getSportName() const
{
    return sportName;
}
//****************************************************************************************************
inline
void Sport::setSportName(const std::string & n)
{
    sportName = n;
}

//****************************************************************************************************
inline
int Sport:: getNumTeams() const
{
    return numTeams;
}

//****************************************************************************************************
inline
int Sport:: getDay() const 
{
    return dateSched.day;
}

//****************************************************************************************************
inline
void Sport:: setDay(int & da)
{
    dateSched.day = da;
}

//****************************************************************************************************
inline
int Sport:: getMonth() const
{
    return dateSched.month;
} 

//****************************************************************************************************
inline
void Sport:: setMonth(int & m)
{
    dateSched.month = m;
}

//****************************************************************************************************
inline
int Sport:: getYear() const
{
    return dateSched.year;
}

//****************************************************************************************************
inline
void Sport:: setYear(int & y)
{
    dateSched.year = y;
}
 
//****************************************************************************************************
inline
Date Sport:: getDate() const
{
    return dateSched;
}

//****************************************************************************************************

#endif