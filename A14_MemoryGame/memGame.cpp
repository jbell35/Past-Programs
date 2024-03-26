//****************************************************************************************************
//  File:           memGame.cpp
//
//  Student:        Jamari Bell
//
//  Assignment:     Program #14
//
//  Course Name:    Computer Programming I 
//
//  Course Number:  COSC 1550 - 01
//
//  Due:            May 5th, 2023
//
//  This program uses multidimension arrays and functions to simulate a memory game. 
//  The program will prompt the user to enter two values, then show the matches, then
//  upate the board to -1 until all matches are found. 
//
//****************************************************************************************************

#include <iostream>
using namespace std;

const int COLS = 4,
          ROWS = 4;

void readUserInput (int [][COLS], int, int);
void displayBoard (int [][COLS], int, int, int &, int &);
void findPosRowCol (int, int, int &, int &);
void displayMatch (int [][COLS], int, int, int, int, int, int);
void updateBoard (int [][COLS], int [][COLS], int, int, int, int, int, int, 
                  bool);
bool checkEqual (int [][COLS], int, int, int, int, int, int);
void displayEqual (bool);
bool gameEnd (int [][COLS], int, int); 

//****************************************************************************************************

int main()
{
    
    int faceup[ROWS][COLS],
        facedown[ROWS][COLS] = {{0, 1, 2, 3}, 
                                {4, 5, 6, 7}, 
                                {8, 9, 10, 11}, 
                                {12, 13, 14, 15}},
        size = 4,                   
        option1,
        option2,
        r1,
        c1,
        r2, 
        c2;
    bool complete, 
         result;
       
    readUserInput(faceup, ROWS, COLS);
    
    do
    {
        displayBoard(facedown, ROWS, COLS, option1, option2);
        findPosRowCol(option1, size, r1, c1);
        findPosRowCol(option2, size, r2, c2);
        result = checkEqual(faceup, ROWS, COLS, r1, c1, r2, c2);
        displayEqual(result);
        displayMatch (faceup, ROWS, COLS, r1, c1, r2, c2);
        updateBoard(faceup, facedown, ROWS, COLS, r1, c1, r2, c2, result);
        complete = gameEnd(facedown, ROWS, COLS);
    }
    while (complete == true);

    if (complete == false)
    {
        cout << "\nYou have found all";
    }

    return 0;
}
    
//****************************************************************************************************

void readUserInput (int faceup[][COLS], int ROWS, int COLS)
{
    cout << "Please Enter the placement of cards" << endl;
    
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            cin >> faceup[i][j];
        }
    }
}

//****************************************************************************************************

void displayBoard (int facedown[][COLS], int ROWS, int COLS, int & option1, 
                   int & option2)
{
    cout << "\n\nThe following numbers show the label of each card." << endl
         << "The value of each card is hidden under the label" << endl 
         <<"Please Pick two cards" << endl
         << "=======================================" << endl;
    
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            cout << facedown[i][j] << "\t";

        }
        cout << endl << endl;
    }

    cin >> option1 >> option2;

} 

//****************************************************************************************************

void findPosRowCol (int position, int size, int & r1, int & c1)
{
    r1 = position / size;
    c1 = position % size;
}

//****************************************************************************************************

bool checkEqual (int faceup[][COLS], int ROW, int COL, int r1, int c1, int r2, 
                 int c2)
{
    bool result = true;
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (faceup[r1][c1] != faceup[r2][c2])
            {
                result = false;
            }
        }
    }

    return result;
}

//****************************************************************************************************

void displayEqual (bool result)
{
    if (result == true)
    {
        cout << "\nplease see the value of each card you picked." << endl
             << "It's a match" << endl;
    }
    else 
    {
        cout << "\nplease see the value of each card you picked." << endl
             << "It's not a match" << endl;
    }
}

//****************************************************************************************************

void displayMatch (int faceup[][COLS], int ROWS, int COLS, int r1, int c1, 
                   int r2, int c2)
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (faceup[i] == faceup[r1] && faceup[j] == faceup[c1])
            {
                cout << faceup[r1][c1] << "\t";
            }
            else if (faceup[i] == faceup[r2] && faceup[j] == faceup[c2])
            {
                cout << faceup[r2][c2] << "\t";
            }
            else 
                cout << "*" << "\t";
        }
        cout << endl;
    }
}

//****************************************************************************************************

void updateBoard (int faceup[][COLS], int facedown[][COLS], int ROWS, int COLS, 
                  int r1, int c1, int r2, int c2, bool result)
{
    if (result == true)
    {
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                if (faceup[i][j] == faceup[r1][c1])
                {
                    facedown[i][j] = -1;
                }
                if (faceup[i][j] == faceup[r2][c2])
                {
                    facedown[i][j] = -1;
                }
            }
        }
    }
}

//****************************************************************************************************

bool gameEnd (int facedown [][COLS], int ROWS, int COLS)
{
    bool complete = false;

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (facedown[i][j] != -1)
            {
                complete = true;
            }
        }
    }

    return complete;
}

//****************************************************************************************************

/*

Please enter the placement of cards.
8 6 12 8 10 0 6 10 4 14 2 12 2 14 4 0 

The following numbers show the label of each card.
The value of each card is hidden under the label. 
Please Pick two cards.
============================================
0       1       2       3

4       5       6       7

8       9       10      11

12      13      14      15
1 2

please see the value of each card you picked. 
it's not a match
*       6       12      * 
*       *       *       * 
*       *       *       * 
*       *       *       *

The following numbers show the label of each card. 
The value of each card is hidden under the label. 
Please Pick two cards. 
============================================ 
0       1       2       3

4       5       6       7

8       9       10      11

12      13      14      15
0 3

please see the value of each card you picked. 
It's a match
8       *       *       8 
*       *       *       * 
*       *       *       *
*       *       *       *

The following numbers show the label of each card.
The value of each card is hidden under the label.
Please Pick two cards.
============================================
-1      1       2       -1 

4       5       6        7 

8       9       10      11

12      13      14      15 
1 6

please see the value of each card you picked. 
It's a match
*       6       *       * 
*       *       6       * 
*       *       *       * 
*       *       *       *

The following numbers show the label of each card.
The value of each card is hidden under the label.
Please Pick two cards.
============================================
-1      -1      2       -1

4       5       -1      7

8       9       10      11

12      13      14      15

9 13

please see the value of each card you picked. 
It's a match
*       *       *       * 
*       *       *       *
*       14      *       * 
*       14      *       *

The following numbers show the label of each card.
The value of each card is hidden under the label.
Please Pick two cards.
============================================
-1      -1      2       -1

4       5       -1      7

8       -1      10      11

12      -1      14      15
5 15

please see the value of each card you picked. 
It's a match
*       *       *       * 
*       0       *       * 
*       *       *       * 
*       *       *       0

The following numbers show the label of each card.
The value of each card is hidden under the label.
Please Pick two cards.
============================================
-1      -1      2       -1

4       -1      -1      7

8       -1      10      11

12      -1      14      -1
8 14

please see the value of each card you picked. 
It's a match
*       *       *       * 
*       *       *       * 
4       *       *       *    
*       *       4       *

The following numbers show the label of each card.
The value of each card is hidden under the label.
Please Pick two cards.
============================================
-1      -1      2       -1

4       -1      -1      7

-1      -1      10      11

12      -1      -1      -1
10 12

please see the value of each card you picked. 
It's a match
*       *       *       * 
*       *       *       * 
*       *       2       * 
2       *       *       *

The following numbers show the label of each card.
The value of each card is hidden under the label.
Please Pick two cards.
============================================
-1      -1      2       -1

4       -1      -1      7

-1      -1      -1      11

-1      -1      -1      -1
2 11

please see the value of each card you picked.
It's a match
*       *       12      *
*       *       *       * 
*       *       *       12 
*       *       *       *

The following numbers show the label of each card.
The value of each card is hidden under the label.
Please Pick two cards.
============================================
-1      -1      -1      -1 

4       -1      -1       7

-1      -1      -1      -1

-1      -1      -1      -1 
4 7

please see the value of each card you picked. 
It's a match
*       *       *       *
10      *       *       10 
*       *       *       * 
*       *       *       *

You have found all


*/