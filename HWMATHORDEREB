#include <iostream>
using namespace std;
int main() {

	int num1, num2, num3, smallest, middle, biggest;
	cout << "enter 3 numbers: " << endl;
	cin >> num1 >> num2 >> num3;


	if (num1 > num2) {  
		if (num2 > num3) { 
			biggest = num1;
			middle = num2;
			smallest = num3;
		}
		else if (num3 < num1 && num3 > num2) { 
			biggest = num1;
			middle = num3;
			smallest = num2;
		}
		else if (num3 > num1) { 
			biggest = num3;
			middle = num1;
			smallest = num2;
		}
	}
	else {   
		if (num1 > num3) { 
			biggest = num2;
			middle = num1;
			smallest = num3;
		}
		else if (num2 > num3 && num3 > num1) { 
			biggest = num2;
			middle = num3;
			smallest = num1;
		}
		else {       
			biggest = num3;
			middle = num2;
			smallest = num1;
		}
	}
	cout << smallest << " " << middle << " " << biggest << endl;
	return 0;
	}
