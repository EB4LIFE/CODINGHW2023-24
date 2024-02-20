#include <iostream>
using namespace std;
//function for this question we use intlilize below
void printAll(int* classrooms, int size);
//prints all classrooms in the list
int* newClass(int* roomList, int& size, int newRoom);
//add new classrooms to list
void insertSort(int* classes, int size, int newClass);
//add new class (classroom) to sorted classroom
int* delClass(int* roomList, int& size, int delRoom);
//deletes classrom
int* searchClass(int* classList, int size, int roomSearch);
//searches for the classrooom and we use a pointer to point to its location
void printCode(int* classList, int size, int classCode);
//code for the particular classroom


int main() {

	int* database = NULL; 
	//this will be the pointer used to point to the dynamic array with the classrooms
	int classCounter = 0;
	//counters for numbers of classrooms in array database
	int userinput;
	//input for enum menu selection
	int classInput;
	//input for class code
	int codeInput;
	//input for special machon lev code
	int* classAddress;
	int* databasereturn;

	enum ACTION { ADD, DELETE, SEARCH, CODE_PRINT, ALL_PRINT };

	cout << "Enter 0 to add a new classroom." << endl;
	cout << "Enter 1 to delete a hybrid classroom." << endl;
	cout << "Enter 2 to search for a specific classroom." << endl;
	cout << "Enter 3 to print all the classrooms for a specific Machon." << endl;
	cout << "Enter 4 to print all the hybrid classrooms." << endl;
	cout << "Enter 5 to exit." << endl;

	cout << "Enter your choice:" << endl;
	cin >> userinput;

	while (userinput != 5) { 

		if ((userinput > 4) || (userinput < 0)) { 
			//now checking if user entered a valid option
			cout << "ERROR" << endl;
			cin >> userinput;
			continue;
		}
		switch (userinput) {

		case ADD: //case 0 and add new classroom
			cout << "Enter the code of the classroom to add:" << endl;
			cin >> classInput;

			if (((classInput / 1000) % 11) || (classInput < 10000) || (classInput > 99999)) { 
				//if user entered class that has an invalid class code or that's not 5 digits
				cout << "ERROR" << endl;
				cin >> classInput;
				break;
			}
			else {
				databasereturn = newClass(database, classCounter, classInput); 
				//added to the function
				if (databasereturn != NULL) { 
					//if function returned null it means the element existed so the array wasn't changed
					database = databasereturn;
					//set pointer database to point to the new dynamic array created in function
				}
				printAll(database, classCounter); 
				//sending the pointer to the dynamic array and the current size to be printed
				break;
			}

		case DELETE: //case 1 and delete classroom
			cout << "Enter the code of the classroom to delete:" << endl;
			cin >> classInput;

			if (((classInput / 1000) % 11) || (classInput < 10000) || (classInput > 99999)) { //if user entered class that has an invalid class code or that's not 5 digits
				cout << "ERROR" << endl;
				cin >> classInput;
				break; 
			}
			else {
				databasereturn = delClass(database, classCounter, classInput); 
				
				if (databasereturn != NULL) { 
					database = databasereturn; 
				}
				printAll(database, classCounter); 
				break; 
			}

		case SEARCH: //case 2 - search classroom
			cout << "Enter the code of the classroom to search for:" << endl;
			cin >> classInput;

			if ((classInput < 10000) || (classInput > 99999)) { 
				cout << "ERROR" << endl;
				cin >> userinput;
				break; 
			}
			else {
				classAddress = searchClass(database, classCounter, classInput);
				//sending the class number to see if it's in the database and storing the address if found
				if (classAddress == NULL) { 
					cout << "Not found" << endl;
				}
				else { 
					cout << "Found" << endl;
				}
				break;
			}

		case CODE_PRINT: //case 3 and print all classrooms for spec mehcon
			cout << "Enter the code of the Machon:" << endl;
			cin >> codeInput;

			if ((codeInput > 99) || ((codeInput % 11) != 0)) { 
				cout << "ERROR" << endl;
				cin >> codeInput;
				printCode(database, classCounter, codeInput);
				cout << endl;
				break;
			}
			else {
				printCode(database, classCounter, codeInput); 
				cout << endl;
				break;
			}

		case ALL_PRINT: //case 4 - new class
			printAll(database, classCounter); 
			break;
		}
		cout << "Enter your next choice:" << endl;
		cin >> userinput;
	}

	return 0;
}

int* newClass(int* roomList, int& size, int newRoom) {

	if (size == 0) { 
		//no elements in the database yet
		roomList = new int[1]; 
		//create a dynamic array of size 1 that roomList will point to
		roomList[0] = newRoom; 
		size++;
		//increase size because just added an element
		return roomList; 
		//returning address of new dynamic array
	}
	else if (size == 1) { 
		int* tempList = new int[2]; 

		if (newRoom > roomList[0]) { 
			tempList[0] = roomList[0]; 
			tempList[1] = newRoom; 

			//delete[] roomList; //delete the array that roomList was currently pointing to
			roomList = tempList; 
			//set roomList to point to the new dynamic array that tempList points to

			size++;
			return roomList; 
		}
		else if (newRoom < roomList[0]) { 
			tempList[0] = newRoom; 
			tempList[1] = roomList[0]; 

			//delete[] roomList; //delete the array that roomList was currently pointing to
			roomList = tempList; 

			size++; 
			return roomList; 
		}
	}
	else { 
		bool exists = false; 

		for (int i = 0; i < size; i++) {
			if (roomList[i] == newRoom) { 
				exists = true;
				break;
			}
		}
		if (exists == false) { 
			int* tempList = new int[size + 1]; 

			for (int j = 0; j < size; j++) {
				tempList[j] = roomList[j]; 
			}
			//delete[] roomList; //delete the array that roomList was currently pointing to
			roomList = tempList; 
			insertSort(roomList, size + 1, newRoom);
			size++; 
			return roomList; 
		}
	}
	return NULL; //this means the element already exists so no new address to return
}
// Function to perform insertion sort
void insertSort(int* classes, int size, int newClass) {
	int sizeBound = size - 2;
	while ((classes[sizeBound] > newClass) && (sizeBound >= 0)) {
		classes[sizeBound + 1] = classes[sizeBound]; 
		//move elements to the right
		sizeBound--; 
		//reducing how far we are checking in the array
	}
	classes[sizeBound + 1] = newClass;
	//add the element to the correct spot, made room for it in the loop, or it will go at the end because it is greater than the last element
}

void printAll(int* classrooms, int size) {

	for (int i = 0; i < size; i++) {
		cout << classrooms[i] << " "; //printing each element of the array with a space after
	}
	cout << endl;
}

int* delClass(int* roomList, int& size, int delRoom) {
	for (int i = 0; i < size; i++) { //looping to find the element in the array so can delete it

		if (roomList[i] == delRoom) { 
			int* tempList = new int[size - 1];
			int j; 
			for (j = 0; j < i; j++) { 
				tempList[j] = roomList[j]; 
			}
			for (; j < (size - 1); j++) { 
				tempList[j] = roomList[j + 1]; 
			}
			//delete[] roomList; //delete the array that roomList was currently pointing to
			roomList = tempList; 
			//set roomList to point to the new dynamic array that tempList points to
			size--; 
			//decreasing size by 1 because element was deleted
			return roomList; 
			//no need to continue, we found the element
		}
	}
	return NULL; 
	//this means the element already exists so no new address to return
}
// Function to search for a class in the list
int* searchClass(int* classList, int size, int roomSearch) { 
	//binary search method
	int* address = NULL;
	int left = 0;
	int right = (size - 1);

	while (left <= right) {
		int middle = (left + right) / 2;

		if (classList[middle] == roomSearch) { 
			//if element is found set the location of the element to variable address and return it, leaving function
			address = &classList[middle];
			return address;
		}
		if (classList[middle] < roomSearch) { 
			//Element not in left half of array
			left = (middle + 1);
		}
		if (classList[middle] > roomSearch) { 
			//Element not in right half of array
			right = (middle - 1);
		}
	}
	return address; 
	//It will return null because left loop without having found item
}

void printCode(int* classList, int size, int classCode) {

	for (int i = 0; i < size; i++) {
		if ((classList[i] / 1000) == classCode) { 
			// If the first 2 digits of the class number are equal to the class code, then print the class
			cout << classList[i] << " ";
		}
	}
}
