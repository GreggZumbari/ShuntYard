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
#ifndef GSTACK_H
#define GSTACK_H

#include <iostream>
#include <cstring>

struct GNode {
	char* ele;
	GNode* next;
	
	GNode() {
		ele = new char[100];
		strcpy(ele, "EMPTY");
		next = NULL;
	}
};

class GStack {
	public:
		//Constructor & Destructor
		GStack();
		~GStack();
	
		//Delete the element at the top of the stack, making the next element in the list be the new top
		void pop();
		//Add an element to the top of the stack
		void push_back(char* ele);
		//Returns the char* component of the element at the top of the stack
		char* peek();
		//Returns true if stack is empty
		bool isEmpty();
		//Returns true if stack is full
		bool isFull();
		
	protected:
		GNode* head;
		const int maxLen = 100;
		int len;
};

#endif
