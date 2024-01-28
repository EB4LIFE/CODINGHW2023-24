#include<iostream>
using namespace std;

void Fillarray(float arr[], const int size);
void sortIndices(float arr1[], int arr2[], const int size);
void orderchange(int& x, int& y);
void Printarray(int arr3[], const int size);


int main() {
	
	float numbers[6];
	int size = 6;
	cout << "enter 6 numbers between 0 and 1:" << endl;
	Fillarray(numbers, size);
	int indices[6] = { 0,1,2,3,4,5 };
	sortIndices(numbers, indices, size);
	cout << "sorted indices:" << endl;
	Printarray(indices, size);
	cout << endl;

	return 0;
}
void Fillarray(float arr[], const int size) {
	bool  Notvalid = true;
	float userinput;
	while (Notvalid == true) {
		Notvalid = false;
		for (int i = 0; i < size; i++) {
			cin >> userinput;
			if (userinput <= 0 || userinput >= 1) {
				Notvalid = true;
			}
			else {
				arr[i] = userinput;
			}
		}
		if (Notvalid == false) {
			break;
		}
		cout << "ERROR" << endl;
	}
}
void orderchange(int& x, int& y) {
	int temp = x;
	x = y;
	y = temp;
}
void sortIndices(float arr1[], int arr2[], const int size) {
	//values of arr1 at index of arr2 to order it
	for (int i = 0; i < size; i++) {
		//acutal doing the comparing
		for (int j = i; j < size; j++) {
			if (arr1[arr2[j]] < arr1[arr2[i]]) {
				orderchange(arr2[j], arr2[i]);
			}
		}
	}
}
void Printarray(int arr3[], const int size) {
	for (int i = 0; i < size; i++) {
		cout << arr3[i] << " ";
	}
	}
