#include<iostream>
#include <cstring>
using namespace std;




//Struct for store's prodcuts Add a new product to the store 
//Product code(integer)
//Product name(string up to 20 characters)
//Current amount in stock(integer)
//Minimum amount needed in stock(integer)
//Price of product(real number)
struct Item {

	int pCode;       
	char pName[20];  
	int curStock;       
	int minStock;       
	float pPrice;    
};
//Add a new product to the store
void addItem(Item* prodlist, int maxprod, int& amountprod);
//Cost of product given a product code
int codeIndex(Item* prodlist, int amountprod, int userCode);
//find price of an item
void findPrice(Item* prodlist, int amountprod);
//Sale of a product(reduces amount in stock)
void sold(Item* prodlist, int amountprod);
//Reorder of product whenever amount in stock falls below minimum
void order(Item* prodlist, int amountprod);
//Print stock
void print(Item* prodlist, int amountprod);
//MAIN CODE 
enum cases { EXIT, ADD, FIND, SOLD, ORDER, PRINT };
int main()
{
	Item* store;
	int maxItems;
	int numItems = 0;
	int choice;
	cout << "enter max number of items: " << endl;
	cin >> maxItems;
	store = new Item[maxItems];

	do {
		cout << "enter 0-5:\n";

		cin >> choice;

		switch (choice) {
		case EXIT:	break;

		case ADD:	addItem(store, maxItems, numItems);
			break;

		case FIND: 	findPrice(store, numItems);
			break;

		case SOLD:	sold(store, numItems);
			break;

		case ORDER:	order(store, numItems);
			break;

		case PRINT: 	print(store, numItems);
			break;

		default: 	cout << "ERROR" << endl;
		}
	} while (choice != 0);

	return 0;
}
//Initliazation of functions
void addItem(Item* prodlist, int maxprod, int& amountprod) {
	int tempCode;
	int tempcurrentamount;
	int tempminamount;
	char tempName[20];
	float tempPrice;
	cout << "enter code:" << endl; 
	cin >> tempCode;
	cout << "enter name:" << endl;
	cin >> tempName;
	cout << "enter amount:" << endl;
	cin >> tempcurrentamount;
	cout << "enter minimum amount:" << endl;
	cin >> tempminamount;
	cout << "enter price:" << endl;
	cin >> tempPrice;

	if (amountprod == 0) { 
		prodlist[amountprod].pCode = tempCode;
		strcpy(prodlist[amountprod].pName, tempName); 
		prodlist[amountprod].curStock = tempcurrentamount;
		prodlist[amountprod].minStock = tempminamount;
		prodlist[amountprod].pPrice = tempPrice;

		amountprod++; 
		return; 
	}
	int existingCode = codeIndex(prodlist, amountprod, tempCode); 

	if (existingCode >= 0) { 

		if (strcmp(tempName, prodlist[existingCode].pName) == 0) { 
			prodlist[existingCode].curStock += tempcurrentamount; 
			return; 
		}
		else { 
			//product code exists but the names are different
			cout << "ERROR" << endl;
			return; 
		}
	}
	else { 
		//returned 0, so code doesn't exist--item doesn't exist, so now checking if enough room to add another item 
		if ((amountprod + 1) <= maxprod) { 

			prodlist[amountprod].pCode = tempCode;
			strcpy(prodlist[amountprod].pName, tempName);
			prodlist[amountprod].curStock = tempcurrentamount;
			prodlist[amountprod].minStock = tempminamount;
			prodlist[amountprod].pPrice = tempPrice;

			amountprod++; 
			return; 
		}
		else { 
			//not enough room left in array 
			cout << "ERROR" << endl;
		}
	}
}
int codeIndex(Item* prodlist, int amountprod, int userCode) {
	//loop through all items to find the code
	for (int i = 0; i < amountprod; i++) {
		if (prodlist[i].pCode == userCode) { 
			//we found the code so return index from array
			return i;
		}
	}
	//else 
	return -1; 
}
void findPrice(Item* prodlist, int amountprod) {
	int inputCode;
	cout << "enter code:" << endl; 
	cin >> inputCode;
	//now will loop through list to find a product with an item code that matches user input
	for (int i = 0; i < amountprod; i++) { 
		//found the item user is looking for
		if (inputCode == prodlist[i].pCode) { 
			cout << "price: " << prodlist[i].pPrice << endl;
			return; 
		}
	}
	cout << "ERROR" << endl;
}
void sold(Item* prodlist, int amountprod) {
	int inputCode;
	int inputamount;

	cout << "enter code:" << endl;
	cin >> inputCode;
	cout << "enter amount:" << endl;
	cin >> inputamount;

	for (int i = 0; i < amountprod; i++) { 

		//found item by a matching code
		if (inputCode == prodlist[i].pCode) { 
			prodlist[i].curStock -= inputamount; 
			//reducinf amount sold from the inventory of a particular item in the store
			return; 
		}
	}
	cout << "ERROR" << endl; 
}
void order(Item* prodlist, int amountprod) {
	int needtoorder;
	for (int i = 0; i < amountprod; i++) {
		//checking each item if the current stock is less than minimum amount needed to be in stock
		if (prodlist[i].curStock < prodlist[i].minStock) { 
			cout << "item name: " << prodlist[i].pName << endl;
			cout << "code: " << prodlist[i].pCode << endl;
			//want that number in stock for product is 5 more than its minimum
			needtoorder = prodlist[i].minStock - prodlist[i].curStock + 5; 
			prodlist[i].curStock += needtoorder; 
			//updating stock to include the "order" made
			cout << "amount to order: " << needtoorder << endl;
		}
	}
}
void print(Item* prodlist, int amountprod) {
	//typical print loop with elements of this code
	for (int i = 0; i < amountprod; i++) { 

		cout << "name: " << prodlist[i].pName << endl;
		cout << "code: " << prodlist[i].pCode << endl;
		cout << "amount: " << prodlist[i].curStock << endl;
		cout << "minimum amount: " << prodlist[i].minStock << endl;
		cout << "price: " << prodlist[i].pPrice << endl;
		cout << endl;
	}
}
