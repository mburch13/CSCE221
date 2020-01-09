//
//  My_stack.cpp
//  assign2
//
//  Created by McKenzie on 7/16/18.
//  Copyright © 2018 McKenzie. All rights reserved.
//

#include "My_stack.h"

//default constructor
My_stack::My_stack(){
    capacity = myVec.max_size();
    topStack = -1;
    myVec = {};
}

//constructor
My_stack::My_stack(int cap){
    cap = capacity;
    topStack = -1;
    myVec = {};
    myVec.resize(cap);
}

//is stack empty
bool My_stack::isEmpty() const{
    return myVec.empty();
}

//returns element at top of stack
int My_stack::top() throw(exception){
    if(isEmpty())
        throw exception();
    return myVec[topStack];
}

//double size of stack
void My_stack::doubleSize(){
    capacity *= 2;
    myVec.resize(capacity);
    vector<int> myVec1;
    for(int i = 0; i <= topStack; i++){
        myVec1[i] = myVec[i];
    }
    myVec.clear();
    myVec = myVec1;
}

//insert new element at top of stack
void My_stack::push(const int& elem) throw(exception){
    if(size() == capacity){
        doubleSize();
    }
    myVec.push_back(elem);
    ++topStack;
}

//return element at top of stack
int My_stack::pop() throw(exception){
    if(isEmpty()){
        throw exception();
    }
    int x = myVec.back();
    myVec.pop_back();
    --topStack;
    return x;
}



