//
//  main.cpp
//  assign2
//
//  Created by McKenzie on 7/16/18.
//  Copyright © 2018 McKenzie. All rights reserved.
//

#include "My_stack.h"

vector<int> spans1(vector<int> x){
    vector<int> s;
    s.resize(x.size());
    for(int i = 0; i < x.size(); i++){
        int j = 1;
        while(j <= i && x[i-j] <= x[i] && x[i-j+1] >= x[i-j]){
            j = j + 1;
        }
        s[i] = j;
        cout << s[i] << " ";
    }
    return s;
}

vector<int> spans2(vector<int> x){
    My_stack tempStack;
    vector<int> s;
    s.resize(x.size());
    int j = 0;
    for(int i = 0; i < x.size(); i++){
        if(tempStack.isEmpty()){
            s[i] = i + 1;
            tempStack.push(i);
        }
        else{
            j = tempStack.top();
            while(x[i] < x[j] == false){
                tempStack.pop();
                j = tempStack.top();
            }
            s[i] = i - j;
            tempStack.push(i);
        }
        cout << s[i] << " ";
    }
    return s;
}

int main() {
    try{
        My_stack temp;
        My_stack vect;
        for(int i = 0; i < 10; i++){
            vect.push(i);
        }
        cout << "Span: ";
        spans1(vect.getVector());
        
        //reverse stack to print in order of push
        for(int max = vect.size(); max > 0; max--){
            temp.push(vect.top());
            vect.pop();
        }
        cout << "\nVector: ";
        for(int max = temp.size(); max > 0; max--){
            cout << temp.top() << " ";
            temp.pop();
        }
        cout << endl << endl;
        

        My_stack vect1;
        for(int i = 20; i > 0; i/=2){
            vect1.push(i);
        }
        cout << "Span: ";
        spans1(vect1.getVector());
        
        //reverse stack to print in order of push
        for(int max = vect1.size(); max > 0; max--){
            temp.push(vect1.top());
            vect1.pop();
        }
        
        cout << "\nVector1: ";
        for(int max = temp.size(); max > 0; max--){
            cout << temp.top() << " ";
            temp.pop();
        }
        cout << endl << endl;
        
        My_stack vect2;
        vect2.push(3);
        vect2.push(5);
        vect2.push(1);
        vect2.push(7);
        vect2.push(2);
        vect2.push(4);
        vect2.push(5);
        vect2.push(9);
        
        cout << "Span: ";
        spans1(vect2.getVector());
        
        //reverse stack to print in order of push
        for(int max = vect2.size(); max > 0; max--){
            temp.push(vect2.top());
            vect2.pop();
        }
        cout << "\nVector2: ";
        for(int max = temp.size(); max > 0; max--){
            cout << temp.top() << " ";
            temp.pop();
        }
        cout << endl << endl;
    }
    catch(exception &error){
        cerr << "Error: " << error.what() << endl;
    }
    
    try{
        My_stack temp;
        My_stack vect3;
        int input = 0;
        cout << "Please input positive integers: \n";
        cout << "Type a negative integer to finish input\n";
        while(input >= 0){
            cin >> input;
            vect3.push(input);

            if(input == -1){
                vect3.pop();
            }
        }

        cout << "\nSpans: ";
        spans2(vect3.getVector());
        
        //reverse stack to print in order of push
        for(int max = vect3.size(); max > 0; max--){
            temp.push(vect3.top());
            vect3.pop();
        }
        cout << "\nVector3: ";
        for(int max = temp.size(); max > 0; max--){
            cout << temp.top() << " ";
            temp.pop();
        }
        cout << endl << endl;

    }
    catch(exception &error){
        cerr << "Error: " << error.what() << endl;
    }
}
