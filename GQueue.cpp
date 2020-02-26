//GQueue.cpp

#include "GQueue.h"

//Constructor
GQueue::GQueue() {
	front = new GNode();
	len = 0;
}

//Desconstructor
GQueue::~GQueue() {}

void GQueue::enqueue(char* ele) {
	if (len < MAXLEN) {
		GNode* current = front;
		
		//cout << "Len: " << len << endl;
		//cout << "Current Beginning: " << current->ele << endl;
		
		//Go through the linked list until we get to the end
		for (int i = 0; i < len + 1; i++) {
			
			//If we are at the end of the linked list
			if (i == len) {
				//Create the GNode to hold the element
				GNode* newTail = new GNode();
				strcpy(newTail->ele, ele);
				
				//Stick it onto the end
				current->next = newTail;
				//cout << "newTail: " << current->ele << endl;
			}
			
			//Iterate to next GNode
			current = current->next;
			
			//cout << "Current After: " << current->ele << endl;
			//cout << "Next: " << current->next->ele << endl << endl;
		}
		
		//cout << "Final Current: " << current->ele << endl << endl;
		len++;
	}
}

char* GQueue::dequeue() {
	if (front->next->ele[0] != '\0' && front->next->ele[0] != 0 && front->next->ele != NULL) {
		//Grab a copy of the current first in queue for later.
		GNode current = *front->next;
		//cout << "Len: " << len << endl;
		if (len >= 1) {
			//Grab the second in queue
			GNode* newFront = front->next;
			//Move it up to the first in queue
			front = newFront;
			len--;
		}
		else {
			current.ele[0] = 0;
			return current.ele;
		}
		
		//Return the copied ex-first in queue
		return current.ele;
	}
	return NULL;
}
