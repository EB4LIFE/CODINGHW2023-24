#include <iostream>
#include <ctime>
using namespace std;

/*This program will produce 10 random numbers and then determine if they are in a sorted list or not*/

int main()  {
  
   int n;
   int n2;
	 bool  isSorted = true;
	
	srand(unsigned int(time));	
	n = rand() % 1000 + 1; 
	cout << n << " "; 

	for (int i = 0; i < 9; i++) { 
		n2 = rand() % 1000 + 1; 
		cout << n2 << " ";
		if (n2 < n) { 
			isSorted = false;
			break;
		}
		n = n2; 
	}
	if (isSorted == true) {  
		cout << endl << "sorted list";
	}
	else {
		cout << endl << "not sorted list";
	}
	return 0;
}

