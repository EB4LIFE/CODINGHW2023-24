#include <iostream>
using namespace std;

/* This program will take 2 numbers and read them in a list of numbers until their
sum > the first number or the number of numbers read =
to the second number, and then prints out the final sum - Eitan brown
*/

int main() {

	int n1;
	int n2;
	

	cout << "enter 2 positive numbers:" << endl;
	cin >> n1;
	while (n1 <= 0) {
		cout << "ERROR" << endl;
		cin >> n1;
	}
	cin >> n2;
	while (n2 <= 0) {
		cout << "ERROR" << endl;
		cin >> n2;
	}
}
