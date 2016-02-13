//
//  fixedsortedlist.cpp
//  fixedSortedList
//
//  Created by Kevin Zhang on 2016-02-07.
//  Copyright © 2016 Kevin Zhang. All rights reserved.
//

#include "fixedsortedlist.hpp"
#include <iostream>
#include <stdexcept>

// Default constructor
FixedSortedList::FixedSortedList(void)
{
    max = 10;
    arr = new string[max];
    current = 0;
    pos = 0;
}



// Constructor that creates a list of size n
// PARAM: n is the maximum size of the list
FixedSortedList::FixedSortedList(int n)
{
    max = n;
    arr = new string[n];
    current = 0;
    pos = 0;
}



// Copy constructor
FixedSortedList::FixedSortedList(const FixedSortedList& list)
{
    max = list.max;
    current = list.current;
    arr = new string[max];
    pos = 0;
    // Copy contents from other list
    for (int i = 0; i < current; i++)
    {
        arr[i] = list.arr[i];
    }
}

// Destructor
FixedSortedList::~FixedSortedList(void)
{
    delete[] arr;
}

// Inserts a string into the list
// PARAM: s is the string to be inseted
// POST: s is inserted in the list in alphabetic order
//void FixedSortedList::Insert(string s)
//{
//    // Throw an error if the array is full
//    if (current >= max) {
//        throw runtime_error("list is full");
//    }
//    
//    // Find insertion point for item
//    int pos = current; //insertion point
//    while (pos > 0 && s < arr[pos-1])
//    {
//        arr[pos] = arr[pos-1];
//        pos--;
//    }
//    
//    // Insert new string
//    arr[pos] = s;
//    current++;
//    //return 0;
//}
//
//void FixedSortedList::Insert(string s)
//{
//    int count1 = 0;
//    int count2 = 0;
//    // Throw an error if the array is full
//    count1++;
//    if (current >= max) {
//        throw runtime_error("list is full");
//    }
//    // Find insertion point for item
//    int pos = current; //insertion point
//    count1++;
//    while (pos > 0 && s < arr[pos-1])
//    {
//        arr[pos] = arr[pos-1];
//        pos--;
//        count2 += 3;
//    }
//    // Insert new string
//    count1 += 2;
//    arr[pos] = s;
//    current++;
//    cout << count1 << " + " << count2 << endl;
//}
int FixedSortedList::Insert(string s)
{
    int count = 0;
    //throw error if array is full
    if (current>=max) {
        throw runtime_error("list is full");
    }
    //find the insertion point for inserting array
    int pos = current;
    while (pos>0 && s<arr[pos-1]) {
        arr[pos]= arr[pos-1];
        pos--;
        count++;
    }
    arr[pos]=s;
    current++;
    cout << "count: " << count << " ";
    return count;
}

bool FixedSortedList::Remove(string s)
{
    int pos = 0;
    // Find string to be removed
    while (pos < current && arr[pos] != s)
    {
        pos++;
    }
    
    // Move items down if s is found
    if (arr[pos] == s)
    {
        for (int i = pos; i < current-1; ++i)
        {
            arr[i] = arr[i+1];
        }
        current--;
        return true;
    }
    else
    {
        return false;
    }
}

// Returns the next string in the list
// POST: Increments pos
string FixedSortedList::Next()
{
    string result = "";
    if (pos < current)
    {
        result = arr[pos];
        pos++;
    }
    return result;
}

// Sets pos to 0
void FixedSortedList::Reset()
{
    pos = 0;
}

// Returns size
int FixedSortedList::Size()
{
    return current;
}

// Overloaded assignment operator
FixedSortedList& FixedSortedList::operator=(const FixedSortedList& list)
{
    // If the LH and RH lists are the same must return
    // immediately to avoid deleting the list before
    // copying it, and to avoid wasting time
    // i.e. where operation is like list1 = list1
    if (this == &list)
    {
        return *this; //pointer to the list
    }
    // Delete old array
    delete[] arr;
    // Make new list
    DeepCopy(list);
    return *this;
}//operator=

// Helper function for copy constructor and assignment operator
void FixedSortedList::DeepCopy(const FixedSortedList& list)
{
    current = list.current;
    max = list.max;
    arr = new string[max];
    for (int i = 0; i < current; i++)
    {
        arr[i] = list.arr[i];
    }
}//DeepCopy