//GStack.cpp

#include "GStack.h"

//Constructor
GStack::GStack() {
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
		GNode* newHead;
		GNode next;
		
		//Grab head by reference...
		next = *head;
		//Then stick it into the "next" of newHead
		newHead->next = &next;
		//Then finally insert the element
		newHead->ele = ele;
		
		len++;
	}
}

char* GStack::peek() {
	return head->ele;
}



