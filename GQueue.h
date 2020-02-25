/*
GQueue.h
A custom made stack-like class which can contain any number of character pointers. You can only access the least recently pushed element; first in, first out.
Contains the classes:
void enqueue(char*) - Adds an element to the back of the queue
char* dequeue() - Returns the element at the front of the queue, and also gets rid of it. Functions like a combination of peek() and pop() in a stack.
@author Greggory Hickman, February 2020
@version dev
 */
#ifndef GQUEUE_H
#define GQUEUE_H

#include <iostream>
#include <cstring>

#define MAXLEN 10000

using namespace std;

class GQueue {
	public:
		//Constructor & Destructor
		GQueue();
		~GQueue();
	
		//Queue an element
		void enqueue(char*);
		//Get, and then DESTROY an element
		char* dequeue();
		
	private:
		struct GNode {
			char* ele;
			GNode* next;
	
			GNode() {
				ele = new char[MAXLEN];
			};
		};
		
		GNode* front;
		int len;
};

#endif
