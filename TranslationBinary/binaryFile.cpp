//****************************************************************************************************
//  File:           binaryFile.cpp
//
//  Student:        Jamari Bell
//
//  Assignment:     Program #10-1
//
//  Course Name:    Computer Programming II
//
//  Course Number:  COSC 1560 - 01
//
//  Due:            November 20th, 2023
//
//  This program reads the information in the Testers.txt file and writes it to a binary file. 
//
//****************************************************************************************************

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int SIZE = 20;

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

Person * readTesters(const string & filename, int & num);
void writeToBinary(const string & filename, Person p[], int numP);

//****************************************************************************************************

int main()
{
    Person * p = nullptr;

    int numP = 0;

    p = readTesters("Testers.txt", numP);
    writeToBinary("Testers.dat", p, numP);

    delete [] p;
    p = nullptr;

    return 0;
}

//****************************************************************************************************

Person * readTesters(const string & filename, int & num)
{
    Person * p = nullptr; 
    fstream f(filename, ios::in); 

    if (!f.fail())
    {
        f >> num; 
        f.ignore();
        p = new Person[num];

        for (int i = 0; i < num; i++)
        {
            f.getline(p[i].name, SIZE);
            f >> p[i].score;
            f.ignore();
            f >> p[i].testTaken.month;
            f.ignore();
            f >> p[i].testTaken.day;
            f.ignore();
            f >> p[i].testTaken.year;
            f.ignore();
        }
        f.close();
    }
    else
    {
        cout << "Error: file could not be opened." << endl;
    }

    return p; 
}

//****************************************************************************************************

void writeToBinary(const string & filename, Person p[], int numP)
{
    fstream f(filename, ios::out|ios::binary);

    f.write(reinterpret_cast<char *>(&numP), sizeof(int));
    f.write(reinterpret_cast<char *>(p), sizeof(Person) * numP);
    f.close();

}

//****************************************************************************************************
