/*
main.cpp
This program takes an input of an infix notation equation (the format most people 
 */
#include <iostream>
#include <cstring>

#include "GStack.h"

using namespace std;

int main() {

	//Initialize important variables
	char in[10000];
	char** parin = new char*[1000];
	GStack stack();
  
	//Grab that input
	cout << "Hello, user. Please enter in your equation, using infix format, separated by spaces (e.x. 3 + 4): ";
	cin.getline(in, 1000);

	char* temp = new char[1000];
	bool wasSpace = false;
	int j = 0;
	int k = 0;
	//Only allow numbers and operators
	for (int i = 0; i < strlen(in) + 1; i++) {
		//If is a number or operator
		if ((in[i] >= 40 && 
		in[i] <= 57) ||
		in[i] == 61) {
			//cout << "Number/Operator: " << in[i] << endl;
			temp[j] = in[i];
			
			wasSpace = false;
			j++;
		}
		//If is a space and the previous one was not a space
		else if (in[i] == 32 && wasSpace == false) {
			cout << "New phrase: " << temp << endl;
			parin[k] = temp;
			
			temp = new char[1000];
			wasSpace = true;
			j = 0;
			k++;
		}
		//If is null
		else if (in[i] == 0) {
			cout << "New phrase: " << temp << endl;
			parin[k] = temp;
			
			temp = new char[1000];
			j = 0;
			k++;
			
			break;
		}
		else {
			wasSpace = true;
		}
	}
	cout << "Parin: " /*<< (sizeof(parin) / sizeof(parin[0])) */ << endl;
	for (int i = 0; i < 1000; i++) {
		//cout << parin[i] << endl;
		stack.push_back(parin[i]);
		cout << stack.peek() << endl;
	}
}
