#include <iostream>
using namespace std;

int main() {

    int a;
    int one;
    int ten;
    int hun;
    int sum;
    cout << "enter a three digit number:" << endl;
    cin >> a;
    hun = a / 100;
    ten = (a / 10) % 10;
    one = a % 10;
    sum = hun + ten + one;
    cout << "the sum is: " << sum << endl;
}

