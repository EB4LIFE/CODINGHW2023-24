#include<iostream>
using namespace std;
//Functions list that will be used in main
void fillArray(int* arrPtr, const int size);
//Classic Fillarray function howvever it will user pointer to array and its size

int Gapcheck(int* bigArr, int* smallArr, const int sizeB, const int sizeS);
//will check gapsize of 1 array in another using pointers


bool Checkcontain(int* bigArr, int* smallArr, const int sizeB, const int sizeS);
//will check if array1 is contained in array 2 using pointers



int main() {
    int big[80];
    int small[80];
    int userbig;
    int usersmall;
    int gap;
    //creating two pointers - each pointer respectiviley will have value of first element of array
    int* pointerB = big;
    int* pointerS = small;
    
    cout << "Enter the size of big:" << endl;
    cin >> userbig;
    //Make sure the input is in necessary range required 0<userbig<80
    while (userbig <= 0 || userbig > 80) {
        cout << "ERROR" << endl;
        cin >> userbig;
    }
    //We prompt user to input X numbers: X being size of userbig
    cout << "Enter " << userbig << " numbers:" << endl;
    fillArray(pointerB, userbig);

    //Now we repeat the process with small array
    cout << "Enter the size of small:" << endl;
    cin >> usersmall;
    //Make sure the input is in necessary range required 0<userbig<80
    while (usersmall <= 0 || usersmall > 80) {
        cout << "ERROR" << endl;
        cin >> usersmall;
    }
    //We prompt user to input X numbers: X being size of userbig
    cout << "Enter " << usersmall << " numbers:" << endl;
    fillArray(pointerS, usersmall);

    //Now we call function gapcheck to see  prints out the minimum gap size of small in big after first printing
    gap = Gapcheck(pointerB, pointerS, userbig, usersmall);

    cout << "Size of jump:" << endl;

    if (gap >= 0) {
        cout << gap << endl;
    }
    else {
        cout << "-1" << endl;
    }

}

//Implentation of the functions listed above
//Classic Fillarray function howvever it will user pointer to array and its size
void fillArray(int* arrPtr, const int size) {
    //sane for loop as usuall but with pointers instead
    for (int* p = arrPtr; p < (arrPtr + size); p++) {
        cin >> *p; //--> fill array like usual execpt with a pointer
    }
}

//will check if one array is contained in another using pointer
//stepping stone fucntion for gapcheck function below
bool Checkcontain(int* bigArr, int* smallArr, const int sizeB, const int sizeS) {
    int* index;
    int * p;
    int * q;
    //classic for loop changed for pointer to go thru small array
    for (p = smallArr; p < (smallArr + sizeS); p++) {
        index = NULL; 
        //we do this to reset value before every itteration of the loop
        //this loop will now do the comparing to see if small is contained in big
        for (q = bigArr; q < (bigArr + sizeB); q++) {
            if (*p == *q) {
                //if we find a same element from p in q set it to address
                index = q;
                break;
            }
        }
            //if element was found in big then set the big array to address of where we found it so it will continue to search from there
            if (index != NULL) {
                bigArr = index;
            }
            else {
                return false;
            }
        }
        return true;
    }
//checking the gap size of 1 array in another
int Gapcheck(int* bigArr, int* smallArr, const int sizeB, const int sizeS) {
    bool containedin;
    int distance;
    //There will be no need to gap check if if small isn't contained in big so we need to check if it is before continuing the function
    containedin = Checkcontain(bigArr, smallArr, sizeB, sizeS);
    //applying result
    if (containedin == false) {
        return -1; 
        //this will leave function and not continue
    }
    //if it made it to this point then we can assume small is cotained in big now we must find the gap
    //this loop is to go through the elements of small to compare to big and get gap size
    for (int* p = smallArr; p < (smallArr + sizeS); p++) { 
        if (sizeS == 1) {
            return 0;
        }
        //this loop will get size between the current element in small and the next one
        for (int* q = bigArr; q < (bigArr + sizeB); q++) { 
            if (*q == *p) {
                //this loop will now pick up where the loop above left off and search for next small element to compare to big
                for (int* r = (q + 1); r < (bigArr + sizeB); r++) { 
                    //looking for the next element in small inside big
                    if (*r == *(p + 1)) {
                        distance = (r - 1) - q; //jump size is the amount of numbers in between q and r so need to do r-1
                        if (sizeS == 2) {
                            return distance; //if there are only 2 numbers then checking p + 2 will go out of scope, so this is the distance
                        }
                        if (*(r + (distance + 1)) == *(p + 2)) { //checking if the element after r + gap is = 3rd small element
                            return distance; 
                        }
                    }
                }
            }
        }
    }
    return -1; //default setting, if the numbers are contained but aren't evenly spaced, will have gotten to this point and will return -1
}


