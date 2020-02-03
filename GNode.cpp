//GNode.cpp
#include "GNode.h"

//Constructor
GNode::GNode(char ele) {
	this->ele = ele;
	next = NULL;
}

//Desctructor
GNode::~GNode() {
	delete(ele);
	delete(next);
	ele = NULL;
	next = NULL;
}

//Set the next item in the array
void setNext(GNode* next) {
	this->next = next;
}