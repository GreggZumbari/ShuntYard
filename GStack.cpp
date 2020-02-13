//GStack.cpp

#include "GStack.h"

//Constructor
GStack::GStack() {
	head = NULL;
	len = 0;
}

//Desconstructor
GStack::~GStack() {
	delete head;
}

void GStack::pop() {
	head = head->next;
	len--;
}

void GStack::push_back(char* ele) {
	if (len < maxLen) {
		GNode newHead;
		newHead.ele = ele;
		newHead.next = head;
		delete head;
		head = &newHead;
		len++;
	}
}

char* GStack::peek() {
	return head->ele;
}

bool GStack::isEmpty() {
	if (head->ele == "EMPTY")
		return true;
	else
		return false;
}

bool GStack::isFull() {
	if (len >= maxLen)
		return true;
	else
		return false;
}





