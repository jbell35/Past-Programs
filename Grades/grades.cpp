//****************************************************************************************************
//  File:           grades.cpp
//
//  Student:        Jamari Bell
//
//  Assignment:     Program #11
//
//  Course Name:    Computer Programming I 
//
//  Course Number:  COSC 1550 - 01
//
//  Due:            April 14th, 2023
//
//  This program reads names and scores from a file into two arrays, 
//  calculates the average, and outputs the average and the list of students 
//  who are above the average score.
//
//****************************************************************************************************

#include <iostream>
#include <fstream>
using namespace std;

//****************************************************************************************************

int main()
{
    const int SIZE = 10;

    int scores[SIZE];

    string names[SIZE];
    
    double avg,
           sum = 0;

    ofstream fout;

    ifstream fin;

    fin.open("scores.txt");

    if (fin)
    {
        for (int i = 0; i < SIZE; i++)
        {
            fin >> names[i] >> scores[i];
        }

        fout.open("goodStud.txt");

        for (int i = 0; i < SIZE; i++)
        {
            sum += scores[i];
        }

        avg = sum/SIZE;

        fout << "The average is " << avg << endl
             << "The student above average are as follows: " << endl;

        for (int i = 0; i < SIZE; i++)
        {
            if (scores[i] >= avg)
                fout << "\t" << names[i] << "\t\t" << scores[i] << endl;
        }

        fout.close();

    }
    fin.close();

    return 0;
}

//****************************************************************************************************

/*

The average is 76.9
The student above average are as follows:
    Morris      92
    Rogers      89
    Cook        77
    Morgan      88
    Johnson     86
    Jones       97
    Brown       79

*/