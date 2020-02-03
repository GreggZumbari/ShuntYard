/*
GNode.h
A custom made stack-like class which can contain any number of character pointers. It points to the next Node in the list, and one can only access the very last one
Contains the classes:
pop(): removes the item at the top of the stack
push_back(): adds an item to the end of the stack
peek(): returns a pointer to the item at the top of the stack
@author Greggory Hickman, January 2020
@version dev
 */
#ifndef GNODE_H
#define GNODE_H

class GNode {
	public:
	//Constructor & Destructor
	GNode(char);
	~GNode();
	
	//Other functions
	void setNext(GNode*);
	
	private:
	char ele;
	GNode* next;
}

#endif
