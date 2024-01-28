#include<iostream>
using namespace std;

/* 
* The set difference between two sets s1 and s2 is the set that contains all
elements in s1 that are not in s2. For example, if s1= {1,3,5,7,9} and
s2={1,2,3,4,5}, then the set difference s1-s2={7,9}.
Write a program that reads in 6 positive integers into the array set1 and 6
positive integers into the array set2 and creates a third array called
difference that contains the set difference of set1 and set2.
If difference is not empty, the program prints out its elements. If difference
is empty, then the program prints empty.
You can assume that there are no repeating elements in either set, but
the sets are not necessarily ordered.
enter first 6 numbers:
10 9 7 5 3 1
enter next 6 numbers:
6 5 4 3 2 1
set difference is:
10 9 7
----------
enter first 6 numbers:
10 9 7 5 3 1
enter next 6 numbers:
1 3 5 7 9 10
set difference is:
empty
*/
void Fillarray(int arr[], const int size);
bool checkDif(int e1, int arr2[], int size);
void FillDif(int arr1[], int arr2[], int arrDif[], int size);
void PrintDif(int arrDif[], int size);


int main() {
	int set1[6];
	int set2[6];
	int difference[6] = { 0 };
	cout << "enter first 6 numbers:" << endl;
	Fillarray(set1, 6);
	cout << "enter next 6 numbers:" << endl;
	Fillarray(set2, 6);
	FillDif(set1, set2, difference, 6);
	cout << "set difference is:" << endl;
	PrintDif(difference, 6);
	return 0; 
}

void Fillarray(int arr[], const int size) {
	int userinput;
	for (int i = 1; i < size; i++) {
		cin >> userinput;
		if (userinput <= 0) {
			break;
		}
		else {
			arr[i] = userinput;
		}
	}
}
bool checkDif(int e1, int arr2[], int size) {
	//We need to see if there specific elements in the set {THIS function will be a buldingblock in the function below
	bool jamesbonded = false; //if they are in the set or not
	for (int i = 0; i < size; i++) {
		if (e1 == arr2[i]) {
			jamesbonded = true; \
				break;
		}
	}
	return jamesbonded;
}
void FillDif(int arr1[], int arr2[], int arrDif[], int size) {
	//comparing elemenets of Array 1 to Array 2
	//result will leave over any remaining elements from Array 1 into the array Difference
	bool Jbond;
	for (int i = 0; i < size; i++) {
		Jbond = checkDif(arr1[i], arr2, size);

		if (Jbond == true) {
			arrDif[i] = 0;
		}
		else {
			arrDif[i] = arr1[i];
		}
	}
}
void PrintDif(int arrDif[], int size) {
	bool empty = true; 
	for (int i = 0; i < size; i++) {
		if (arrDif[i] == 0) {
			empty = true;
		}
		else {
			empty = false;
			break;
		}
	}
	if (empty==true) {
		cout << "empty" << endl;
	}
	else {
		for (int j = 0; j < size; j++) {
			if (arrDif[j] != 0) {
				cout << arrDif[j] << " ";
			}
		}
	}
}
