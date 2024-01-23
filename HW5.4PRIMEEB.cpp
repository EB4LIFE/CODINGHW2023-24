#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//Checks to see if number is prime
bool isPrime(int pnum) {
    bool isprime;
    for(int i = 2; i < pnum; i++) {
        if (pnum % i == 0) { 
		isprime = false; 
		break;
		}
		else {
		isprime = true;
        }
    }
     return isprime;
}
//takes a positive whole number and returns the smallest prime number that is greater than or equal to the number passed.
int findPrime(int num) {
    int smallp;
	bool isprime;
	do { 
		isprime = isPrime(num);
		if (isprime == true) {
			smallp = num; 
		}
		else { 
			isprime = false;
			++num; 
		}
	} while (isprime == false); 
    
	return smallp; 
}
//USER INPUT
int main () {
int tablesize;
srand( (unsigned)time(NULL) ); 
int usernum;
cout << "Enter number of values:" << endl;
cin >> usernum;
//If the number is negative, the program randomly chooses a number from 10-100
if(usernum <0) {
usernum = (rand() % 91 + 10);
}
tablesize = findPrime(usernum); 
cout << "Table size: " << tablesize << endl;
}
