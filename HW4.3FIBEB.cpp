#include <iostream>
using namespace std;

//fibi code that will print digits of the code starting from n+1 becuase 0 is first of code and will start from the one after - Eitan brown

int main() {

	int digits;
	//variables for fib for loop later
	int f1=0; //first of fib seqeunce setting it
	int f2=1; //second of fib seqeunce setting it
	int ff = 0;  //set to zero so that after each run of later for loop can set it back to orignal value which will be 0
	//Ask for how many number of Fibi code to print
	cout << "enter a number:" << endl;
	cin >> digits; 
	//while loop to make sure number inputed is positive and can't be zero as that will always be printed 
	while (digits < 0) {
		cout << "ERROR" << endl;
		cin >> digits;
	}
	for (int i = 1; i <= digits + 1; ++i) {
		if (i == 1) {
			cout << f1 << " ";
			continue;
		}
		if (i == 2) {
			cout << f2 << " ";
			continue;
		}
		ff = f1 + f2;
		f1 = f2;
		f2 = ff;
		cout << ff << " ";
	}
	return 0;
}
