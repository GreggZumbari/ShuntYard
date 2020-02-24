/*
main.cpp
This program takes an input of an infix notation equation (the format most people understand)
 */
#include <iostream>
#include <cstring>

#include "GStack.h"

using namespace std;

int main() {

	//Initialize important variables
	char in[10000];
	char** parin = new char*[100];
	GStack stack;
  
	//Grab that input
	cout << "Hello, user. Please enter in your equation, using infix format, separated by spaces (e.x. 3 + 4 * ( 25 ^ 2 )): ";
	cin.getline(in, 10000);

	/*
	The following code is meant to separate the input into individual elements of numbers and operators
	The parsed inputs are stored in "parin"
	
	"i" is the iterator for the input
	"j" is represents the current amount of chars since a space was seen
	"k" is the iterator for parin
	"wasSpace" is true if the last char was a space
	 */
	char* temp = new char[100];
	bool wasSpace = false;
	int j = 0;
	int k = 0;
	//Only allow numbers and operators
	for (int i = 0; i < strlen(in) + 1; i++) {
		//If is a number or operator
		if ((in[i] >= 40 && 
		in[i] <= 57) ||
		in[i] == 61) {
			cout << "In: " << in[i] << endl;
			//cout << "Number/Operator: " << in[i] << endl;
			temp[j] = in[i];
			
			wasSpace = false;
			j++;
		}
		//If is a space and the previous one was not a space
		else if (in[i] == 32 && wasSpace == false) {
			cout << "New phrase: " << temp << endl;
			parin[k] = temp;
			
			temp = new char[100];
			wasSpace = true;
			j = 0;
			k++;
		}
		//If is null
		else if (in[i] == 0) {
			cout << "New phrase: " << temp << endl;
			parin[k] = temp;
			
			temp = new char[100];
			j = 0;
			k++;
			
			break;
		}
		else {
			wasSpace = true;
		}
	}
	cout << "Parin: " << endl;
	for (int i = 0; i < k; i++) {
		cout << parin[i] << endl;
	}
	
	cout << "Stack: " << endl;
	for (int i = 0; i < k; i++) {
		//cout << parin[i] << endl;
		stack.push_back(parin[i]);
		cout << stack.peek() << endl;
	}
}
