/* This class will hold the top [first] node called head. This class will be what the user interacts with when pushing or popping Nodes.
 */
#include <iostream>
#include "Stack.h"
#include "Node.h"

using namespace std;

Stack::Stack() {head = NULL;}

Stack::~Stack() {delete head;}

void Stack::push(int a) {
	head= new Node(a,head);
}

Node* Stack::pop() {
	Node *t = new Node(head->getnumber(),NULL);
	Node *a = head;
	head = head->getnext();
	delete a;
	return t;
}

bool Stack::isempty() { return !head; }
