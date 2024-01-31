#include <iostream>
using namespace std;
//function to change array in Main function
void updateArray(int numbers[], int n, int arr[10]);

int main() {
    const int size = 7;
    int numbers[size];

  //input of user
    cout << "Enter 7 numbers: " << endl;
    for (int i = 0; i < size; ++i) {
        cin >> numbers[i];
    }
//calling array and now updating array using function 
     int arr[10];
     updateArray(numbers, size, arr);
     cout << "Output:" << endl;
  
    for (int i = 0; i < 10; ++i) {
        cout << arr[i] << " ";
    }
    return 0;
}

//intilaziation of the function
  void updateArray(int numbers[], int n, int arr[10]) {
      for (int i = 0; i < 10; ++i) {
        arr[i] = 0;
    }

    // Count the the numbers of each digit in the input array
    for (int i = 0; i < n; ++i) {
        int num = numbers[i];
        while (num > 0) {
            int digit = num % 10;
            arr[digit] = arr[digit] * 10 + digit; 
            num /= 10;
        }
    }
}

