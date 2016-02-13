//
//  fixedsortedlist.hpp
//  fixedSortedList
//
//  Created by Kevin Zhang on 2016-02-07.
//  Copyright © 2016 Kevin Zhang. All rights reserved.
//

#ifndef fixedsortedlist_hpp
#define fixedsortedlist_hpp

#include <stdio.h>
#pragma once

#include <string>
using namespace std;

class FixedSortedList
{
public:
    // Constructors and destructor
    FixedSortedList(void);
    FixedSortedList(int);
    FixedSortedList(const FixedSortedList& list);
    ~FixedSortedList(void);
    
    // Mutators
    int Insert(string s);
    bool Remove(string s);
    
    // Accessors
    string Next();
    void Reset();
    int Size();
    
    // Overloaded operator
    FixedSortedList& operator=(const FixedSortedList& list);
    
private:
    int current;
    int max;
    int pos;
    string* arr;
    void DeepCopy(const FixedSortedList& list);
};
#endif /* fixedsortedlist_hpp */
