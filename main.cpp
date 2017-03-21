/* Alexander Lanthier
 * Northern Michigan University
 * This program lists the steps and the amount of the steps it takes to complete the Hanoi tower game the quickest way possible (currently accepted (2/22/15))
 */
#include <iostream>
#include <string.h>
#include <cstdlib>
#include <stdio.h>
#include "Stack.h"
#include "main.h"
using namespace std;

int main() {
	Stack *A = new Stack(), *B = new Stack(), *C = new Stack();
	bool even, ltor; //ltor = right to left, this determines which way disk one is going to move.
	int diskone = 1, disks; //Disk one will be the top disk
	cout << "How many disks?" << endl;
	cin >> disks;

	for(int i = disks; i > 0; i--) A->push(i);
	even = ltor = (disks%2==0) ? true : false; //If the number of initial disks is even, move 1 left to right consitently.

	//First Move
	if(even) { printmove(1,1,2); move(A,B); diskone=2; }
	else { printmove(1,1,3); move(A,C); diskone=3; even = true; }
	int movecount;
	for(movecount = 1; !A->isempty() || !B->isempty(); movecount++) {	//Movecount starts at one because first move was already done, go until both towers are empty.
		if(even) { //Find and exceucute the only possible move that does not involve disk one
			if(diskone==1) {
				if(getsmallest(B,C)) printmove(move(B,C),2,3); //Move the lowest top Node of a stack that isn't one ontop of the remaining stack.
				else printmove(move(C,B),3,2);
			}
			else if(diskone==2) {
				if(getsmallest(C,A)) printmove(move(C,A),3,1);
				else printmove(move(A,C),1,3);
			}
			else {
				if(getsmallest(A,B)) printmove(move(A,B),1,2);
				else printmove(move(B,A),2,1);
			}
		}
		else { //Only move disk one if not even.
			int nextdiskone;
			if(ltor) {
				nextdiskone = diskone < 3 ? diskone+1 : 1; //Temporary variable for printing the move.
				printmove(1,diskone,nextdiskone);
				if(diskone==1) move(A,B);
				else if(diskone==2) move(B,C);
				else move(C,A);
				diskone=nextdiskone;
			}
			else {
				nextdiskone = diskone > 1 ? diskone-1 : 3;
				printmove(1,diskone,nextdiskone);
				if(diskone==1) move (A,C);
				else if (diskone==2) move(B,A);
				else move(C,B);
				diskone=nextdiskone;
			}
		}
		even=!even;
	}
	cout << endl << "It took " << movecount << " moves." << endl;
	delete A,B,C;
	return 0;
}

void printmove(int a, int b, int c) {
	cout << "Move disk " << a << " from tower " << b << " to tower " << c << "." << endl;
}

int move(Stack * A, Stack * B) {
	int x = A->pop()->getnumber();
	B->push(x);
	return x;
}

bool getsmallest(Stack *Y, Stack *Z) {
	bool ret;
	if(Y->isempty()) { return false;} //Check if either node is empty. If one is, return the other. In doing this, I am assuming that there will always be a node in stack y or stack z
	if(Z->isempty()) { return true;}
	Node * Ynode = Y->pop(), *Znode = Z->pop();
	if(Ynode->getnumber() < Znode->getnumber()) ret=true; //If the Y node is less, then we will be returning true.
	else ret=false;
	Y->push(Ynode->getnumber());
	Z->push(Znode->getnumber());
	return ret;
}
