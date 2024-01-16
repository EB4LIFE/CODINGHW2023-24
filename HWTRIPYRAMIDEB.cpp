#include <iostream>
using namespace std;

int main() {

	int n;

	cout << "enter a one digit number:" << endl;
	cin >> n;
	//n must be postive 
	while (n <= 0 || n >= 10) {
		cout << "ERROR" << endl;
		cin >> n;
	}
	//first for loop== rows
	for (int rows = n - 1; rows >= 0; --rows) {
		//second for loop == columns
		for (int col = n - 2; col >= rows; --col) {
			cout << "   ";
		}
		int output = rows;
		//now we need to add comma and space after each number in the pyrmaid triangle
		while (output < n && output >= 0) {
			cout << output + 1;
			//will continue if doesn't hit the last digit which in this code would be 1
			if (output + 1 != 1) {
				cout << ", ";
			}
			else {
				cout << endl;
			}
			output--; //one less column which means one less number
		}
	}
	return 0;
}
