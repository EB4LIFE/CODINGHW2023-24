#include<iostream>
using namespace std;

//accepts a positive whole number and returns true if the number is perfect and false otherwise
bool perfect(int pernum) {
   int sum = 0; 
   bool IsPerfect;
  //Loop to check if numbers that are less than input are FACTORS of the input variable itself
  for(int i = 1; i < pernum; i++) {
    //If there are no remainders than they are facotors of input so we add to sum 
    if(pernum % i == 0) {
      sum+=i;
    }
  }
  //Once loops finishes we compare sum to pernum (input) to see if a prfect number or not
  if(sum == pernum) {
    IsPerfect = true;
  }
  else {
    IsPerfect = false;
  }
  return IsPerfect;
}

//accepts as input a positive whole number and prints out all the perfect numbers in numeric order (separated by a space) that is less than this number. 
void perfectprint(int num=500) {
  
  bool IsPerfect;

  for(int i = 1; i  < num; i++) {
    //calling function above to see if 'i' is perfect
    IsPerfect = perfect(i); 
    //result of what we did above
    if(IsPerfect == true) {
      cout << i << " ";
    }
    if(i == (num - 1)) {
      cout << endl;
    }
  }
//If no parameter was passed, the function prints out all perfect numbers less than 500.
  for(int i = 1; i < 500; i++) {
    IsPerfect = perfect(i);
    if(IsPerfect == true) {
      cout << i << " ";
    }
  }
  cout << endl;
}
int main () {

  int usernum;
  //user number we will use to see if it is perfect or not
  cout << "enter a numbers:" << endl;
  cin >> usernum;
  //make sure it is above zero
  while(usernum <= 0) {
    cout << "ERROR" << endl;
    cin >> usernum;
  }
  //calling functions written above to determine if it is a perfect number or not
  perfectprint(usernum);
  perfectprint();
  return 0;
}
