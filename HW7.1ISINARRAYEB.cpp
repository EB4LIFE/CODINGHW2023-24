#include<iostream>
using namespace std;

bool Sorted(int arr[], const int size);
bool AllDiff(int arr[], const int size);
void fillArray(int arr[], const int size);
int Binarysearch(int arr[], const int size, int userint);


int main() {
	int arrX[10] = { 0 };
	int usernum;
	int index;
	// s1 Prompt user to put 10 digit array and must be in asending order and no pulicate 
	cout << "enter 10 numbers:" << endl;
	//needs met inside of function as described below 
	fillArray(arrX, 10);
	//if it is in ascending order then prompot user to  choose a number 
	cout << "enter 1 number:" << endl;
	cin >> usernum;
	index = Binarysearch(arrX, 10, usernum); 
	if (index < 0) { 
		cout << "not found" << endl;
	}
	else {
		cout << "the number " << usernum << " was found at index " << index << endl;
	}

	return 0;
}
//steeping stone function to help in fill array - will make sure it is ascending order
bool Sorted(int arrsort[], const int size) {
	for (int i = 0; i < size-1; i++) {
		if (arrsort[i] > arrsort[i + 1]) {
			return false;
		}
	}
	return true;
}


//stepping stone function to help in fill array - will make sure no dulicates exist
bool AllDiff(int arrAD[], const int size) {
	for(int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++) {
			if (j != i) {
			  if (arrAD[i] == arrAD[j]) {
				  return false;
				}
			}
		}
	}
	return true;
}

void fillArray(int arr[], const int size) {
	bool sorted;
	bool alldiff;
	//this do loop will run while (sorted == false || alldiff == false)
	do {
		sorted = true;
		alldiff = true;
		//as stated in main - prompt user to enter values for array
		for (int i = 0; i < size; i++) {
			cin >> arr[i];
		}
		sorted = Sorted(arr, size);
		alldiff = AllDiff(arr, size);

		if (sorted == false || alldiff == false) {
			cout << "ERROR" << endl;
		}
	} while (sorted == false || alldiff == false);

}
int Binarysearch(int arrbs[], const int size, int userint) {
	int left = 0;
	int right = size - 1;
	int mid = 0; //the middle element we will need in loop below 
	//this loop will run as long as the left index is less than right
	while (left <= right) { 
		//Classic kmath: X+Y/2
		mid = (left + right) / 2; 
		//look at one side of the array
		if (arrbs[mid] < userint) {
			left = mid + 1;
		}
		//will look at other side of array
		else if (arrbs[mid] > userint) { 
			right = mid - 1;
		}
		else { 
		   left = right + 1;
		}
	}
	//if the number is found at index of mid
	if (arrbs[mid] == userint) { 
		return mid;
	}
	else {
		return -1;
	}
}
