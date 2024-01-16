#include <iostream>
using namespace std;

/* This program will take 2 numbers and read them in a list of numbers until their
sum > the first number or the number of numbers read =
to the second number, and then prints out the final sum - Eitan brown
*/

int main() {

	int n1;
	int n2;
	int sumlim;
	int amtlim;
	int numlist;
	int sum=0;
	int nsum;
	int amtcheck=0;
	
	cout << "enter 2 positive numbers:" << endl; 
	cin >> n1;
	//while loop to see if it is postive input and will say error until input is correct for number 1
	while (n1 <= 0) {
		cout << "ERROR" << endl;
		cin >> n1;
	}
	//while loop to see if it is postive input and will say error until input is correct for number 2
	cin >> n2;
	while (n2 <= 0) {
		cout << "ERROR" << endl;
		cin >> n2;
	}
	//part 2 
	sumlim = n1; //sets the max sum for loop below
	amtlim = n2; //sets amount of numbers for loop below
	cout << "enter a list of numbers:" << endl;
	//value of n2(amtlim) is more than amtcheck and sum is less or equal to n1(sumlim)
	while (amtcheck < amtlim && sum <= sumlim) {
		cin >> numlist; //list inputed
		nsum = numlist;  //adds new numbers added as new number store value 
		sum += nsum; //adds new sum to final sum 
		amtcheck++; //1 for ever number stored
	}
	cout << sum << endl; //prints value of listed numbers added together
	return 0;

}
