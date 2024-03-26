
#include <iostream>
using namespace std;

void readArray (char [], int &);
void deleteRepeas (char [], int &);
void printArray (char [], int &);
char promptUser ();

//****************************************************************************************************

int main()
{
    const int SIZE = 10;
    char let[SIZE],
         repeat;
    int used;

    do 
    {
        readArray(let, used);
        deleteRepeats(let, used);
        printArray(let, used);
        repeat = promptUser();
    }
    while (repeat == 'Y' || repeat == 'y');

    return 0;
}

//****************************************************************************************************

void readArray (char let[], int & used)
{
    cout << "\nWhat is the size: ";
    cin >> used;

    cout << "Enter the array" << endl;
    for (int i = 0; i < used; i++)
    {
        cin >> let[i]; 
    }
}

//****************************************************************************************************

void deleteRepeats (char let[], int & used)
{
    for (int i = 0; i < used - 1; i++)
    {
        for (int j = i + 1; j < used; j++)
        {
            if (let[i] == let[j])
            {
                cout << "\nFound duplicates at " << i + 1 << " and " 
                     << j + 1 << " : " << let[i] << " and " << let[j] 
                     << endl;

                for (int k = j; k < used - 1; k++)
                {
                    let[k] = let[k + 1];
                }
                j--;
                used--;

                cout << "Updated array: ";
                for (int i = 0; i < used; i++)
                {
                    cout << let[i] << " ";
                }
                cout << endl;
            }
        }
    }
}

//****************************************************************************************************

void printArray(char let[], int & used)
{
    cout << "\n\nThe array after delete repeats" << endl;
    for (int i = 0; i < used; i++)
    {
        cout << let[i] << " ";
    }
}

//****************************************************************************************************

char promptUser () 
{
    char repeat; 

    cout << "\nRepeat? ";
    cin >> repeat;

    return repeat;
}

/*

what is the size: 10 
Enter the array 
a g g g e n g g e e

Found duplicates at 2 and 3 : g and g
Updated array: a g g e n g g e e 

Found duplicates at 2 and 3 : g and g 
Updated array: a g e n g g e e 

Found duplicates at 2 and 5 : g and g 
Updated array: a g e n g e e 

Found duplicates at 2 and 5 : g and g 
Updated array: a g e n e e 

Found duplicates at 3 and 5 : e and e 
Updated array: a g e n e 

Found duplicates at 3 and 5 : e and e 
Updated array: a g e n 

The array after delete repeats 
a g e n 
Repeat? N (if Y or y, will prompt user from the top)

*/