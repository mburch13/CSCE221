#include "TemplateDoublyLinkedList.h"
#include <iostream>
#include <string>
#include <cstdio>
#include <sstream>

using namespace std;

int main () {
    try{
      // Construct a linked list with header & trailer
      cout << "Create a new list" << endl;
      DoublyLinkedList<string> dll;
      cout << "list: " << dll << endl << endl;


      // Insert 10 nodes at back with value 10,20,30,..,100
      cout << "Insert 10 nodes at back with value 10,20,30,..,100" << endl;
      for (int i=10;i<=100;i+=10) {
        stringstream ss;
        ss << i;
        dll.insertLast(ss.str());
      }
      cout << "list: " << dll << endl << endl;

      // Insert 10 nodes at front with value 10,20,30,..,100
      cout << "Insert 10 nodes at front with value 10,20,30,..,100" << endl;
      for (int i=10;i<=100;i+=10) {
        stringstream ss;
        ss << i;
        dll.insertFirst(ss.str());
      }
      cout << "list: " << dll << endl << endl;
      
      // Copy to a new list
      cout << "Copy to a new list" << endl;
      DoublyLinkedList<string> dll2(dll);
      cout << "list2: " << dll2 << endl << endl;
      
      // Assign to another new list
      cout << "Assign to another new list" << endl;
      DoublyLinkedList<string> dll3;
      dll3=dll;
      cout << "list3: " << dll3 << endl << endl;
      
      // Delete the last 10 nodes
      cout << "Delete the last 10 nodes" << endl;
      for (int i=0;i<10;i++) {
        dll.removeLast();
      }
      cout << "list: " << dll << endl << endl;
      
      // Delete the first 10 nodes
      cout << "Delete the first 10 nodes" << endl;
      for (int i=0;i<10;i++) {
        dll.removeFirst();
      }
      cout << "list: " << dll << endl << endl;
      
      // Check the other two lists
      cout << "Make sure the other two lists are not affected." << endl;
      cout << "list2: " << dll2 << endl;
      cout << "list3: " << dll3 << endl;

      // more testing...
      // add tests for insertAfter, insertBefore
        cout << "Insert after" << endl;
        DListNode<string> temp = *dll.getFirst();
        dll.insertAfter(temp, "45");
        cout << "list: " << dll << endl << endl;
        
        cout << "Insert before" << endl;
        dll.insertBefore(temp, "10");
        cout << "list: " << dll << endl << endl;
        
        // add tests for removeAfter, removeBefore
        cout << "Remove after" << endl;
        dll.removeAfter(temp);
        cout << "list: " << dll << endl << endl;
        // add tests for DoublyLinkedListLength
        cout << "Length of list" << endl;
        cout << "list3: " << TemplateDoublyLinkedListLength(dll3) << endl;

        cout << "done\n";
    }
    catch(exception &error){
        cerr << "Error: " << error.what() << endl;
    }  return 0;
}
