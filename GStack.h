/*
GNode.h
A custom made stack-like class which can contain any number of character pointers. You can only access the most recently pushed element; first in, last out.
Contains the classes:
pop(): Removes the item at the top of the stack
push_back(): Adds an item to the end of the stack
peek(): Returns a pointer to the item at the top of the stack
@author Greggory Hickman, January-February 2020
@version dev
 */
#ifndef GSTACK_H
#define GSTACK_H

#include <cstring>

#define MAXLEN 10000

class GStack {
	public:
		//Constructor & Destructor
		GStack();
		~GStack();
	
		//Delete the element at the top of the stack, making the next element in the list be the new top
		void pop();
		//Add an element to the top of the stack
		void push_back(char*);
		//Returns the char* component of the element at the top of the stack
		char* peek();
		
	protected:
		struct GNode {
			char* ele;
			GNode* next;
	
			GNode() {
				ele = new char[MAXLEN];
				ele[0] = 0;
			};
		};
		
		GNode* head;
		int len;
};

#endif
