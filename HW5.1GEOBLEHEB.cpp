#include<iostream>
using namespace std;

//Function that if called will give the area of rectangle with specified values
int Area(int rl, int rw) {
      int Rectarea;
      Rectarea = rl * rw;
      return Rectarea;
}
//Function that if called will give the area of circle with specified values
double Area(int rad) {
    const double PI = 3.14159;
    double Cirarea;
    Cirarea = PI * rad * rad;
    return Cirarea;
}

int main() {
    
//variables for user's Rect and circle respectively
    int url;
    int uwl;
    int ucr; //will be used for circle code
//Asking user input for Length and width 
    cout << "enter length and width of the rectangle:" << endl;
    cin >> url >> uwl;
//Making sure user inputted numbers whole and non negative numbers
   while(url <=0 || uwl <=0) {
       cout << "ERROR" << endl;
       cin >> url >> uwl;
 }
   


}
