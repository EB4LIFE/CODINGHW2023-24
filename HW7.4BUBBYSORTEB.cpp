#include <iostream>
#include <cctype> 
using namespace std;

const int words = 10;
const int letters = 5;

bool fillMatrix(char matrix[][letters], int rows);
void bubbleSort(char words[][letters], int rows);
bool compareWords(char w1[], char w2[], int wLen);
void swapWords(char w1[], char w2[], int wLen);
void printMatrix(const char matrix[][letters], int rows);

int main() {
    char Wlist[words][letters];
    cout << "Enter 10 words:" << endl;
    if(fillMatrix(Wlist, words)) {
    bubbleSort(Wlist, words);
    cout << "After sorting:" << endl;
    printMatrix(Wlist, words);
    }
    return 0;
}

bool fillMatrix(char matrix[][letters], int rows) {
    for (int i = 0; i < rows; i++) {
       for (int j = 0; j < letters; j++) {
            cin >> matrix[i][j];
            if ((matrix[i][j] >= 'A') && (matrix[i][j] <= 'Z'))  {
                cout << "ERROR" << endl;
                return false;
            }
       }
    }
    return true;
}
void bubbleSort(char words[][letters], int rows) {
    int sort;
    int i;
    bool first;
    for (sort = (rows - 1); sort > 0; sort--) {
        for (i = 0; i < sort; i++) {
            first = compareWords(words[i], words[i + 1], letters);
            if (first == false) {
                swapWords(words[i + 1], words[i], letters);
            }
        }
    }
}

bool compareWords(char w1[], char w2[], int wLen) {
    for (int i = 0; i < wLen; i++) {
        if (w1[i] < w2[i]) {
            return true;
        }
        else if (w1[i] > w2[i]) {
            return false;
        }
    }
    return true;
}

void swapWords(char w1[], char w2[], int wLen) {
    for (int i = 0; i < wLen; i++) {
        char temp = w1[i];
        w1[i] = w2[i];
        w2[i] = temp;
    }
}

void printMatrix(const char matrix[][letters], int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < letters; j++) {
            cout << matrix[i][j];
        }
        cout << '\t';
    }
}
