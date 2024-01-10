#include <iostream>
using namespace std;

int main() {
	int l1;
	int l2;
	int l3;

	cout << "enter 3 numbers:" << endl;
	cin >> l1 >> l2 >> l3;

	if ((l1 <= 0) || (l2 <= 0) || (l3 <= 0)) {
		cout << "ERROR" << endl;
	}
	if ((l1 + l2 <= l3) || (l1 + l3 <= l2) || (l2 + l3 <= l1)) {
		cout << "cannot form a triangle" << endl;
	}
	else {
	if (l1 == l2 && l2 == l3) {
		cout << "equilateral triangle" << endl;
	}
	else if ((l1 == l2) || (l1 == l3) || (l2 == l3)) {
		cout << "isosceles triangle" << endl;
	}
	else {
		// no sides equal
		cout << "scalene triangle";
	}
	}
	return 0;
}
