#include <iostream> 
using namespace std;

/* This program will take in 2 inputs from the user, x and n, and
will print out the sum of a series based in x, n number of times
Series is: X + (-1/3)X^3  + (1/5)X^5 + (-1/7)X^7 + …. +((-1)^n-1/2n-1)X^2n-1
*/
int main() {
	int x; //base of expo term
	int n; //amount of elements 
	int ctop;
	int cbottom;
	//double are so that in case an asnwer will end with a decimal so it is possible
	double sum = 0;
	double element;
	double Xt;
	double fullc;
	cout << "enter 2 numbers:" << endl;
	cin >> x >> n;
	//while loop becuase n must be postive 
	while (n < 0) {
		cout << "ERROR" << endl;
		cin >> n;
	}
	ctop = -1; //set to -1 to help when doing th loop to make first term positive
	cbottom = 1; //since we want it odd we need this odd as well
	for (int i = 0; i < n; ++i) {

		ctop *= -1; //multiply everything by -1 to find sign the particular term in the loop
		fullc = (double)ctop / cbottom;  //setting the full term
		Xt = 1; 

		for (int j = 0; j < cbottom; ++j) {
			Xt *= x; //factorial of x of cbottom
		}
		cbottom += 2; //as stated before will now make it odd 1,3,5,7
		element = fullc * Xt;  //sets the next element
		sum += element; //adds new element to the sum
	}
	cout << sum;
	return 0;

}
