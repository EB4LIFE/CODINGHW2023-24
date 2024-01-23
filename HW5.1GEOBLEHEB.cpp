#include<iostream>
using namespace std;

//Function that if called will give the area of rectangle with specified values
int area(int rl, int rw) {
      int Rectarea;
      Rectarea = rl * rw;
      return Rectarea;
}
//Function that if called will give the area of circle with specified values
double area(int rad) {
    const double PI = 3.14159;
    double Cirarea;
    Cirarea = PI * rad * rad;
    return Cirarea;
}

int main() {
    
    int rectarea;
    double cirarea;
//variables for user's Rect and circle respectively
    int url;
    int uwl;
    int ucr; //will be used for circle code
//Asking user input for Length and width 
    cout << " Enter length and width of the rectangle:" << endl;
    cin >> url >> uwl;
//Making sure user inputted numbers whole and non negative numbers
   while(url <=0 || uwl <=0) {
       cout << "ERROR" << endl;
       cin >> url >> uwl;
 }
//Calling function of Rect area and outpiting results using user input
   rectarea = area(url, uwl);
   cout << rectarea << endl;
//Part 2 - same thing we did but with the circle function using user input variable ucr
cout << "Enter radius of the circle:" << endl;
cin >> ucr;
//same as before checking to make sure it fits our parameters as whole non negative number
while(ucr<=0) {
  cout << "ERROR" << endl;
       cin >> ucr;
}
cirarea = area(ucr);
cout << cirarea << endl;

return 0;
}
