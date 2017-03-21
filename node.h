<pre>
/* This is the header file for Node.cpp
 */
#ifndef _NODE_
#define _NODE_

class Node {
private:
	Node * next; //A pointer to a Node after "this"
	int number;
public:
	Node(int a, Node*n); //Constructor, *n is next.
	Node * getnext(); 
	int getnumber();
};


#endif

</pre>