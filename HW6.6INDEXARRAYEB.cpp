#include <iostream>

using namespace std;

void updateArray(int numbers[], int n, int arr[]);

int main() {
    const int size = 7;
    int numbers[size];
    int arr[10];

    // Input 7 positive integers
    cout << "Enter 7 numbers: " << endl;
    for (int i = 0; i < size; ++i) {
        cin >> numbers[i];
        if (numbers[i] < 0) {
            cout << "ERROR" << endl;
            return 0;
        }
    }

    // Update the array according to the specified rules
    updateArray(numbers, size, arr);

    // Output the resulting array
    cout << "Output:" << endl; 
    for (int i = 0; i < 10; ++i) {
        cout << arr[i] << " ";
    }

    return 0;
}

void updateArray(int numbers[], int n, int arr[]) {
    // Initialize arr with zeros
    for (int i = 0; i < 10; ++i) {
        arr[i] = 0;
    }

    // Count the occurrences of each digit
    for (int i = 0; i < n; ++i) {
        int num = numbers[i];
        while (num > 0) {
            int digit = num % 10;
            arr[digit] = arr[digit] * 10 + digit;
            num /= 10;
        }
    }
}
