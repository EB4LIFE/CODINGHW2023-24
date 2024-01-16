#include <iostream>
using namespace std;

int main() {

	int num;
	int digit;
	int prevleft;
	bool lessthan = true;
	//asks for digit that will be needed for program
	cout << "enter a number:";
	cin >> num;
	//digit must be positive or display error
	while (num <= 0) {
		cout << "ERROR" << endl;
		cin >> num;
	}
	digit = 0; 
	prevleft = num % 10; //help get the right most digit
	num /= 10; //To know if user inputed a single digit or not

	do {
		if (num == 0) { 
			break;
		}
		digit = prevleft; 
		nextLeft = num % 10;
		if (digit >= prevleft) { 
			lessthan = false; 
			break; 
		}
	}
	while ((num /= 10) != 0); 
	if (lessthan == true) { 
		cout << "YES";
	}
	else {
		cout << "NO"; 
	}
	return 0;
}
