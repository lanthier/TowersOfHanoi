/* The Node class keeps an int as data. Whenever a node is added, it will be added before "this".
 */
#include "Node.h"

Node::Node(int a, Node * n) {
	number = a;
	next = n;
}

Node * Node::getnext() { return next; }

int Node::getnumber() { return number; }
