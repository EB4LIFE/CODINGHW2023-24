#include<iostream>
using namespace std;
//asked for in the question 
const int words = 10;
const int letters = 5;
//needed functions
void fillMatrix(char matrix[][letters], int rows);
void bubbleSort(char words[][letters], int rows);
bool compareWords(char w1[], char w2[], int wLen);
void swapWords(char w1[], char w2[], int wLen);
void printMatrix(const char matrix[][letters], int rows);

int main() {

	char Wlist[words][letters];

	cout << "enter 10 words:" << endl;
	fillMatrix(wordList, words); 
	bubbleSort(wordList, words); 
	cout << "after sorting:" << endl;
	printMatrix(wordList, words); 

	return 0;
}
void fillMatrix(char matrix[][letters], int rows) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < letters; j++) {
			cin >> matrix[i][j];
		}
	}
}
//will take compare words and swap words and sort them compltley into order
void bubbleSort(char words[][letters], int rows) {
	int sort; 
	int i;
	bool first;
	//starting with all rows, but after each iteration the last word will be in place so we can decrease the length that we are checking
	//send each word (rows from the matrix) and the word after it to check if they are in the right dictionary order
	//when the words are not in the right order --> we need to swap them
	for (sort = (rows - 1); sort > 0; sort--) { 
		for (i = 0; i < sort; i++) { 
			first = compareWords(words[i], words[i + 1], letters); 
			if (first == false) {
				swapWords(words[i + 1], words[i], letters); 
			}
		}
	}
}
//This will make words in dictionary order
bool compareWords(char w1[], char w2[], int wLen) {
	for (int i = 0; i < wLen; i++) {
		if (w1[i] < w2[i]) {
			return true;
		}
		else if (w1[i] > w2[i]) {
			return false;
		}
	}
	return true;
}
//classic swap witha temp variable execept in this case using for loop and words instead of number values
void swapWords(char w1[], char w2[], int wLen) {
	for (int i = 0; i < wLen; i++) {
		char temp = w1[i];
		w1[i] = w2[i];
		w2[i] = temp;
	}
}
//classic print ARRAY execept double for loop for 2d matrix array
void printMatrix(const char matrix[][letters], int rows) {
	for (int i = 0; i < rows; i++) {

		for (int j = 0; j < letters; j++) {
			cout << matrix[i][j];
		}
		cout << '\t';
	}
}
