#include<iostream>
using namespace std;
//functions that will be used in this example - these two are cimiliar to Fillarray and printArray
void fillMatrix(int matrix[][10], int size);
void printMatrix(const int matrix[][10], int size);
//function for needed trianles
void insertionSort(int arr[], int size);



int main() {
	const int matrixsize = 10;
	const int trianglesize = 45;
	int matrix[matrixsize][matrixsize];
	int LT[trianglesize];
	int RT[trianglesize];
	int triIndex;

	cout << "Enter the values:" << endl;
	fillMatrix(matrix, matrixsize);

	cout << "Before sorted:" << endl;
	printMatrix(matrix, matrixsize);
	//this will be for moving the bottom left side of the matrix to a regular array to be sorted
	//since we are ignoring the diagnal line we are starting at row index 1 instead of 0
	//how far into each column we go corresponds to the row number
	triIndex = 0; 
	for (int i = 1; i < matrixsize; i++) { 
		for (int j = 0; j < i; j++) { 
			LT[triIndex] = matrix[i][j];
			triIndex++;
		}
	}
	//this will be for moving the top right side of the matrix to a regular array to be sorted
	//since we are ignoring the diagnal, we go up until the last row
	//where we start in each column corresponds 1 + the row number
	triIndex = 0;
	for (int i = 0; i < (matrixsize)-1; i++) { 
		for (int j = (i + 1); j < matrixsize; j++) { 
			RT[triIndex] = matrix[i][j];
			triIndex++;
		}
	}
	//sending the left array to be sorted
	insertionSort(LT, trianglesize); 
	//sending the right array to be sorted
	insertionSort(RT, trianglesize); 
	//now copying the left sorted array back to the bottom left side of the matrix
	//now putting the array elements back in their proper places
	triIndex = 0; 
	for (int i = 1; i < matrixsize; i++) {
		for (int j = 0; j < i; j++) {
			matrix[i][j] = LT[triIndex]; 
			triIndex++;
		}
	}
	//now copying the right sorted array back to the top right side of the matrix
	 //now putting the array elements back in their proper places
	triIndex = 0; 
	for (int i = 0; i < (matrixsize - 1); i++) {
		for (int j = (i + 1); j < matrixsize; j++) {
			matrix[i][j] = RT[triIndex];
			triIndex++;
		}
	}
	cout << "Sorted matrix:" << endl;
	printMatrix(matrix, matrixsize); 

	return 0;

}

void fillMatrix(int matrix[][10], int size) {
	bool Error;
	int user;
	/*WHILE THERE IS AN ERROR(this case means that input isn't positive DO the loop again first for loop to go thru array and another for the 2nd dimension of array, if input
	is more than zero (pos) then put user value into matrix array. if not - ERROR output and break. Then DO loop will restart*/
	do { 
		Error = false;		
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
			    cin >> user;
				if (user > 0) {
					matrix[i][j] = user;
				}
				else {
					Error = true;
					cout << "ERROR" << endl;
					break;
				}
			}
			if (Error == true) {
				break;
			}
		}
	} while (Error == true);
}
//classic print ARRAY execept double for loop for 2d matrix array
void printMatrix(const int matrix[][10], int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << matrix[i][j] << '\t';
		}
		cout << endl;
	}
}
void insertionSort(int arr[], int size) {
	int sort;
	int i;
	// traverse backwards to find sort position of sort[i]
	// shifting values along the way
	// stop if beginning of list or non-larger number is reached
		for (sort = 1; sort < size; sort++) { //this loop controls which 2 elements are currently being compared (that's why start at 1 and not 0)
		int temp = arr[sort]; //this element is what will be compared to all elements below it
		//if the current element (sort) is less than the element before it (i-1), then switch them
		for (i = sort; i > 0 && temp < arr[i - 1]; i--) {
			arr[i] = arr[i - 1]; // shift right
		}
		//putting the element we were sorting back into the array
		arr[i] = temp; 
	}
}

	
