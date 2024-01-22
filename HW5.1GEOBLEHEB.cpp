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
}
