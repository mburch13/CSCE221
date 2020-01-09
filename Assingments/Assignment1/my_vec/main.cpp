// main.cpp
//Tests all functionality of the My_vec class.

#include <iostream>
#include <stdexcept>
#include "My_vec.h"

int main(){
    // Some test cases are expected to throw an exception.
    // Add more try and catch blocks as necessary for your code to finish execution.
    
    try{
        My_vec v;       // define an object v of My_vec type
        v.insert_at_rank(0, 'B');     // insert 'B' at the rank 0 into the vector v
        cout << "v: " << v << endl;
        cout << "Size: " << v.get_size() << endl;         // display the vector v size

        v.insert_at_rank(0, 'A');                // insert 'A' at the rank 0  to the vector v
        cout << "v: " << v << endl;                // use the overloaded operator << to display vector elements
        cout << "Size: " << v.get_size() << endl;                // display the vector v size

        v.insert_at_rank(10, 'D');                // insert 'D' at the rank 10 into the vector v
        cout << "v: " << v << endl;          // use the overloaded operator << to display vector elements
        cout << "Size: " << v.get_size() << endl;                // display the vector v size

        v.remove_at_rank(1);                // remove a character at the rank 1 from the vector v
        cout << "v: " << v << endl;                // use the overloaded operator << to display vector elements
        cout << "Size: " << v.get_size() << endl;                // display the vector v size

        v.replace_at_rank(0, 'E');                // replace a character at the rank 0 by the character 'E'
        cout << "v: " << v << endl;                // use the overloaded operator << to display vector elements
        cout << "Size: " << v.get_size() << endl;                // display the vector v size
        
        My_vec v1 = v;                // create a copy v1 of the vector v using a copy constructor
        cout << "v1: " << v1 << endl;           // use the overloaded operator << to display the vector v1
        v1.replace_at_rank(2, 'Y');   // replace a character at the rank 2 of the vector v1 with the character 'Y'
        cout << "v1: " << v1 << endl;                // use the overloaded operator << to display vector v1 elements

        My_vec v2;                // define an object v2 of My_vec type
        v2.insert_at_rank(0, 'K');                // insert 'K' at the rank 0 into the vector v2
        cout << "v2: " << v2 << endl;                // use the overloaded operator << to display vector elements
        cout << "Size: " << v2.get_size() << endl;                // display the vector v2 size

        v2 = v1;         // test the assignment operator and copy the vector v1 to v2
        v2.replace_at_rank(0, '1');    // Set v2 to '1','2','3','4','5'
        v2.replace_at_rank(1, '2');
        v2.insert_at_rank(2, '3');
        v2.insert_at_rank(3, '4');
        v2.replace_at_rank(4, '5');
        cout << "v2: " << v2 << endl;                // use the overloaded operator << to display vector v2
        cout << "Size: " << v2.get_size() << endl;         // display the vector v2 size

        cout << "Max index: " << find_max_index(v2, v2.get_size()) << endl;     // test the function find_max_index using v2
        sort_max(v2);                // test the function sort_max using v2
        cout << "v2: " << v2 << endl;

        v2.replace_at_rank(14, 'S');        // replace in the vector v2 a character at the rank 14 with 'S'

    }

    catch(exception &error){
        cerr << "Error: " << error.what() << endl;
    }
}
