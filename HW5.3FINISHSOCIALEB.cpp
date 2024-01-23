#include <iostream>
using namespace std;

//Function that is passed a number and returns the sum of the digits
int Digitsum(int ID) {
  int sum =0; //to add sum of digits into this variable then return value of this as will see below
  int dig;

  for(int i = 0; i < 8; i++) {
    //the last digit
    if(i != 7) {
      dig = ID % 10; 
      //takes off another digit and does process of loop again
      ID /= 10; 
    }
      //no more need to do another step
    else {
      dig = ID % 10; 
    }
    //even numbers
    if (i % 2 == 0) { 
			dig *= 2; 
		}
    //odd numbers
		else { 
			dig *= 1;
		}
    //if we end up with a two digit number 
		if ((dig / 10) != 0) { 
			dig = (dig % 10) + 1; 
		}
		sum += dig; 
}
return sum;
}
//Function that is passed an id number and returns its correct check-sum.
int Checksum(int weight, int inID) {
  int FullID;
  int checksum;
  int one;

  one = weight % 10;
  checksum = 10 - one;
  FullID = (inID * 10) + checksum; 
 
  return FullID;
  
}



//Application of function in main 
int main () {
  
    int USERID; 
    int sumid;
    int fullid; 
    cout << "enter your ID:" << endl;
    cin >> USERID;
    sumid = Digitsum(USERID);
    fullid = Checksum(sumid,
    cout << "your full ID is:"
    
  
  return 0;
}
