#include<iostream>
#include<cstring>
#include<string>
using namespace std;
#pragma warning (disable:4996)


void Crypto(char* word);
//This function will encrypt the the lowercase letters of the given word with the azby encrytpion counterpart


int main() {

	char String[80];
	cout << "Enter a string:" << endl;
	//the >> operator reads until the space or enter, but just until, That means the next input will be the blank  character.
	//so we use a different version to avoid this problem 
	cin.getline(String, 80);
	//once string is finlizaed we will call  the crypto function and encrypt the given word
	Crypto(String);
	//Now it is encyrpted we print the new word
	cout << "After crypto:" << endl;
	cout << String << endl;

	return 0;
}

//intilization of cyrpto 
void Crypto(char* word) {
	//array with all lowercase 
	char rule[] = "abcdefghijklmnopqrstuvwxyz";
	//int for index of each letter in array 
	int letindex;
	//char pointers
	char* address;
	char* Aindex = rule;
	char** p = word;

	while (*p) {

		//The strchr() function returns a pointer to the first occurrence of c that is converted to a character in string.
		//we  are looking to see what letter we are up to if needs to be encrypted meaning if it is lwoercase
		address = strchr(rule, *p);
		//if above strchr function returned an address for letter from rule array then....
		if (address) {
			letindex = address - Aindex;
			//first we grabbed the index of letter found in rule array 
			*p = *(aindex + +25 - letindex);
			//then we set the letter the pointer P is pointing to in word to its azby encryption
			p++;
			//then we next to the next letter 
		}
		else {
			p++; 
			//As the current char index we are up to is not lowercase so we must move to the next one 
		}
	}
}
