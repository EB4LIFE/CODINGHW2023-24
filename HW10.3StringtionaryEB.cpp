#include<iostream>
#include<cstring>
#include<string>
using namespace std;
#pragma warning (disable:4996)

void newStr(char**& dictionary, int& size, char* newWord);
void selectionSort(char** words);
void swapWords(char*& word1, char*& word2);
void printAll(char** dictionary, int size);
void delStr(char**& dictionary, int& size, char* delWord);
char** searchStr(char** dictionary, int size, char* wordSearch);
void printChar(char** dictionary, int size, char letter);


int main() {
	//pointer to a char set to null
	char** lexicon = NULL;
	//pointer to char to store input for words
	char* wInput;
	//pointer to a pointer to char
	char*** wAddress;
	//pointer temp variable
	char* temp;
	//char pointer for single character
    char* letter;
	//int size for current size of lexicon currently at size at 0
	int wSize = 0;
	//used to store user input for menu choices
	int userint;
	//length of strings
	int len;
	//prompts user to pick a choice from the menu
	cout << "Enter 0-5:" << endl;
	cin >> userint;

	while (userint != 5) { 
		//if input is not between those choices then prints an error
		if ((userint > 4) || (userint < 0)) {
			cout << "ERROR" << endl;
			cin >> userint;
			continue; 
		}
		// If the user input is 0, this block handles adding a new word to the lexicon.
       // It prompts the user to enter a word, adds it to the lexicon, and then prints all words in the lexicon.
		else if (userint == 0) { 
			temp = new char[80];
			cout << "Enter the word:" << endl;
			cin.ignore(); 
			cin.getline(temp, 80); 

			len = strlen(temp) + 1;
			wInput = new char[len];
			strncpy(wInput, temp, len); 
			delete[] temp; 

			newStr(lexicon, wSize, wInput);
			printAll(lexicon, wSize); 

			delete[] wInput;
		}
		// If the user input is 1, this block handles deleting a word from the lexicon.
        // It prompts the user to enter a word to delete, 
        // removes it from the lexicon, and then prints all words in the lexicon.
		else if (userint == 1) { 
			temp = new char[80]; 
			cout << "Enter the word to delete:" << endl;
			cin.ignore(); 
			cin.getline(temp, 80); 

			len = strlen(temp) + 1;
			wInput = new char[len]; 
			strncpy(wInput, temp, len); 
			delete[] temp; 

			delStr(lexicon, wSize, wInput); 
			printAll(lexicon, wSize); 

			delete[] wInput; 
		}
		// If the user input is 2, this block handles searching for a word in the lexicon.
       // It prompts the user to enter a word to search for, searches for it in the lexicon,
       // and prints whether the word is found or not.
		else if (userint == 2) { 
			temp = new char[80]; 
			cout << "Enter the word to search for:" << endl;
			cin.ignore(); 
			cin.getline(temp, 80);

			len = strlen(temp) + 1;
			wInput = new char[len];
			strncpy(wInput, temp, len); 
			delete[] temp;

			wAddress = searchStr(lexicon, wSize, wInput); 

			if (wAddress == NULL) { 
				cout << "Not Found" << endl;
			}
			else { 
				cout << "Found" << endl;
			}
			delete[] wInput; 
		}
		// If the user input is 3, this block handles printing all words in the lexicon that start with a specific character.
        // It prompts the user to enter a character, then prints all words that start with that character.
		else if (userint == 3) { 
			cout << "Enter the char:" << endl;
			cin >> letter;

			printChar(lexicon, wSize, letter); 
		}
		// If the user input is 4, this block handles printing all words in the lexicon.
        // It simply prints all the words stored in the lexicon.
		else if (userint == 4) { 

			printAll(lexicon, wSize); 
		}

		cout << "Enter 0-5:" << endl; 
		cin >> userint;
	}
	//After the loop, this part of the code deallocates memory allocated dynamically 
	// for lexicon and its elements using delete[], 
	// then returns 0 to indicate successful program execution.
	for (int i = 0; i < wSize; i++) { 
		delete[] lexicon[i];
	}
	delete[] lexicon; 


	return 0;
}
/*
* dictionary: a reference to a pointer to a pointer to char, representing the lexicon.
size: a reference to an integer representing the current size of the lexicon.
newWord: a pointer to char representing the new word to be added to the lexicon.
*/
void newStr(char**& dictionary, int& size, char* newWord) {
	int wCmp;
	int wLen;
	wLen = strlen(newWord) + 1; 
	//If the size of the lexicon is 0, indicating it's empty>>
	if (size == 0) { 
		// In this block, memory is allocated for the lexicon (dictionary) with space for 2 pointers.
		// The new word is copied into the lexicon, and the size is updated accordingly.
		dictionary = new char* [2]; 
		dictionary[0] = new char[wLen]; 
		strcpy(dictionary[0], newWord); 
		dictionary[1] = NULL;

		size += 2; 
	}
	//If the size of the lexicon is 2, indicating it contains one word
	else if (size == 2) { 
		char** temp = new char* [3]; 
		wCmp = strcmp(dictionary[0], newWord); 
		//If the comparison between the existing word and the new word indicates 
        // the new word comes after the existing word
		if (wordCmp < 0) { 

			temp[0] = new char[(strlen(dictionary[0])) + 1];
			strcpy(temp[0], dictionary[0]); 

			temp[1] = new char[wLen]; 
			strcpy(temp[1], newWord); 

			temp[2] = NULL; 

			for (int i = 0; i < 2; i++) {
				delete[] dictionary[i];
			}
			delete[] dictionary; 
			dictionary = temp; 
			size++; 
		}
		//If the comparison indicates the new word comes before the existing word
		else if (wordCmp > 0) { 

			temp[0] = new char[wLen]; 
			strcpy(temp[0], newWord);

			temp[1] = new char[((strlen(dictionary[0]) + 1))]; 
			strcpy(temp[1], dictionary[0]); 

			temp[2] = NULL;

			for (int i = 0; i < 2; i++) {
				delete[] dictionary[i]; 
			}
			delete[] dictionary; 
			dictionary = temp; 
			size++; 
		}
	}
	else { 
		bool exists = false; 
		//loop will check if words is already there in lexicon array
		for (int i = 0; i < size - 1; i++) { 
			if (!strcmp(newWord, dictionary[i])) { 
				exists = true;
				break;
			}
		}
		//words does not exist in lexicon
		if (exists == false) { 
			char** temp = new char* [size + 1]; 
			//when the new word does not exist in the lexicon, 
			// adding it to the lexicon, resizing it if necessary, and sorting it alphabetically.
			for (int i = 0; i < size - 1; i++) {
				temp[i] = new char[((strlen(dictionary[i]) + 1))]; 
				strcpy(temp[i], dictionary[i]); 
			}
			temp[size - 1] = new char[wLen];
			strcpy(temp[size - 1], newWord);
			temp[size] = NULL; 

			for (int j = 0; j < size; j++) {
				delete[] dictionary[j]; 
			}
			delete[] dictionary;
			dictionary = temp; 

			selectionSort(dictionary); 
			size++;
		}
	}
}
//This function is named selectionSort and takes a pointer to a pointer to char as its parameter, 
// representing an array of strings.
void selectionSort(char** words) {
	//loop will run until it encounters a null value 
	for (; *words != NULL; words++) {
    //This nested loop starts from the next element after the current word (words) and continues until it encounters a NULL pointer.
    //It iterates through the remaining elements of the array to compare each word with the current word (*words).
		for (char** p = words + 1; *p != NULL; p++) { 
			//comparing words and p pointers
			//f the current word comes after the word pointed to by p in lexicographical order 
			// (a value greater than 0)
			// the condition evaluates to true.
			if ((strcmp(*words, *p)) > 0) {
				//if true we swap the words/position using function below 
				swapWords(*words, *p); 
			}
		}
	}
}
void swapWords(char*& word1, char*& word2) {
	//classic swap with a temp
	char* temp = word1;
	word1 = word2;
	word2 = temp;
}

void printAll(char** dictionary, int size) {
	//classic print with char and pointer
	for (int i = 0; i < size - 1; i++) { 
		cout << dictionary[i] << " ";
	}
	cout << endl;
}
void delStr(char**& dictionary, int& size, char* delWord) {
	/*
	* dictionary: a reference to a pointer to a pointer to char, representing the lexicon.
	size: a reference to an integer representing the current size of the lexicon.
	delWord: a pointer to char representing the word to be deleted from the lexicon.
	*/
	//will go thru the loop of lexicon not inlcuding null
	for (int i = 0; i < size - 1; i++) {
		//This condition checks if the ith word in the lexicon matches the delWord using strcmp. 
		// If the words match, the condition evaluates to true.
		if (!(strcmp(dictionary[i], delWord))) { 
			//If a match is found, a temporary list tempList is created
			//With a size one less than the current size of the lexicon.
			char** temp = new char* [size - 1]; 
			//loop below will copy words before the matched words for OG lexcion array into temp
			int j;
			for (j = 0; j < i; j++) { 
				temp[j] = new char[strlen(dictionary[j]) + 1]; 
				strcpy(temp[j], dictionary[j]); 
			}
			//loop will coby words after mathched word from og lexicon to temp then making adjusment 
			// to j to start from where match was found
			for (; j < size - 2; j++) { 
				temp[j] = new char[strlen(dictionary[j + 1]) + 1];
				strcpy(temp[j], dictionary[j + 1]); 
			}
			//we set it null so this is end of the list
			temp[size - 2] = NULL;
			//he original lexicon is deallocated, and the pointer is reassigned to point to temp.
			for (int k = 0; k < size; k++) {
				delete[] dictionary[k]; 
			}
			delete[] dictionary; 
			dictionary = temp;

			size--; 
		}
	}
}
//will search for word using binary search method that we talked about 
char** searchStr(char** dictionary, int size, char* wordSearch) { 
	int L = 0;
	int R = size - 2;

	while (L <= R) {
		int middle = (L + R) / 2;
		//The strcmp() function in C++ returns an integer value calculated according to the first mismatched character among the two strings.
		//if strcmp returns 0 (so need ! to make it true) then the current word is the word
		if (!(strcmp(dictionary[middle], wordSearch))) { 
			return &dictionary[middle]; //we found the word, so return the address for it and we stop function		
		}
		//the word is in the second half of the list, it comes after the current word alphabetically
		if ((strcmp(dictionary[middle], wordSearch)) < 0) { 
			L = (middle + 1);
		}
		//the word is in the first half of the list, it comes before the current word alphabetically
		if ((strcmp(dictionary[middle], wordSearch)) > 0) {
			R = (middle - 1);
		}
	}
	return NULL; 
	//word wasn't found, so return NULL
}

void printChar(char** dictionary, int size, char letter) {
	//normal print array except with char and pointers
	for (int i = 0; i < size - 1; i++) { 

		if (dictionary[i][0] == letter) { 
			cout << dictionary[i] << " ";
		}
	}
}





