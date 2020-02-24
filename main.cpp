/*
main.cpp
This program takes an input of an infix notation equation (the format most people understand)

@author Greggory Hickman, January-Febuary 2020
@version dev
 */
#include <iostream>
#include <cstring>

#include "GStack.h"

using namespace std;

int main() {

	//Initialize important variables
	char* in = new char[MAXLEN];
	char* parin = new char[MAXLEN];
	GStack stack;
	
	//Clear in and parin
	for (int i = 0; i < MAXLEN; i++) {
		in[i] = '\0';
		parin[i] = '\0';
	}
  
	//Grab that input
	cout << "Hello, user. Please enter in your equation, using infix format, separated by spaces (e.x. 3 + 4 * ( 25 ^ 2 )): ";
	cin.getline(in,  MAXLEN);

	/*
	The following code is meant to put the input into a stack, while producing a zero-terminated string version at the same time, as well as getting rid of any invalid tokens
	Invalid tokens are tokens with either a mixture of numbers and operators, or more than one operator
	The parsed input is stored in "parin"
	
	"temp" is the holder for the current token
	"i" is the iterator for the input
	"j" is represents the current amount of chars since a space was seen
	"wasSpace" is true if the last char was a space
	"wasInv" is true if the last or current char is an operator
	 */
	char* temp = new char[MAXLEN];
	bool wasSpace = false;
	bool wasOp = false;
	int j = 0;
	
	for (int i = 0; i < MAXLEN; i++) {
		temp[i] = 0;
	}
	
	//Parse the input
	for (int i = 0; i < strlen(in) + 1; i++) {
		cout << in[i] << ": ";
		
		//If is a number
		if (in[i] >= 48 && in[i] <= 57) {
			cout << "Number, ";
			//If last element was an operator, ignore the rest of the phrase
			if (!wasOp) {
				//Add in[i] to temp
				cout << "Was not op, ";
				wasSpace = false;
				temp[j] = in[i];
				j++;
			}
		}
		//If is an operator
		else if ((in[i] >= 40 && 
		in[i] <= 57) ||
		in[i] == 61) {
			cout << "Operator, ";
			if (!wasOp) {
				cout << "Was not op, ";
				wasSpace = false;
				wasOp = true;
				//Add in[i] to temp
				temp[j] = in[i];
				j++;
			}
		}
		//If is a space and the previous one was not a space
		else if (in[i] == 32 && wasSpace == false) {
			cout << "Space" << endl;
			cout << "New phrase: " << temp << endl;
			
			//Append temp to the end of parin
			strcat(parin, temp);
			strcat(parin, " ");
			stack.push_back(temp);
			
			//Clear temp. I know that I really should make a method for this but I'm running out of time on this project and I don't want to spend time figuring that out
			for (int i = 0; i < MAXLEN; i++) {
				temp[i] = 0;
			}
			
			wasOp = false;
			wasSpace = true;
			j = 0;
		}
		//If is null
		else if (in[i] == 0) {
			cout << "Null" << endl;
			cout << "New phrase: " << temp << endl;
			
			//Append temp to the end of parin
			strcat(parin, temp);
			strcat(parin, " ");
			stack.push_back(temp);
			
			//Clear temp
			for (int i = 0; i < MAXLEN; i++) {
				temp[i] = 0;
			}
			
			j = 0;
			
			break;
		}
		cout << endl;
	}
	
	/*
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
			
			temp = new char[MAXLEN];
			wasSpace = true;
			j = 0;
			k++;
		}
		//If is null
		else if (in[i] == 0) {
			cout << "New phrase: " << temp << endl;
			parin[k] = temp;
			
			temp = new char[MAXLEN];
			j = 0;
			k++;
			
			break;
		}
		else {
			wasSpace = true;
		}
	}
	*/
	
	cout << "Parin: " << endl;
	cout << parin << endl;
	
	cout << "Stack: " << endl;
	for (int i = 0; i < strlen(parin); i++) {
		cout << stack.peek() << endl;
		stack.pop();
	}
}
