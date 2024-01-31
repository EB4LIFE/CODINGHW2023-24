#include<iostream>
using namespace std;

void FillArray(int arr[], const int size);
bool CheckDifference(int element1, int arr2[], int size);
void FillDifference(int arr1[], int arr2[], int arrDiff[], int size);
void PrintDifference(int arrDiff[], int size);

int main() {
    int set1[6];
    int set2[6]; 
    int difference[6] = { 0 };

    cout << "Enter first 6 numbers:" << endl;
    FillArray(set1, 6);

    cout << "Enter next 6 numbers:" << endl;
    FillArray(set2, 6);

    FillDifference(set1, set2, difference, 6);

    cout << "Set difference is:" << endl;
    PrintDifference(difference, 6);

    return 0;
}

void FillArray(int arr[], const int size) {
    bool Error = false;
    int input;

    do {
        for (int i = 0; i < size; i++) {
            cin >> input;
            if (input > 0) {
                arr[i] = input;
            }
            else {
                Error = true;
                cout << "ERROR" << endl;
                break;
            }
        }
    } while (Error == true);
}

bool CheckDifference(int element1, int arr2[], int size) {
    bool inSet = false;

    for (int i = 0; i < size; i++) {
        if (element1 == arr2[i]) {
            inSet = true;
            break;
        }
    }
    return inSet;
}

void FillDifference(int arr1[], int arr2[], int arrDiff[], int size) {
    bool inSet2;

    for (int i = 0; i < size; i++) {
        inSet2 = CheckDifference(arr1[i], arr2, size);

        if (inSet2 == true) {
            arrDiff[i] = 0;
        }
        else {
            arrDiff[i] = arr1[i];
        }
    }
}

void PrintDifference(int arrDiff[], int size) {
    bool EMPTY = true;

    for (int i = 0; i < size; i++) {
        if (arrDiff[i] == 0) {
            EMPTY = true;
        }
        else {
            EMPTY = false;
            break;
        }
    }
    if (EMPTY == true) {
        cout << "empty" << endl;
    }
    else {
        for (int j = 0; j < size; j++) {
            if (arrDiff[j] != 0) {
                cout << arrDiff[j] << " ";
            }
        }
        cout << endl;
    }
}
