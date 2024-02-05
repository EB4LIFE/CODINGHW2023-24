#include<iostream>
using namespace std;

bool Sorted(int arrsort[], const int size);
void fillArray(int arr[], const int size);
void printArray(int arrp[], int size);
void mergeArrays(int arr1[], int arr2[], int arr3[], int arrMerge[], int size1, int sizeMerge);


int main() {

	int A[10] = { 0 };
	int B[10] = { 0 };
	int C[10] = { 0 };
    int M[30] = { 0 };
	cout << "Enter values for the first vector:" << endl;
	fillArray(A, 10);
	cout << "Enter values for the second vector:" << endl;
	fillArray(B, 10);
	cout << "Enter values for the third vector:" << endl;
	fillArray(C, 10);
	cout << "Merged vector is:" << endl;
    mergeArrays(A, B, C, M, 10, 30);
    printArray(M, 30);
}


//stepping stone function - sort in descending order
bool Sorted(int arrsort[], const int size) {
	for (int i = 0; i < size - 1; i++) {
	    if(arrsort[i+1]==0) {
	        return true;
	    }
		if (arrsort[i] <= arrsort[i + 1]) {
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
		if (sorted == false) {
			cout << "ERROR" << endl;
		}
	} while (sorted == false || positive == false);

}
void mergeArrays(int arr1[], int arr2[], int arr3[], int arrMerge[], int size1, int sizeMerge){
        int i = 0, j = 0, k = 0, x = 0;

while (i < 10 && j < 10 && k < 10) {
    if (arr1[i] >= arr2[j] && arr1[i] >= arr3[k]) {
        arrMerge[x] = arr1[i++];
    }
    else if (arr2[j] >= arr1[i] && arr2[j] >= arr3[k]) {
        arrMerge[x] = arr2[j++];
    }
    else if (arr3[k] >= arr1[i] && arr3[k] >= arr2[j]) {
        arrMerge[x] = arr3[k++];
    }
    else {
        break;
    }
    x++;
}

if (i < 10 && j < 10) {
    while (i < 10 && j < 10) {
        if (arr1[i] > arr2[j]) {
            arrMerge[x] = arr1[i++];
        }
        else {
            arrMerge[x] = arr2[j++];
        }
        x++;
    }
    while (i < 10) {
        arrMerge[x++] = arr1[i++];
    }
    while (j < 10) {
        arrMerge[x++] = arr2[j++];
    }
}

if (j < 10 && k < 10) {
    while (j < 10 && k < 10) {
        if (arr2[j] > arr3[k]) {
            arrMerge[x] = arr2[j++];
        }
        else {
            arrMerge[x] = arr3[k++];
        }
        x++;
    }
    while (j < 10) {
        arrMerge[x++] = arr2[j++];
    }
    while (k < 10) {
        arrMerge[x++] = arr3[k++];
    }
}

if (i < 10 && k < 10) {
    while (i < 10 && k < 10) {
        if (arr1[i] > arr3[k]) {
            arrMerge[x] = arr1[i++];
        }
        else {
            arrMerge[x] = arr3[k++];
        }
        x++;
    }
    while (i < 10) {
        arrMerge[x++] = arr1[i++];
    }
    while (k < 10) {
        arrMerge[x++] = arr3[k++];
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
