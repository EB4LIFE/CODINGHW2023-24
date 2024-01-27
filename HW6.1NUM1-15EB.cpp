#include<iostream>
using namespace std;

//initlaizing functions we will need - will be set below intmain
//this will fill array  in main with 15 numbers
void Fillarray(int arr[], const int size);
//checkin to see if the 15 num printed are between 1-15
bool checkarray(int arr2[], const int size);




int main() {
	int num[15] = { 0 };
	int size = 15;
	bool ISgood;
	cout << "enter 15 numbers:" << endl;
	//calling the functions - first till fill array and second to check the numbers
	Fillarray(num, size); 
	ISgood = checkarray(num, size);
	//result 
	//there are 15 num printed between 1-5
	if (ISgood == true) {
		cout << "GOOD" << endl;
	}
	//otherwise:
	else {
		cout << "NOT GOOD" << endl;
	}
}
//intilaizing the functions below
void Fillarray(int arr[], const int size) {
	for (int i = 0; i < size; i++) {
		cin >> arr[i];
		//as it goes through the loop it will input a digit into the array
	}
}
bool checkarray(int arr1[], const int size) {
	bool checker = false;
	//confirms number are between 1-15 (index of 14)
	for (int i = 0; i < size; i++) {
		if ((arr1[i] > 0) && (arr1[i] < 16)) {
			checker = true;
		}
		else {
			checker = false;
			break;
		}
		//Must make sure there are no double values in the array
		for (int j = i; j < size; j++) {
			if (j != i) {
				//if there is a duplicate element
				if (arr1[j] == arr1[i]) {
					checker = false; 
					break;
				}
			}
		}
		//leaving the i loop because of duplicate
		if (checker == false) {
			break;
		}
	}
	return checker;
}
