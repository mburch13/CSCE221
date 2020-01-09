//// main.cpp
////Tests all functionality of the My_vec class.
//
#include <iostream>
#include <stdexcept>
#include "TemplatedMy_vec.h"

int main(){
    // Some test cases are expected to throw an exception.
    // Add more try and catch blocks as necessary for your code to finish execution.
    
    try{
        
//---------begin char test----------------------------------------------------
        cout << "BEGIN char TESTING\n";
        TemplatedMy_vec<char> vChar;       // define an object v of My_vec type
        vChar.insert_at_rank(0, 'B');     // insert 'B' at the rank 0 into the vector v
        cout << "vChar: " << vChar << "   ";
        cout << "Size: " << vChar.get_size() << endl;         // display the vector v size

        vChar.insert_at_rank(0, 'A');                // insert 'A' at the rank 0  to the vector v
        cout << "vChar: " << vChar << "   ";                // use the overloaded operator << to display vector elements
        cout << "Size: " << vChar.get_size() << endl;                // display the vector v size

        vChar.insert_at_rank(10, 'D');                // insert 'D' at the rank 10 into the vector v
        cout << "vChar: " << vChar << "   ";          // use the overloaded operator << to display vector elements
        cout << "Size: " << vChar.get_size() << endl;                // display the vector v size

        vChar.remove_at_rank(1);                // remove a character at the rank 1 from the vector v
        cout << "vChar: " << vChar << "   ";                // use the overloaded operator << to display vector elements
        cout << "Size: " << vChar.get_size() << endl;                // display the vector v size

        vChar.replace_at_rank(0, 'E');                // replace a character at the rank 0 by the character 'E'
        cout << "vChar: " << vChar << "   ";                // use the overloaded operator << to display vector elements
        cout << "Size: " << vChar.get_size() << endl;                // display the vector v size

        TemplatedMy_vec<char> vChar1 = vChar;                // create a copy v1 of the vector v using a copy constructor
        cout << "vChar1: " << vChar1 << "   ";           // use the overloaded operator << to display the vector v1
        vChar1.replace_at_rank(2, 'Y');   // replace a character at the rank 2 of the vector v1 with the character 'Y'
        cout << "v1: " << vChar1 << endl;                // use the overloaded operator << to display vector v1 elements

        TemplatedMy_vec<char> vChar2;                // define an object v2 of My_vec type
        vChar2.insert_at_rank(0, 'K');                // insert 'K' at the rank 0 into the vector v2
        cout << "v2: " << vChar2 << "   ";                // use the overloaded operator << to display vector elements
        cout << "Size: " << vChar2.get_size() << endl;                // display the vector v2 size

        vChar2 = vChar1;         // test the assignment operator and copy the vector v1 to v2
        vChar2.replace_at_rank(0, '1');    // Set v2 to '1','2','3','4','5'
        vChar2.replace_at_rank(1, '2');
        vChar2.insert_at_rank(2, '3');
        vChar2.insert_at_rank(3, '4');
        vChar2.replace_at_rank(4, '5');
        cout << "vChar2: " << vChar2 << "   ";                // use the overloaded operator << to display vector v2
        cout << "Size: " << vChar2.get_size() << endl;         // display the vector v2 size

        cout << "Max index: " << find_max_index(vChar2, vChar2.get_size()) << endl;     // test the function find_max_index using v2
        sort_max(vChar2);                // test the function sort_max using v2
        cout << "vChar2: " << vChar2 << endl;

        vChar2.replace_at_rank(14, 'S');        // replace in the vector v2 a character at the rank 14 with 'S'
        cout << "END char TESTING\n\n";
//---------end char test----------------------------------------------------
        
//---------begin int test----------------------------------------------------
        cout << "BEGIN int TESTING\n";

        TemplatedMy_vec<int> vInt;       // define an object v of My_vec type
        vInt.insert_at_rank(0, 6);     // insert 'B' at the rank 0 into the vector v
        cout << "vInt: " << vInt << "   ";
        cout << "Size: " << vInt.get_size() << endl;         // display the vector v size

        vInt.insert_at_rank(0, 3);                // insert 'A' at the rank 0  to the vector v
        cout << "vInt: " << vInt << "   ";                // use the overloaded operator << to display vector elements
        cout << "Size: " << vInt.get_size() << endl;                // display the vector v size

        vInt.insert_at_rank(10, 2);                // insert 'D' at the rank 10 into the vector v
        cout << "vInt: " << vInt << "   ";         // use the overloaded operator << to display vector elements
        cout << "Size: " << vInt.get_size() << endl;                // display the vector v size

        vInt.remove_at_rank(1);                // remove a character at the rank 1 from the vector v
        cout << "vInt: " << vInt << "   ";                // use the overloaded operator << to display vector elements
        cout << "Size: " << vInt.get_size() << endl;                // display the vector v size

        vInt.replace_at_rank(0, 4);                // replace a character at the rank 0 by the character 'E'
        cout << "vInt: " << vInt << "   ";                // use the overloaded operator << to display vector elements
        cout << "Size: " << vInt.get_size() << endl;                // display the vector v size

        TemplatedMy_vec<int> vInt1 = vInt;                // create a copy v1 of the vector v using a copy constructor
        cout << "vInt1: " << vInt1 << endl;           // use the overloaded operator << to display the vector v1
        vInt1.replace_at_rank(2, 8);   // replace a character at the rank 2 of the vector v1 with the character 'Y'
        cout << "vInt1: " << vInt1 << endl;                // use the overloaded operator << to display vector v1 elements

        TemplatedMy_vec<int> vInt2;                // define an object v2 of My_vec type
        vInt2.insert_at_rank(0, 9);                // insert 'K' at the rank 0 into the vector v2
        cout << "vInt2: " << vInt2 << "   ";                // use the overloaded operator << to display vector elements
        cout << "Size: " << vInt2.get_size() << endl;                // display the vector v2 size

        vInt2 = vInt1;         // test the assignment operator and copy the vector v1 to v2
        vInt2.replace_at_rank(0, 1);    // Set v2 to '1','2','3','4','5'
        vInt2.replace_at_rank(1, 2);
        vInt2.insert_at_rank(2, 3);
        vInt2.insert_at_rank(3, 4);
        vInt2.replace_at_rank(4, 5);
        cout << "vInt2: " << vInt2 << endl;                // use the overloaded operator << to display vector v2
        cout << "Size: " << vInt2.get_size() << endl;         // display the vector v2 size
//
        cout << "Max index: " << find_max_index(vInt2, vInt2.get_size()) << endl;     // test the function find_max_index using v2
        sort_max(vInt2);                // test the function sort_max using v2
        cout << "v2: " << vInt2 << endl;
//
        vInt2.replace_at_rank(14, 'S');        // replace in the vector v2 a character at the rank 14 with 'S'
        cout << "END int TESTING\n\n";
//---------end int test----------------------------------------------------
        
//---------begin double test----------------------------------------------------
        cout << "BEGIN double TESTING\n";
//
        TemplatedMy_vec<double> vD;       // define an object v of My_vec type
        vD.insert_at_rank(0, 6.131);     // insert 'B' at the rank 0 into the vector v
        cout << "vD: " << vD << "   ";
        cout << "Size: " << vD.get_size() << endl;         // display the vector v size

        vD.insert_at_rank(0, 3.33);                // insert 'A' at the rank 0  to the vector v
        cout << "vD: " << vD << "   ";                // use the overloaded operator << to display vector elements
        cout << "Size: " << vD.get_size() << endl;                // display the vector v size

        vD.insert_at_rank(10, 2.1);                // insert 'D' at the rank 10 into the vector v
        cout << "vD: " << vD << "   ";         // use the overloaded operator << to display vector elements
        cout << "Size: " << vD.get_size() << endl;                // display the vector v size

        vD.remove_at_rank(1);                // remove a character at the rank 1 from the vector v
        cout << "vD: " << vD << "   ";                // use the overloaded operator << to display vector elements
        cout << "Size: " << vD.get_size() << endl;                // display the vector v size

        vD.replace_at_rank(0, 4.000);                // replace a character at the rank 0 by the character 'E'
        cout << "vD: " << vD << "   ";                // use the overloaded operator << to display vector elements
        cout << "Size: " << vD.get_size() << endl;                // display the vector v size

        TemplatedMy_vec<double> vD1 = vD;                // create a copy v1 of the vector v using a copy constructor
        cout << "vD1: " << vD1 << endl;           // use the overloaded operator << to display the vector v1
        vD1.replace_at_rank(2, 8.42);   // replace a character at the rank 2 of the vector v1 with the character 'Y'
        cout << "vD1: " << vD1 << endl;                // use the overloaded operator << to display vector v1 elements
//
        TemplatedMy_vec<double> vD2;                // define an object v2 of My_vec type
        vD2.insert_at_rank(0, 9.99);                // insert 'K' at the rank 0 into the vector v2
        cout << "vD2: " << vD2 << "   ";                // use the overloaded operator << to display vector elements
        cout << "Size: " << vD2.get_size() << endl;                // display the vector v2 size
//
        vD2 = vD1;         // test the assignment operator and copy the vector v1 to v2
        vD2.replace_at_rank(0, 1.3);    // Set v2 to '1','2','3','4','5'
        vD2.replace_at_rank(1, 2.4);
        vD2.insert_at_rank(2, 3.6);
        vD2.insert_at_rank(3, 4.2);
        vD2.replace_at_rank(4, 5.13);
        cout << "vD2: " << vD2 << endl;                // use the overloaded operator << to display vector v2
        cout << "Size: " << vD2.get_size() << endl;         // display the vector v2 size
    
        cout << "Max index: " << find_max_index(vD2, vD2.get_size()) << endl;     // test the function find_max_index using v2
        sort_max(vD2);                // test the function sort_max using v2
        cout << "vD2: " << vD2 << endl;
        //
        vD2.replace_at_rank(14, 'S');        // replace in the vector v2 a character at the rank 14 with 'S'
        cout << "END double TESTING\n\n";
        //---------end double test----------------------------------------------------
    }

    catch(exception &error){
        cerr << "Error: " << error.what() << endl;
    }
}
