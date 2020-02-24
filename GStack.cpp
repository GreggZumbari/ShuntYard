//GStack.cpp

#include "GStack.h"

//Constructor
GStack::GStack() {
	len = 0;
}

//Desconstructor
GStack::~GStack() {}


void GStack::pop() {
	head = head->next;
	len--;
}

void GStack::push_back(char* ele) {
	if (len < 100) {
		GNode newHead;
		newHead.ele = ele;
		newHead.next = head;
		head = &newHead;
		len++;
	}
}

char* GStack::peek() {
	return head->ele;
}



