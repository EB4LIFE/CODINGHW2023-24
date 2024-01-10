#include <iostream>
using namespace std;

int main() {

    int hour;
    int min;
    int sec;
    int hourF;
    int minF;
    int secF;
    int hourA;
    int minA;
    int secA;
    cout << "enter flight takeoff:\n";
    cin >> hour >> min >> sec;
    cout << "enter flight duration:\n";
    cin >> hourF >> minF >> secF;
    secA = sec + secF;
    minA = min + minF + (sec / 60);
    hourA = hour + hourF + (minA / 60);
    hourA = hourA % 24;
    minA = minA % 60;
    secA = secA % 60;
    cout << "flight arrival is:" << endl;
    cout << hourA << ":" << minA << ":" << secA << endl;
    return 0;
}
