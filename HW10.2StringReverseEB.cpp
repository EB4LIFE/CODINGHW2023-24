#include<iostream>
#include<cstring>
#include<string>
using namespace std;
#pragma warning (disable:4996)

/*
A string sentence is a string with sequences of characters (called words) of varying lengths. Words are separated by 1 or more spaces. 
The reverse of a string sentence is a string sentence in which all the words in the original string sentence are reversed. 
For example, if the word hello is in the original string sentence, then the word olleh will be in the reverse string sentence.
As an example, If the original string sentence was:
This is    a  silly88 sentence
Then the reverse string sentence is:
sihT si    a  88yllis ecnetnes
Note: digits and spaces are preserved in the reverse statement.
Write a function called reverse which receives 
as input a string sentence not greater than 80 characters and returns its reverse string sentence.
*/

void reverse(char*& words);
//This is the main fucntion for this answer as we will use this to reverse word in a given sentence
void reverseletters(char*& word, int L, int R);
//This is swap letters from a given string and will help in above function


int main() {
	//setting a char array that will be used for user inputed sentence to be reversed
	char* Sentence[80];
	//pointing to address of index 0 of array at first
	char* pointsen = Sentence;
	//prompt user to fill string array
	cout << "enter a string:" << endl;
	cin.getline(Sentence, 80);
	//once it is filled we call reverse function using the pointer variable we set up several lines above
	reverse(pointsen);
	//once reversed we print result
	cout << "After reverse: " << Sentence << endl;

	return 0;

}


//first we intilize the stepping stone function 
void reverseletters(char*& word, int L, int R) {
	//while condition is for once they cross each other stop the loop 
	while (L < R) {
		//now its is normal swap with char
		char temp = word[L];
		word[L] = word[R];
		word[R] = temp;

		L++;
		R--;
	}
}
//Now we intilize  the main reverse function of a sentence
void reverse(char*& words) {
	int Wlen;
	int j = 0;
	int k = 0;
	//the strlen function determines the length of string excluding the ending null character. 
    // The strlen() function returns the length of string
	Wlen = strlen(words) + 1;
	//as stated we get length of sentence and 1 added for null value
	char* temp = new char[Wlen];

	for (int i = 0; i < Wlen - 1; i++) {
		//copying over characters for old array to new array
		temp[i] = words[i];
	}
	temp[Wlen - 1] = ' ';
	//adds space at index before null

	for (; j < Wlen; j++) {
		if (temp[j] == ' ') {
			reverseletters(temp, k, (j - 1));

			while (j + 1 == ' ') {
				j++;
			}
			k = j + 1;
		}
	}
	for (int l = 0; m < Wlen - 1; l++) {
		words[l] = temp[m];
	}
	delete[] temp;
}



