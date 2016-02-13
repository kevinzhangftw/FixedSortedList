// profilinglabdriver.cpp : Defines the entry point for the console application.
//

#include "fixedsortedlist.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

void ProfileList(string fname);
FixedSortedList ReadFile(string infile);
void Barometer();
void InsertCost(string infile);

int main()
{
    ProfileList("animals_rand.txt");
    //Barometer();
    cout << endl << endl;
    return 0;
}

// Reads a file into a list and then prints list
// PARAM: fname is the name of the file to be opened
void ProfileList(string fname)
{
    FixedSortedList list = ReadFile(fname);
    //PrintList(list, 5);
}

// Opens a file and reads the contents into a FixedSortedList
// The function does not remove non-alpha characters
// PARAM: fname is the name of the file to be opened
// PRE: the file contains words separated by white space
FixedSortedList ReadFile(string infile)
{
    FixedSortedList result(200);
    string s;
    
    ifstream ist(infile.c_str()); // open file
    // Check if file opened correctly
    if (ist.fail())
        throw runtime_error("file not found");
    
    // Read file into list
    while (ist >> s)
    {
        cout << "insert " << s << ": ";
        result.Insert(s);
    }
    
    return result;
}

// Opens a file and reads the contents into a FixedSortedList
// Displays the number of operations performed for each insert
// PARAM: fname is the name of the file to be opened
// PRE: the file contains words separated by white space
void InsertCost(string infile)
{
    FixedSortedList list(200);
    string s;
    
    ifstream ist(infile.c_str()); // open file
    // Check if file opened correctly
    if (ist.fail())
        throw runtime_error("file not found");
    
    // Read file into list
    int ops = 0;
    int total = 0;
    
    // Read file into list
    cout << "Inserting " << " words from " << infile << endl ;
    while (ist >> s)
    {
        //ops = list.Insert(s);
        total += ops;
        if ((list.Size()-1) % 10 == 0){ //print in columns
            cout << endl;
        }
        cout << right << setw(5) << ops;
    }
    cout << endl << endl << "Inserted " << list.Size() << " words" << endl ;
    cout << "Total iterations = " << total << endl;
}

// Calling function for InsertCost for lab activity
void Barometer()
{
    InsertCost("animals_rand.txt");
    cout << "-----------------------------------------------" << endl << endl;
    InsertCost("animals_sort.txt");
    cout << "-----------------------------------------------" << endl << endl;
    InsertCost("animals_rev.txt");
    cout << "-----------------------------------------------" << endl << endl;
}