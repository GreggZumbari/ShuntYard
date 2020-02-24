//GQueue.cpp

#include "GQueue.h"

//Constructor
GQueue::GQueue() {
	head = new GNode();
	strcpy(head->ele, "TAIL");
	len = 0;
}

//Desconstructor
GQueue::~GQueue() {}


void GQueue::pop() {
	if (len > 0) {
		head = head->next;
		len--;
	}
}

void GQueue::enqueue(char*) {
	if (len < MAXLEN) {
		GNode* newHead = new GNode();
		
		//Then stick it into the "next" of newHead
		newHead->next = head;
		//Insert the element
		strcpy(newHead->ele, ele);
		//newHead->ele = ele;
		
		//Replace head with newHead
		head = newHead;
		len++;
	}
}

void GQueue::push_back(char* ele) {
	if (len < MAXLEN) {
		GNode* newHead = new GNode();
		
		//Then stick it into the "next" of newHead
		newHead->next = head;
		//Insert the element
		strcpy(newHead->ele, ele);
		//newHead->ele = ele;
		
		//Replace head with newHead
		head = newHead;
		len++;
	}
}

char* GQueue::peek() {
	//cout << "Peek: " << head->ele << endl;
	return head->ele;
}
