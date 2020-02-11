//GStack.cpp
#include "GStack.h"
#include <iostream>

//Constructor
GStack::GStack() {
	head = NULL;
}

//Desconstructor
GStack::~GStack() {
	delete head;
}

void GStack::pop() {
	head = head->next;
}

void GStack::push_back(char* ele) {
	GNode newHead;
	newHead.ele = ele;
	newHead.next = head;
	delete head;
	head = &newHead;
}

char* GStack::peek() {
	return head->ele;
}





