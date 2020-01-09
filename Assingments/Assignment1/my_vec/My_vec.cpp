//
//  My_vec.cpp
//  
//
//  Created by McKenzie on 7/3/18.
//

#include <stdio.h>
#include "My_vec.h"

//constructor
My_vec::My_vec(){
    size = 0;
    capacity = 10;
    ptr = new char[capacity];
}

//destructor
My_vec::~My_vec(){
    delete [] ptr;
}

//copy constructor
My_vec::My_vec(const My_vec& vec){
    size = vec.size;
    capacity = vec.capacity;
    ptr = new char[capacity];
    for (int i = 0; i < size; i++)
    {
        ptr[i] = vec.ptr[i];
    }
}

My_vec& My_vec::operator=(const My_vec& vec){
    if (this != &vec){
        delete [] ptr;
        size = vec.size;
        capacity = vec.capacity;
        ptr = new char[capacity];
        for(int i = 0; i < size; i++){
            ptr[i] = vec.ptr[i];
        }
    }
    return *this;
}

int My_vec::get_size() const{
    return size;
}

int My_vec::get_capacity() const{
    return capacity;
}

char& My_vec::operator[](int i) const{
    return ptr[i];
}
char& My_vec::operator[](int i){
    return ptr[i];
}

bool My_vec::is_empty() const{
    if(ptr == nullptr && size == 0 && capacity == 0){
        return true;
    }
    else{
        return false;
    }
}

char& My_vec::elem_at_rank(int r) const{
    return ptr[r];
}

void My_vec::insert_at_rank(int r, const char& elem){
    char temp;
    if(size == capacity){
        My_vec vec;
        size = vec.size+1;
        capacity = vec.capacity * 2;
        ptr = new char[capacity];
        for (int i = 0; i < size; i++){
            ptr[i] = vec.ptr[i];
            if(ptr[i] == ptr[r]){
                temp = ptr[i];
                ptr[i] = elem;
                ptr[i+1] = temp;
            }
        }
    }
    else{
        size += 1;
        for (int i = 0; i < size; i++){
            if(ptr[i] == NULL){
                ptr[i] = elem;
            }
            if(ptr[i] == ptr[r]){
                    temp = ptr[i];
                    ptr[i] = elem;
                    ptr[i+1] = temp;
            }
        }
    }
}
void My_vec::replace_at_rank(int r, const char& elem){
    for(int i = 0; i < size; i++){
        if(ptr[i] == ptr[r]){
            ptr[i] = elem;
        }
    }
}
void My_vec::remove_at_rank(int r){
    for(int i = 0; i < size; i++){
        if(ptr[i] == ptr[r]){
            ptr[i] = ptr[i+1];
        }
    }
}

ostream& operator<<(ostream& out, const My_vec& vec){
    for(int i = 0; i<vec.get_size(); i++){
        out << vec.elem_at_rank(i) << " ";
    }
    return out;
}
int find_max_index(const My_vec& v,int size){
    int max = 0;
    size = v.get_size();
    for(int i = 0; i < size; i++){
        if(v.elem_at_rank(i+1)<v.elem_at_rank(i)){
            max = i;
        }
    }
    return max;
}

void sort_max(My_vec& vec)
{    
    int size = vec.get_size();
    int indexTemp = find_max_index(vec, size);
    char temp;

    if(size%2 == 0){
        while(indexTemp > indexTemp%2){
            for(int i = 0; i < indexTemp; i++){
                temp = vec[indexTemp];
                vec[indexTemp] = vec[i];
                vec[i] = temp;
                --indexTemp;
            }
        }
    }
    else{
        while(indexTemp > indexTemp%3){
            for(int i = 0; i < indexTemp; i++){
                temp = vec[indexTemp];
                vec[indexTemp] = vec[i];
                vec[i] = temp;
                --indexTemp;
            }
        }
    }
}









