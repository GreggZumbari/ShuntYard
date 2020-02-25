//GStack.cpp

#include "GStack.h"

//Constructor
GStack::GStack() {
	head = new GNode();
	strcpy(head->ele, "HEAD");
	len = 0;
}

//Desconstructor
GStack::~GStack() {}


void GStack::pop() {
	if (len > 0) {
		head = head->next;
		len--;
	}
}

void GStack::push_back(char* ele) {
	if (len < MAXLEN) {
		GNode* newHead = new GNode();
		
		//Then stick it into the "next" of newHead
		newHead->next = head;
		//Insert the element
		strcpy(newHead->ele, ele); //Credit to Barton Hickman (my Dad) for fixing a minor error that used to exist right here
		//newHead->ele = ele;
		
		//Replace head with newHead
		head = newHead;
		len++;
	}
}

char* GStack::peek() {
	//cout << "Peek: " << head->ele << endl;
	return head->ele;
}
