/*

 */
#include <iostream>
#include <cstring>

using namespace std;

int main() {

	char* in = new char[1000];
  
	cout << "Hello, user. Please enter in your equation, using infix format, separated by spaces (e.x. 3 + 4): ";

	cin.getline(in, 1000);

	//Only allow numbers and operators
	for (int i = 0; i < strlen(in); i++) {
		if (in[i] <= 39 ||
		in[i] == 44) {
    
	}
}
  
	cout << in << endl;
  
}
