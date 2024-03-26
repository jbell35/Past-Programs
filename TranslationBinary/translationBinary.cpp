//****************************************************************************************************
//  File:           translationBinary.cpp
//
//  Student:        Jamari Bell
//
//  Assignment:     Program #10-2
//
//  Course Name:    Computer Programming II
//
//  Course Number:  COSC 1560 - 01
//
//  Due:            November 20th, 2023
//
//  This program takes input from the Translations.txt file and from the previously made binary
//  file, randomly generates 3 people to take the test (read from binary file) which prompts them
//   5 random questions, writes the updated info to the binary file and outputs the results.
//
//****************************************************************************************************

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cctype>
using namespace std;

const int SIZE = 20;

struct Translation
{
    string american; //a word in American
    string english; //The equalivent (proper) word in English

};

struct Date
{
    int day;
    int month;
    int year;
};

struct Person
{
    char name[SIZE]; // c-string not string 
    double score; 
    Date testTaken;
};

Translation * readTranslation(const string & filename, int & num); //keep 
void testersUpdates(const Translation t[], int numT, const string& fileName);
void takeTest(const Translation t[], int numT, Person & p); //keep 
void displayTesters(const string& fileName);

//****************************************************************************************************

int main()
{
    int numT = 0,
        numP = 0;
    string fileName = "Testers.dat"; 

    Translation * t = nullptr;

    t = readTranslation("Translation.txt", numT);
    displayTesters(fileName);
    testersUpdates(t, numT, fileName);

    cout << "\nUpdated Results:" << endl;
    displayTesters(fileName);

    delete[] t;
    t = nullptr;

    return 0;
}

//****************************************************************************************************

Translation * readTranslation(const string & filename, int & num) //don't change
{
    Translation * t = nullptr;
    fstream f(filename, ios::in);

    if (!f.fail())
    {
        f >> num; 
        f.ignore();

        t = new Translation[num]; 

        for (int i = 0; i < num; i++)
        {
            getline(f, t[i].american, ',');
            getline(f, t[i].english);
        }
        
        f.close();
    }
    else
    {
        cout << "Error: file could not be opened." << endl;
    }

    return t; 

}

//****************************************************************************************************

void testersUpdates(const Translation t[], int numT, const string& fileName)
{
    int numP,
        randP = 0,
        month,
        day,
        year,
        numOfTests = 3; 

    short seed; 
    seed = time(0);
    srand(seed); 

    Person p; 

    cout << "\nEnter the Current Date " << endl
         << "========================" << endl;
    
    cout << "Enter the month: ";
    cin >> month; 

    cout << "Enter the day: ";
    cin >> day; 

    cout << "Enter the year: ";
    cin >> year;

    fstream f(fileName, ios::in | ios::out | ios::binary);
    f.read(reinterpret_cast<char *>(&numP), sizeof(int)); 

    for (int i = 0; i < numOfTests; i++)
    {
        randP = (rand() % numP)+ 1;

        f.seekg(sizeof(int) + (randP - 1) * sizeof(Person), ios::beg); 
        f.read(reinterpret_cast<char *>(&p), sizeof(Person));

        p.testTaken.month = month; 
        p.testTaken.day = day; 
        p.testTaken.year =  year; 

        cout << "\nName: " << p.name << endl
             << "Date of test: " << p.testTaken.month << "/" 
             << p.testTaken.day << "/"
             << p.testTaken.year << endl;

        takeTest(t, numT, p); 

        f.seekp((sizeof(int) + (randP - 1) * sizeof(Person)), ios::beg);
        f.write(reinterpret_cast<char *>(&p), sizeof(Person)); 
    }

    f.close();
}

//****************************************************************************************************

void takeTest(const Translation t[], int numT, Person & p) //don't change
{
    string answer,
           input;

    int numOfQues = 5,
        numCorrect = 0,
        randQ = 0;
    
    double avg = 0;

    short seed; 

    seed = time(0);
    srand(seed);

    cout << "\nHere are the questions: " << endl
         << "========================" << endl; 

    for (int i = 0; i < numOfQues; i++)
    {
        randQ = rand() % numT; 

        cout << setw(2) << i + 1 << ". American word: " << t[randQ].american << endl
             << "English Translation: ";
        
        cin >> input;
        cin.ignore();

        answer = t[randQ].english;

        if (input == answer)
        {
            cout << "\nCorrect!" << endl;
            numCorrect++;
        }
        else 
        {
            cout << "\nIncorrect. The answer was: " << t[randQ].english << endl;
        }
        cout << endl;
    }

    avg = (static_cast<double>(numCorrect)/numOfQues) * 100;
    p.score = avg; 

}

//****************************************************************************************************

void displayTesters(const string & fileName)
{
    int num = 0; 
    Person p;

    fstream f(fileName, ios::in | ios::binary);

    if (!f.fail())
    {
        f.read(reinterpret_cast<char *>(&num), sizeof(int)); 

        cout << left  
                << setw(15) << "NUMBER" << setw(20) << "NAME" 
                << setw(20) << "SCORE" << "TEST TAKEN" << endl
                << "==================================================================" << endl;

            for (int i = 0; i < num; i++)
            {
                f.read(reinterpret_cast<char *>(&p), sizeof(Person)); 

                cout << setw(15) << i + 1 << setw(20) << p.name
                    << setw(20) << p.score
                    << p.testTaken.month << "/"
                    << p.testTaken.day << "/"
                    << p.testTaken.year << endl;

            }
        f.close();
    }
    else
    {
        cout << "Error: file could not be opened." << endl;
    }
}

//****************************************************************************************************


/*

NUMBER         NAME                SCORE               TEST TAKEN
==================================================================
1              Steve Smith         0                   11/11/2222
2              Sue Jones           10                  11/11/2011
3              Li Ying             0                   11/11/2011
4              Kun Joom            0                   11/11/1111
5              Joe Bush            80                  11/11/2021
6              Kim Long            0                   11/11/1111
7              Fred Ring           0                   11/11/2021
8              Frank Pearse        0                   11/11/2021
9              Helen Hu            0                   11/11/2021
10             Mark James          0                   11/11/2021


Enter the Current Date 
========================
Enter the month: 10
Enter the day: 12
Enter the year: 2024

Name: Fred Ring
Date of test: 10/12/2024

Here are the questions: 
========================
1 . American word: gas
English Translation: petrol

Correct!

2 . American word: movie
English Translation: fil

Incorrect. The answer was: film

3 . American word: cart
English Translation: trolley

Correct!

4 . American word: last name
English Translation: surname

Correct!

5 . American word: subway
English Translation: underground

Correct!


Name: Mark James
Date of test: 10/12/2024

Here are the questions: 
========================
1 . American word: pants
English Translation: trousers

Correct!

2 . American word: pants
English Translation: trousers

Correct!

3 . American word: pants
English Translation: trousers

Correct!

4 . American word: hood
English Translation: idk

Incorrect. The answer was: bonnet

5 . American word: cart
English Translation: trolley

Correct!


Name: Steve Smith
Date of test: 10/12/2024

Here are the questions: 
========================
1 . American word: movie
English Translation: film

Correct!

2 . American word: chips
English Translation: crisps

Correct!

3 . American word: soccer
English Translation: football

Correct!

4 . American word: restroom
English Translation: toilet

Correct!

5 . American word: sidewalk
English Translation: pavement

Correct!


Updated Results:
NUMBER         NAME                SCORE               TEST TAKEN
==================================================================
1              Steve Smith         100                 10/12/2024
2              Sue Jones           10                  11/11/2011
3              Li Ying             0                   11/11/2011
4              Kun Joom            0                   11/11/1111
5              Joe Bush            80                  11/11/2021
6              Kim Long            0                   11/11/1111
7              Fred Ring           80                  10/12/2024
8              Frank Pearse        0                   11/11/2021
9              Helen Hu            0                   11/11/2021
10             Mark James          80                  10/12/2024

*/