/*
main.cpp
This program takes an input of an infix notation equation (the format most people understand), and converts it to postfix notation. Then, it will convert to then output either infix, postfix, or prefix notation.

@author Greggory Hickman, January-February 2020
@version dev
 */
#include <iostream>
#include <cstring>

#include "GStack.h"
#include "GQueue.h"

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
	cout << "Hello, user. Please enter in your equation, using infix format, separated by spaces (e.x. 3 + 4 * ( 25 ^ 2 )): " << endl;
	cin.getline(in,  MAXLEN);

	/*
	The following code is meant to get rid of any invalid tokens, while separating the input into its individual tokens, putting them into the queue at the same time. 
	Optionally, it can produce a zero-terminated string version at the same time for debugging purposes (to do that, just uncomment all of the random code snippets throughout the main method).
	Invalid tokens are tokens with either a mixture of numbers and operators, or more than one operator
	The parsed input is stored in "parin"
	
	"temp" is the holder for the current token
	"i" is the iterator for the input
	"j" is represents the current amount of chars since a space was seen
	"wasSpace" is true if the last char was a space
	"wasOp" is true if the last or current char is an operator
	"lastOp" is true if the last token was an operator
	"openPend" is true if there is a pending open brace
	 */ 
	
	char* temp = new char[MAXLEN];
	bool wasSpace = false;
	bool wasOp = false;
	bool lastOp = true; //Starting with this as true solves some issues with the very first character being registered correctly
	bool openPend = false;
	int j = 0;
	int k = 0;
	
	//Clear temp. I know that I really should make a method for this but I'm running out of time on this project and I don't want to spend time figuring that out when this is only adds a few lines of code
	for (int i = 0; i < MAXLEN; i++)
		temp[i] = 0;
	
	//Parse the input
	for (int i = 0; i < strlen(in) + 1; i++) {
		//cout << in[i] << ": ";
		
		//If is a number
		if (in[i] >= 48 && in[i] <= 57) {
			//cout << "Number, ";
			//If last element or token was an operator, ignore the rest of the phrase
			if (!wasOp && lastOp) {
				//Add in[i] to temp
				//cout << "Was not op, ";
				wasSpace = false;
				lastOp = false;
				temp[j] = in[i];
				j++;
			}
		}
		//If is an operator, not including parentheses because those are allowed to be next to other operators
		else if (in[i] == 42 ||
		in[i] == 43 ||
		in[i] == 45 ||
		in[i] == 47 ||
		in[i] == 94) {
			//cout << "Operator, ";
			if (!wasOp && !lastOp) {
				//cout << "Was not op, ";
				wasSpace = false;
				wasOp = true;
				lastOp = true;
				//Add in[i] to temp
				temp[j] = in[i];
				j++;
			}
		}
		//If is a parenthesis
		else if (in[i] == 40 ||
		in[i] == 41) {
			cout << "Parenthesis, ";
			
			//Must be after another operator, but not in the same phrase
			if (lastOp && in[i] == 40) {
				cout << "Open brace, ";
				
				wasSpace = false;
				openPend = true;
				wasOp = true;
				
				//Add in[i] to temp
				temp[j] = in[i];
				j++;
			}
			//If a close brace, it can occur anyplace on its own after an open brace, unless the last token was an operator
			else if (wasSpace && !wasOp && openPend) {
				cout << "Last was op, ";
				cout << "Was space, ";
				
				wasSpace = false;
				openPend = false;
				wasOp = true;
				
				//Add in[i] to temp
				temp[j] = in[i];
				j++;
			}
		}
		//If is a space and the previous one was not a space
		else if (in[i] == 32 && wasSpace == false) {
			//cout << "Space" << endl;
			//cout << "New phrase: " << temp << endl;
			
			//Append temp to the end of parin
			//strcat(parin, temp);
			stack.push_back(temp);
						
			//Add a space at the end for viewing purposes
			strcat(parin, " ");
			
			//Clear temp
			for (int i = 0; i < MAXLEN; i++)
				temp[i] = 0;
			
			wasOp = false;
			wasSpace = true;
			j = 0;
			k++;
			
		}
		//If is null
		else if (in[i] == 0) {
			//cout << "Null" << endl;
			//cout << "New phrase: " << temp << endl;
			
			//Append temp to the end of parin
			//strcat(parin, temp);
			//strcat(parin, " ");
			stack.push_back(temp);
			
			//Clear temp
			for (int i = 0; i < MAXLEN; i++)
				temp[i] = 0;
			
			j = 0;
			k++;
			
			break;
		}
		cout << endl;
	}
	
	//cout << "Parin: " << endl;
	//cout << parin << endl;
	
	cout << "Stack: " << endl;
	for (int i = 0; i < k; i++) {
		cout << stack.peek() << endl;
		stack.pop();
	}
}

//We do not speak of the code past this point
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
