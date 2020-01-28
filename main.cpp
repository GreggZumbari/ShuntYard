#include <iostream>
#include <cstring>

using namespace std;

int main() {

  char* in = new char[1000];
  
  cout << "Hello, user. Please enter in your equation, using infix format, separated by spaces (e.x. 3 + 4): ";

  cin.getline(in, 1000);

  cout << strlen(in) << endl;
  
}
