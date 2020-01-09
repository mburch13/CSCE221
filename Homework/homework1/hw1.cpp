//
//  hw1.cpp
//  
//
//  Created by McKenzie on 7/9/18.
//

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int search(vector<int> &v, int x){
    int num_comp = 0;
    int low, mid, high;
    bool sorted = false;
    
    //if range is 1
    if(v.size() == 1){
        return v.size();
    }
    
    //if ascending first < last
    if(v[0] < v[v.size()-1]){
        //check bubble ascending
        for(int k = 1; k < v.size(); k++){
            sorted = false;
            for (int j = 0; j < v.size()-k; j++){
                if(v[j+1] > v[j]){
                    sorted = true;
                }
            }
            if(sorted == true) break;
        }
        mid, low = 0;
        high = (int) v.size() - 1;

        while(sorted == true){
            while (low < high) {
                //exit when low == high
                mid = (low+high)/2;  //set mid

                if (num_comp++, v[mid] < x) low = mid+1;    //num_comp is number of comparisons
                //search upper half
                else high = mid;
                //search lower half
            }
            // low is index for finding element x
            if (num_comp++, x==v[low]) return num_comp; //found

            //        cout << "Element not found "; //not found
        }
    }
    
    
    //if descending last < first
    if(v[v.size()-1] < v[0]){
        //check bubble sort
        for(int k = 1; k < v.size(); k++){
            sorted = false;
            for (int j = 0; j < v.size()-k; j++){
                if(v[j] > v[j+1]){
                    sorted = true;
                }
            }
            if(sorted == true) break;
        }
        low = (int) v.size() - 1;
        mid, high = 0;
        
        while(sorted == true){
            while (low > high) {
                //exit when low == high
                mid = (low+high)/2;  //set mid
                
                if (num_comp++, v[mid] > x) {
                    high = mid+1;    //num_comp is number of comparisons
//                    cout << "HERE: " << num_comp << " ";
                }
                //search upper half
                else low = mid;
                //search lower half
            }
            // low is index for finding element x
            if (num_comp++, x==v[low]) {
//                cout << "here ";
                return num_comp; //found
            }
            
            //        cout << "Element not found "; //not found
        }
    }
    cout << "Vector is not sorted\n";
    return 0;
}


int main(){

    //ascending powers of 2 comparisons;
    vector<int> a;
    for(int i = 1; i < 2049; i*=2){
        for(int j = 1; j <= i; j++){
            a.push_back(j);
        }
        cout <<"i: "<< i <<"\tComparisons: " << search(a, i) << endl;
        a.clear();
    }

    cout << endl;

    vector<int> d;
    for (int i = 2048; i > 0; i/=2){
        for(int j = i; j > 0; j--){
            d.push_back(j);

        }
        cout << "i: "<< i <<"\tComparisons: " << search(d, 1) << endl;
        d.clear();
    }
    
    cout << endl;

    
    vector<int> a1;
    for(int i = 2; i < 2049; i*=2){
        for(int j = 1; j <= i; j++){
            a1.push_back(j);
        }
        cout <<"i: "<< i-1 <<"\tComparisons: " << search(a1, i-1) << endl;
        a1.clear();
    }
    
    cout << endl;
    
    vector<int> d1;
    for (int i = 2048; i > 0; i/=2){
        for(int j = i; j > 0; j--){
            d1.push_back(j);
            
        }
        cout << "i: "<< i-1 <<"\tComparisons: " << search(d1, 1) << endl;
        d1.clear();
    }
    return 0;
}
