#include<iostream>
using namespace std;

bool Sorted(int arrsort[], const int size);
void fillArray(int arr[], const int size);
void printArray(int arrp[], int size);
void mergedarray(int arr1[], int arr2[], int arr3[], int mer[], int size1, int merge);


int main() {

	int A[10] = { 0 };
	int B[10] = { 0 };
	int C[10] = { 0 };
    int M[30] = { 0 };
	cout << "enter values for the first vector:" << endl;
	fillArray(A, 10);
	cout << "enter values for the second vector:" << endl;
	fillArray(B, 10);
	cout << "enter values for the third vector:" << endl;
	fillArray(C, 10);
	cout << "merged vector is:" << endl;
    mergedarray(A, B, C, M, 10, 30);
    printArray(M, 30);
}


//stepping stone function - sort in descending order
bool Sorted(int arrsort[], const int size) {
	for (int i = 0; i < size - 1; i++) {
		if (arrsort[i] < arrsort[i + 1]) {
			return false;
		}
	}
	return true;
}
void fillArray(int arr[], const int size) {
	bool sorted;
	bool positive;
	int dig;
	//this do loop will run while (sorted == false || alldiff == false)
	do {
		sorted = true;
		positive = true;
		//as stated in main - prompt user to enter values for array
		for (int i = 0; i < size; i++) {
			cin >> dig;

			if (dig != 0) {
				arr[i] = dig;
				if (dig < 0) {
					positive = false;
				}
			}
			else {
				break;
			}
		}
		if (positive == false) {
			cout << "ERROR" << endl;
			continue;
		}
		sorted = Sorted(arr, 10);
		if (sorted == false || positive == false) {
			cout << "ERROR" << endl;
		}
	} while (sorted == false || positive == false);

}
void mergedarray(int arr1[], int arr2[], int arr3[], int mer[], int size1, int merge) {
        int i = 0, j = 0, k = 0, l = 0;
        while (i < size1 && j < size1 && k < merge) {
            if (arr1[i] >= arr2[j] && arr1[i] >= arr3[k]) {
                mer[l] = arr1[i++];
            }
            else if (arr2[j] >= arr1[i] && arr2[j] >= arr3[k]) {
                mer[l] = arr2[j++];
            }
            else if (arr3[k] >= arr1[i] && arr3[k] >= arr2[j]) {
                mer[l] = arr3[k++];
            }
            else {
                break;
            }
            l++;
        }

        if (i < size1 && j < size1) {
            while (i < size1 && j < size1) {
                if (arr1[i] > arr2[j]) {
                    mer[l] = arr1[i++];
                }
                else {
                    mer[l] = arr2[j++];
                }
                l++;
            }
            while (i < size1) {
                mer[l++] = arr1[i++];
            }
            while (j < size1) {
                mer[l++] = arr2[j++];
            }
        }

        if (j < size1 && k < merge) {
            while (j < size1 && k < merge) {
                if (arr2[j] > arr3[k]) {
                    mer[l] = arr2[j++];
                }
                else {
                    mer[l] = arr3[k++];
                }
                l++;
            }
            while (j < size1) {
                mer[l++] = arr2[j++];
            }
            while (k < merge) {
                mer[l++] = arr3[k++];
            }
        }

        if (i < size1 && k < merge) {
            while (i < size1 && k < merge) {
                if (arr1[i] > arr3[k]) {
                    mer[l] = arr1[i++];
                }
                else {
                    mer[l] = arr3[k++];
                }
                l++;
            }
            while (i < size1) {
                mer[l++] = arr1[i++];
            }
            while (k < merge) {
                mer[l++] = arr3[k++];
            }
        }
    }
void printArray(int arrp[], int size) {
	for (int i = 0; i < size; i++) {
		if (arrp[i] != 0) { 
			cout << arrp[i] << " ";
		}
	}
}

