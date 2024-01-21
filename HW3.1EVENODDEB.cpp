#include <iostream>
using namespace std;
int main() {
	
	int a;
	int num1;
	int num2;

	cout << "Enter a number:" << endl;
	cin >> a;

	if ((a >= 10) && (a < 100)) {
		num1 = (a / 10) % 10; 
		num2 = a % 10;
	}
	else {
		cout << "ERROR" << endl;
	}
	if ((num1 % 2 == 0) && (num2 % 2 ==0)) {
		cout << "Even digits only" << endl;
		cout << num1 * num2 << endl;

	}
	else if ((num1 % 2 != 0) && (num2 % 2 !=0)) {
		cout << "Odd digits only" << endl;
		cout << num1 + num2 << endl;
	}
	else {
		cout << "Mixed Number" << endl;
	}
	return 0;
}
