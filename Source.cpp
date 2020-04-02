#include<iostream>
#include<string>
#include<fstream>
#include<list>
#include "Header.h"

using namespace std;



int main() {
	init();
	int action = 0;
	int count = 0;
	int numberOfEmployee = 0;

	do {
		cout << "1. Show employees list" << endl;
		cout << "2. Search employees of the same age" << endl;
		cout << "3. Search employees whose name begins with the same letter" << endl;
		cout << "4. Portfolio of employee " << endl;
		cout << "5. Add employee" << endl;
		cout << "6. Edit information for employee" << endl;	
		cout << "7. Delete employee" << endl;
		cout << "8. Exit " << endl << endl;
		
		cout << "Enter action->_ ";
		cin >> action;
		cout << endl;
		switch (action) {
		case 1:
			showListEmployees();
			break;
		case 2:
			showbyAge();
			cout << endl;
			break;
		case 3:
			searchbyLetter();
			cout << endl;
			break;
		case 4:
			portfolioOfEmployeer();
			cout << endl;
			break;
		case 5:
			cout << "Enter the number of employees you want to add->_";
			cin >> count;
			addEmployee(&count);
			cout << endl;
			saveListEmployees();
			break;
		case 6:
			cout << "Enter number of emloyee you want to edit->_ ";
			cin >> numberOfEmployee;
			editEmployee(numberOfEmployee);
			saveListEmployees();
			break;
		case 7:
			cout << "Enter number of emloyee you want to delete->_ ";
			cin >> numberOfEmployee;
			deleteEmployee(numberOfEmployee);
			saveListEmployees();
			break;
		case 8:
			cout << "Bye ;)" << endl;
			break;
		default:
			cout << "Error! Enter another number!" << endl << endl;
		}

	} while (action != 8);


	system("pause");
	return 0;
}