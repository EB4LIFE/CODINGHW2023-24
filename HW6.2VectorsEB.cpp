#include<iostream>
using namespace std;

//function to fill array we wiil use in the function
void Fillarray(int arr[], const int size);
//checks to see if inputed value is with the range necessary
void Checkinput(int& userint, int limit);
//checks and prints out the number of times vector1 contains the elements in vector2, 
// that is, the number of times the elements invector2 is repeated in vector1.
int combocheck(int arr1[], const int s1, int arr2[], const int s2);


int main() {
	int v1;
	int v2;
	int combo;

	cout << "enter size of first array:" << endl;
	cin >> v1;
	Checkinput(v1, 500);

	int vector1[500];

	cout << "enter first array values:" << endl;
	Fillarray(vector1, v1);

	cout << "enter size of second array:" << endl;
	cin >> v2;
	Checkinput(v2, 100);

	int vector2[100];

	cout << "enter second array values:" << endl;
	Fillarray(vector2, v2);


	combo = combocheck(vector1, v1, vector2, v2);
	cout << "Result: " << combo << " times";

}
//intilaizing the functions below
void Checkinput(int& userint, int limit) {
	while (userint >= limit) {
		cout << "ERROR" << endl;
		cin >> userint;
	}
}
void Fillarray(int arr[], const int size) {
	for (int i = 0; i < size; i++) {
		cin >> arr[i];
		//as it goes through the loop it will input a digit into the array

	}
}
int combocheck(int arr1[], const int s1, int arr2[], const int s2) {
	int times = 0; 
	bool Isin = false;

	//to see how many times arr 2 can go into arr 1
	for (int i = 0; i < (s1 - s2)+1; i++) {
		//checking actual elements of arr2 
		for (int j = 0; j < s2; j++) {
			if (arr1[i + j] != arr2[j]) {
				Isin = false;
				break;
			}
			else {
				Isin = true;
			}
		}
		if (Isin == true) {
			times++;
		}
	}
		return times;
}
