#include<iostream>
using namespace std;

void printAll(int* classrooms, int size);
void newClass(int* roomList, int& size, int newRoom);
void insertSort(int* classes, int size, int newClass);
void delClass(int* roomList, int& size, int delRoom);
int* searchClass(int* classList, int size, int roomSearch);
void printCode(int* classList, int size, int classCode);


int main() {

	int database[50];
	int classCounter = 0;
	int userinput;
	int classInput;
	int codeInput;
	int* pDatabase = database, * classAddress;

	enum ACTION { ADD, DELETE, SEARCH, CODE_PRINT, ALL_PRINT }; 

	cout << "Enter 0 to add a new classroom." << endl;
	cout << "Enter 1 to delete a hybrid classroom." << endl;
	cout << "Enter 2 to search for a specific classroom." << endl;
	cout << "Enter 3 to print all the classsrooms for a specific Machon." << endl;
	cout << "Enter 4 to print all the hybrid classrooms." << endl;
	cout << "Enter 5 to exit." << endl;

	cout << "Enter your choice:" << endl;
	cin >> userinput;
	//now checking if user entered a valid option
	while (userinput != 5) { 
		if ((userinput > 4) || (userinput < 0)) { 
			cout << "ERROR" << endl;
			cin >> userinput;
			continue; 
		}
		switch (userinput) {

		case ADD: //case 0
			cout << "Enter the code of the classroom to add:" << endl;
			cin >> classInput;
			if ((classInput / 1000) % 11) { 
				cout << "ERROR" << endl;
				cin >> classInput;
				break;
			}
			else {
				newClass(pDatabase, classCounter, classInput); //sending array and new element to be added to the array
				printAll(pDatabase, classCounter); //printing all the current elements in the database
				break;
			}

		case DELETE: //case 1
			cout << "Enter the code of the classroom to delete:" << endl;
			cin >> classInput;
			if ((classInput / 1000) % 11) { 
				cout << "ERROR" << endl;
				cin >> classInput;
				break; 
			}
			else {
				delClass(pDatabase, classCounter, classInput);
				printAll(pDatabase, classCounter); 
				break;
			}

		case SEARCH: //case 2 
			cout << "Enter the code of the classroom to search for:" << endl;
			cin >> classInput;

			classAddress = searchClass(pDatabase, classCounter, classInput); //sending the class number to see if it's in the database and storing the address if found
			if (classAddress == NULL) { //if it wasn't found will return a null value
				cout << "Not found" << endl;
			}
			else { 
				cout << "Found" << endl;
			}
			break;

		case CODE_PRINT: //case 3
			cout << "Enter the code of the Machon:" << endl;
			cin >> codeInput;

			if ((codeInput % 11) || (codeInput >= 100)) { 
				cout << "ERROR" << endl;
				cin >> codeInput;
				printCode(pDatabase, classCounter, codeInput);
				cout << endl;
				break;
			}
			else { 
				printCode(pDatabase, classCounter, codeInput);
				cout << endl;
				break;
			}

		case ALL_PRINT: //case  4 
			printAll(pDatabase, classCounter);
			break;
		}
		cout << "Enter your next choice:" << endl;
		cin >> userinput;
	}

	return 0;
}

void printAll(int* classrooms, int size) {

	for (int* p = classrooms; p < (classrooms + size); p++) { 
		cout << *p << " ";
	}
	cout << endl;
}

void newClass(int* roomList, int& size, int newRoom) {

	// If no elements were added to the array yet, set the new element to the first spot of the array
	if (size == 0) {
		*roomList = newRoom;
		size++; // Increase size by 1; it's adding to the counter that was sent as a parameter to gauge the current size of the array
	}
	// If there is only 1 element in the array, compare the values to see which one goes first
	else if (size == 1) {
		// If the new element is greater, add it to the next open spot
		if (newRoom > *roomList) {
			*(roomList + 1) = newRoom;
			size++;
		}
		// If the new element is less than the current element, swap them
		else if (newRoom < *roomList) {
			int temp = *roomList;
			*roomList = newRoom;
			*(roomList + 1) = temp;
			size++;
		} // If the new element is equal to the current element, it won't do anything
	}
	else { // If there are a number of elements in the array already 
		bool exists = false; // Flag to check if the new elements exist in the array
		for (int* p = roomList; p < (roomList + size); p++) {
			// If the element exists, set the flag to true and leave the loop
			if (*p == newRoom) {
				exists = true;
				break;
			}
		}
		// If the element is not in the array, add the new element using the insert sort method
		if (exists == false) {
			insertSort(roomList, size, newRoom);
			size++;
		}
	}
}

// Function to perform insertion sort
void insertSort(int* classes, int size, int newClass) {
	int sizeBound = size - 1;
	while ((*(classes + sizeBound) > newClass) && (sizeBound >= 0)) {
		*(classes + (sizeBound + 1)) = *(classes + sizeBound); // Move elements to the right
		sizeBound--; // Reduce how far we're checking in the array
	}
	*(classes + (sizeBound + 1)) = newClass; // Add the element to the correct spot; made room for it in the loop, or it will go at the end because it is greater than the last element 
}

// Function to delete a class from the list
void delClass(int* roomList, int& size, int delRoom) {
	for (int* p = roomList; p < (roomList + size); p++) {
		// Will now go through all the elements in the array to find the element to delete
		if (*p == delRoom) {
			for (int* q = p; q < (p + (size - 1)); q++) {
				// Move all elements to the left because we got rid of one of the elements
				*q = *(q + 1);
			}
			size--; // Decrease the size of the array since the element was deleted
			break; // No need to continue; found the element
		}
	}
}

// Function to search for a class in the list
int* searchClass(int* classList, int size, int roomSearch) {
	int* address = NULL;
	int left = 0, right = (size - 1); // Will use binary search method since the array is sorted

	while (left <= right) {
		int middle = (left + right) / 2;

		if (*(classList + middle) == roomSearch) {
			// If element is found, set the location to variable address and return it, leaving the function
			address = (classList + middle);
			return address;
		}
		if (*(classList + middle) < roomSearch) {
			// Element not in the left half of the array
			left = (middle + 1);
		}
		if (*(classList + middle) > roomSearch) {
			// Element not in the right half of the array
			right = (middle - 1);
		}
	}
	return address; // It will return null because there were no cases when the element was found which would have resulted in the program ending
}

// Function to print class codes matching a certain code
void printCode(int* classList, int size, int classCode) {
	for (int* p = classList; p < (classList + size); p++) {
		// If the first 2 digits of the class number are equal to the class code, then print the class
		if (((*p) / 1000) == classCode) {
			cout << *p << " ";
		}
	}
}

