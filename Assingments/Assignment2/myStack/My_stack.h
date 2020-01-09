//
//  My_stack.hpp
//  assign2
//
//  Created by McKenzie on 7/16/18.
//  Copyright © 2018 McKenzie. All rights reserved.
//

#ifndef My_stack_h
#define My_stack_h

#include <stdio.h>
#include <vector>
#include <exception>
#include <iostream>

using namespace std;

class My_stack{
//    vector<int> myVec;
private:
    vector<int> myVec;
    int capacity;
//    int *vec;
    int topStack;
    void doubleSize();
    
public:
    My_stack(); //constructor
    My_stack(int cap);
    ~My_stack() = default;   //destructor
    int top() throw(exception);
    void push(const int& elem) throw(exception);
    int pop() throw(exception);
    bool isEmpty() const;
    int size() const { return myVec.size(); }
    vector<int> getVector() {return myVec; }
};

#endif /* My_stack_h */
