
#include<iostream>
using namespace std;
//fill the empty array
void Fillarray(int arr[], const int size);
//will remove any double valuus from the array
void Fixarray(int arr1[], const int size);
//will print new array as well as count elements
int Printrem(int arr2[], const int size);

int main() {
	int hunnum[100] = { 0 }; 
	int leftover;
	cout << "enter up to 100 values, to stop enter 0:" << endl;
	Fillarray(hunnum, 100);
	Fixarray(hunnum, 100);
	cout << "the new vector is:" << endl;
	//will print new edited array without any doubles
	leftover = Printrem(hunnum, 100);
	//will print amount of elements in the array
	cout << "number of elements: " << leftover << endl;

	return 0;

}

void Fillarray(int arr[], const int size) {
	int userinput;
	for (int i = 0; i < size; i++) {
		cin >> userinput;
		if(userinput == 0) {
			break;
		}
		else {
			arr[i] = userinput;
		}
		//as it goes through the loop it will input a digit into the array
	}
}
void Fixarray(int arr1[], const int size) {
	//moves through the array
	for (int i = 0; i < size; i++) {
		//condtion that will help in print the array (next function Printrem) in which we will skip over every zero
		if (arr1[i] == 0) {
			break;
		}
		//go through array counting down
		for (int j = i; j >= 0; j--) {
			if (j != i) {
				//Uf there is a duplicate then as stated before make the value zero so that it can be skipped over in function Printrem
				if (arr1[i] == arr1[j]) {
					arr1[i] = 0;
				}
			}
		}
	}
}

int Printrem(int arr2[], const int size) {
	int count = 0;
	for (int i = 0; i < size; i++) {
		if (arr2[i] != 0) {
			cout << arr2[i] << " ";
			count++;
		}
	} 
	cout << endl;
	return count;
}
