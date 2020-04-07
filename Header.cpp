#include "Header.h"
#include<iostream>
#include<string>
#include<list>
#include <iterator>
#include<fstream>
using namespace std;

int index_count = 0;
const string fileName1 = "SearchInformation.txt";
const string fileName2 = "ListOfEmployees.txt";


struct employee {
	string firstName;
	string lastName;
	int age;
	string position;
};


list<employee> listEmployees;
list <employee> ::iterator it;


void init()
{
	ifstream fin;
	fin.open(fileName2);

	bool isOpen = fin.is_open();
	if (isOpen == true) {

		while (!fin.eof()) {
			employee tempEmployee;
			
			fin>> tempEmployee.lastName;
			if (tempEmployee.lastName != "") {
				fin >> tempEmployee.firstName;
				fin >> tempEmployee.age;
				fin >> tempEmployee.position;
				listEmployees.push_back(tempEmployee);
			}
			else {
				break;
			}
		}
	}
	else {
		cout << "Error!" << endl;
	}

	fin.close();
}




int addEmployee(int* count)
{
	if (index_count >= *count) {
		index_count = 0;
		return 0;
	}
	else {				
			employee newEmployee;
			cout << "Enter employee first name ->_";
			cin >> newEmployee.firstName;

			cout << "Enter employee last name ->_";
			cin >> newEmployee.lastName;			

			cout << "Enter employee age ->_";
			cin >> newEmployee.age;

			cout << "Enter employee position ->_";
			cin >> newEmployee.position;	

			cout << endl;

			listEmployees.push_back(newEmployee);

			index_count++;
			return addEmployee(count);
		}		
	
}

	void showListEmployees()
	{
		int count = 1;
		if (listEmployees.empty()) {

			cout << "The list is empty!" << endl << endl;
		}
		else {
			for (employee item : listEmployees) {
				cout << count << ") " << item.lastName <<
					" " << item.firstName << endl;

				count++;
			}
			cout << endl;
		}
	}

	void portfolioOfEmployeer()
	{
		int index = 0;
		bool isEmpty = false;
		if (listEmployees.empty()) {

			cout << "The list is empty!" << endl << endl;
		}
		else {
			ofstream fout;
			fout.open(fileName1, fstream::app);
			bool isOpen = fout.is_open();
			if (isOpen == true) {

			string lastName;
			cout << "Enter the second name of employee->_";
			cin >> lastName;
			cout << endl;
			fout << "Portfolio of selected employee: " << endl;
			for (employee item : listEmployees) {
				if (item.lastName == lastName) {
					index++;
					cout << "Portfolio of selected employee: " << endl;
					cout << "\t" << item.lastName << " " << item.firstName <<
						"\n\t" << item.age << " years"
						"\n\t" << item.position << endl;						
					cout << endl;
					
					fout << "\t" << item.lastName << " " << item.firstName <<
						"\n\t" << item.age << " years"
						"\n\t" << item.position << endl;
				}
				else if (item.lastName != lastName&&index==1) {
					isEmpty = true;
				}
			}
			if (isEmpty == true) {
				cout << "No matches found!" << endl;
			}
			}
			else {
				cout << "Error!" << endl;
			}

			fout.close();
		}
	}

	void editEmployee(int &num)	{
		it = listEmployees.begin();
		int count = 0;
		employee tempEmployee;

		if (listEmployees.empty()) {

			cout << "The list is empty!" << endl << endl;
		}
		else {			
			for (employee item : listEmployees) {
				count++;
			}
			if (num > count || num <= 0) {

				cout << "Enter another number!" << endl;
				return;
			}
			else {
				num--;
				advance(it, num);
				it = listEmployees.erase(it);
				cout << "Enter employee NEW first name ->_";
				cin >> tempEmployee.firstName;

				cout << "Enter employee NEW second name ->_";
				cin >> tempEmployee.lastName;

				cout << "Enter employee age ->_";
				cin >> tempEmployee.age;

				cout << "Enter employee NEW position ->_";
				cin >> tempEmployee.position;

				cout << endl;

				listEmployees.insert(it, tempEmployee);
				cout << "Employee information successfully changed!" << endl;
			}
		}
		cout << endl;
		
	}

	void deleteEmployee(int &num)
	{
		it = listEmployees.begin();
		int count = 0;
		if (listEmployees.empty()) {

			cout << "The list is empty!" << endl << endl;
		}
		else {
			for (employee item : listEmployees) {				
				count++;				
			}

			if (num > count || num <=0) {

				cout << "Enter another number!" << endl;
				return;
			}
			else {
				num --;
				advance(it, num);
				it = listEmployees.erase(it);
				cout << "Employee successfully deleted!" << endl;

			}
			cout << endl;
		}
	}

	void showbyAge()
	{
		int index = 0;
		int count = 1;
		bool isEmpty = false;
		if (listEmployees.empty()) {

			cout << "The list is empty!" << endl << endl;
		}
		else {
			ofstream fout;
			fout.open(fileName1, fstream::app);
			bool isOpen = fout.is_open();
			if (isOpen == true) {
			int showByAge;
			cout << "Enter the age of employee->_";
			cin >> showByAge;
			cout << endl;
			fout << "Emloyees of the age -" << showByAge << " : "<< endl;
			cout << "Emloyees of the age -" << showByAge << " : " << endl;

			for (employee item : listEmployees) {
				if (item.age == showByAge) {
					index++;
					cout << count<< ") " << item.lastName << " " << item.firstName <<" - " << item.position << endl;					

					fout << count << ") " << item.lastName << " " << item.firstName << " - " << item.position << endl;

					count++;
				}

				else if (item.age != showByAge&&index==1) {
					isEmpty = true;
				}
			}
			if (isEmpty == true) {
				cout << "No matches found!" << endl;
			}

			}
			else {
				cout << "Error!" << endl;
			}
			fout.close();
		}
	}

	void saveListEmployees()
	{
		ofstream fout;
		fout.open(fileName2);
		bool isOpen = fout.is_open();
		if (isOpen == true) {
			for (employee item : listEmployees) {
				fout << item.lastName << endl;
				fout << item.firstName << endl;
				fout << item.age << endl;
				fout << item.position << endl;
			}
		}		
		else {
			cout << "Error!" << endl;
		}

		fout.close();

	}

	void searchbyLetter()
	{
		int index = 0;
		int count = 1;
		bool isEmpty = false;
		if (listEmployees.empty()) {

			cout << "The list is empty!" << endl << endl;
		}
		else {
			ofstream fout;
			fout.open(fileName1, fstream::app);
			bool isOpen = fout.is_open();
			if (isOpen == true) {
				char firstLetter;
				cout << "Enter first letter of the last name of employee->_";
				cin >> firstLetter;
				cout << endl;
				fout << "Emloyees whose name begins with the letter -" << firstLetter << " : " << endl;
				cout << "Emloyees whose name begins with the letter -" << firstLetter << " : " << endl;
				for (employee item : listEmployees) {
					if (item.lastName[0] == firstLetter) {
						index++;
						cout << count << ") " << item.lastName << " " << item.firstName << " - " << item.position << endl;

						fout << count << ") " << item.lastName << " " << item.firstName << " - " << item.position << endl;

						count++;
					}
					else if (item.lastName[0] != firstLetter&&index==1) {
						isEmpty = true;
					}
				}
				if (isEmpty == true) {
					cout << "No matches found!" << endl;
				}
				cout << endl;
			}
			else {
				cout << "Error!" << endl;
			}
			fout.close();
		}		
	}
	
		
