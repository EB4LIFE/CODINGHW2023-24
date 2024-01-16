#include <iostream>
#include <ctime>
using namespace std;

/* Eitan Brown: This program will print 10 random numbers and then determine if they are in a sorted list or not and will act accordingly*/

int main() {

	int n; //variable to store value
	int n2; //for for loop to to compare the 2-9 numbers to see if sorted or not
	bool  isSorted = true; //Whether or not it is sorted or not

	srand(time(0)); //random number generator

	n = rand() % 1000 + 1; //first of the random numbers  and sets the range
	cout << n << " "; // printing random number

	//Below for loop in which we repaeat random number process up until we hit total of 10 digits (1 from before loop and 9 in loop) 
	for (int i = 0; i < 9; i++) { 
		n2 = rand() % 1000 + 1;
		cout << n2 << " ";
		if (n2 < n) { //after each loop, it will evaluate if it is sorted so once loop is over we can apply it 
			isSorted = false;
			
		}
		n = n2; //changing intial number to a second variable so when e go through the loop again it will compare both values 
	}
	//loop ended now we need to see if bool still equals true or is it false
	if (isSorted == true) { //still equals true
		cout << endl << "sorted list";
	}
	else { //Or equals false
		cout << endl << "not sorted list";
	}
	return 0;
}
/*
465 256 506 195 972 569 833 792 301 29
not sorted list
C : \Users\eitan\source\repos\PROJECTEBCODE\x64\Debug\PROJECTEBCODE.exe(process 132480) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .
*/
