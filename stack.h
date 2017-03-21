/* This is the header file for Stack.cpp
 */
#include <iostream>
using namespace std;
#include "Node.h"

class Node;
class Stack {
private:
	Node* head;
public:
	Stack(); //Constructor
	~Stack(); //Destructor
	void push(int a); //Creates a new node with the number a for data and puts it "on top of" all others
	Node* pop(); //Removes the top node and returns it.
	bool isempty(); //Returns true if list is empty.
};
