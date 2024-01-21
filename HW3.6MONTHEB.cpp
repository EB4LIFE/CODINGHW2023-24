#include <iostream>
using namespace std;
int main() {

	int mon;

	enum MONTH { JAN = 1, FEB, MARCH, APRIL, MAY, JUNE, JULY, AUG, SEPT, OCT, NOV, DEC };

	cout << "enter a number:" << endl;
	cin >> mon;

	switch (mon) {  
	case JAN:       
	case MARCH:
	case MAY:
	case JULY:
	case AUG:
	case OCT:
	case DEC:
		cout << "31 days in the month" << endl;
		break;
	case APRIL:    
	case JUNE:
	case SEPT:
	case NOV:
		cout << "30 days in the month" << endl;
		break;
	case FEB:           
		cout << "28 days in the month" << endl;
		break;
	default:
		break;
	}
		return 0;
}
