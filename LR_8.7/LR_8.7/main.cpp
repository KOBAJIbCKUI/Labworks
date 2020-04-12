#include <conio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <list>

using namespace std;

struct Product//Element of list
{
	string prodName;
	int prodVolume, dateDay, dateMonth, dateYear;
	double prodPrice;
};

bool showFile(list<Product>);//Show list
bool writeElToFile(const char*, Product);//Write element to file
bool writeListToFile(const char*, list<Product>);//Write list to file
bool dateCheck(int, int, int);//Date checking

int main()
{
	//Programm creates container list which synchronizes with data in file
	cout << "This program can shape and adjust file," << endl;
	cout << "which consists of data about goods stored in a warehouse" << endl;

	ifstream fileRead;//File reading stream
	ofstream fileWrite;//File writing stream
	Product prodBuffer;//Buffer for one product
	list<Product> ProductsList;//List for products
	const char filename[13] = "Products.txt";//Name of file
	int  bufferKey;//Input by user
	int	 elementCounter;//Counter for elements in list
	bool endOfProg = false; //End the program

	while (!endOfProg)
	{
		fileRead.open(filename, ios::in);
		if (fileRead.is_open())//Does file exist
		{
			fileRead.seekg(0, ios::end);//Put file pointer to end of file
			if (fileRead.tellg())//Is file empty
			{
				fileRead.seekg(0, ios::beg);//Put file pointer to beginning of file
				if (!ProductsList.empty())//If list not empty
					ProductsList.clear();//clear it
				while (!fileRead.eof())//Read file to list of products
				{
					fileRead >> prodBuffer.prodName;
					fileRead >> prodBuffer.prodVolume;
					fileRead >> prodBuffer.dateDay;
					fileRead >> prodBuffer.dateMonth;
					fileRead >> prodBuffer.dateYear;
					fileRead >> prodBuffer.prodPrice;
					ProductsList.push_back(prodBuffer);
				}
			}

			fileRead.close();
		}
		cout << endl;//Main menu
		cout << "Main menu. Press key to choose option" << endl;
		cout << "1. Add product to list" << endl;
		cout << "2. Delete product by index" << endl;
		cout << "3. Clear list of products" << endl;
		cout << "4. Show list of products" << endl;
		cout << "5. Exit" << endl;
		cin >> bufferKey;
		cout << endl;
		
		switch (bufferKey)
		{
		case 1://Add product
		{
			cout << "Input product name" << endl;
			cin >> prodBuffer.prodName;
			cout << "Input volume of batch" << endl;
			cin >> prodBuffer.prodVolume;
			cout << "Input day of receipt at a warehouse" << endl;
			cin >> prodBuffer.dateDay;
			cout << "Input month of receipt at a warehouse" << endl;
			cin >> prodBuffer.dateMonth;
			cout << "Input year of receipt at a warehouse" << endl;
			cin >> prodBuffer.dateYear;
			if (!dateCheck(prodBuffer.dateDay, prodBuffer.dateMonth, prodBuffer.dateYear))
			{
				cout << "Invalid date: " << prodBuffer.dateDay << '.' << prodBuffer.dateMonth << '.' << prodBuffer.dateYear << endl;
				break;
			}
			cout << "Input unit cost" << endl;
			cin >> prodBuffer.prodPrice;
			
			if (writeElToFile(filename, prodBuffer))
				cout << "New element successfully added to list" << endl;
			else
				cout << "Unable to open file " << filename << " for writing" << endl;
			break;
		}//end case 1
		case 2://Delete product
		{
			if (showFile(ProductsList))//Show file if its not empty and it exists
			{
				cout << "Input index of element you want to delete" << endl;
				cin >> bufferKey;

				if (bufferKey > 0 && bufferKey <= ProductsList.size())//Check for valid index
				{
					elementCounter = 0;
					//Delete element
					for (list<Product>::iterator it = ProductsList.begin(); it != ProductsList.end(); elementCounter++)
					{
						if (elementCounter == bufferKey - 1)//Index in file begins from 1
						{
							ProductsList.erase(it);
							it = ProductsList.end();
							continue;
						}
						it++;
					}
					if (writeListToFile(filename, ProductsList))
						cout << "Element with index " << bufferKey << " successfully deleted" << endl;
					else
						cout << "Unable to write changes to file " << filename << endl;
				}
				else
				{
					cout << "Element with index " << bufferKey << " not found" << endl;
				}
			}
			else
				cout << "List is empty" << endl;
			break;
		}//end case 2
		case 3://Clear file
		{
			if (!ProductsList.empty())
			{
				ProductsList.clear();//Clear list
				fileWrite.open(filename, ios::trunc);//Clear file
				fileWrite.close();
				cout << "List successfully cleared" << endl;
			}
			else
				cout << "List is empty" << endl;
			break;
		}//end case 3
		case 4://Show list
		{
			if (!showFile(ProductsList))
				cout << "List is empty" << endl;
			break;
		}//end case 4
		case 5://Exit
		{
			endOfProg = true;
			break;
		}//end case 5
		default:
		{
			cout << "Unknown option" << endl;
			break;
		}
		}//end switch
	}//end while(endOfProg)
	cout << "Press any key" << endl;
	_getch();
	return 0;
}

bool dateCheck(int day, int month, int year) { //Check date
	if (month >= 1 && month <= 12) {
		int arrMonths[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };//Days in months
		bool leapYear = false;
		if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {//Check for leap year
			arrMonths[1]++;
			leapYear = true;
		}
		if (day > 0 && day <= arrMonths[month - 1]) { // Check for right day in month
			return true;
		}
	}
	return false;
}

bool showFile(list<Product> Products)
{
	Product prodBuffer;
	int counter = 1;//Elements counter
	if (!Products.empty())
	{
		for (list<Product>::iterator it = Products.begin(); it != Products.end(); it++, counter++)
		{
			cout << endl;
			cout << "#" << counter << endl;
			cout << "Name: " << it->prodName << endl;
			cout << "Volume of batch: " << it->prodVolume << endl;
			cout << "Date of receipt at a warehouse: " << it->dateDay << '.' << it->dateMonth << '.' << it->dateYear << endl;
			cout << "Unit cost: " << it->prodPrice << endl << endl;
		}
		return true;
	}
	else
		return false;
}

bool writeElToFile(const char* filename, Product prodBuffer)
{
	ofstream fileWrite;
	fileWrite.open(filename, ios::app);//Write to end of file
	if (fileWrite.is_open())
	{
		fileWrite << endl;
		fileWrite << prodBuffer.prodName << endl;
		fileWrite << prodBuffer.prodVolume << endl;
		fileWrite << prodBuffer.dateDay << endl;
		fileWrite << prodBuffer.dateMonth << endl;
		fileWrite << prodBuffer.dateYear << endl;
		fileWrite << prodBuffer.prodPrice;
		fileWrite.close();
		return true;
	}
	return false;
}

bool writeListToFile(const char* filename, list<Product> ProductsList)
{
	ofstream fileWrite;
	fileWrite.open(filename, ios::out | ios::trunc);

	if (fileWrite.is_open())
	{
		if (!ProductsList.empty())
		{
			for (list<Product>::iterator it = ProductsList.begin(); it != ProductsList.end(); it++)
			{
				fileWrite << endl;
				fileWrite << it->prodName << endl;
				fileWrite << it->prodVolume << endl;
				fileWrite << it->dateDay << endl;
				fileWrite << it->dateMonth << endl;
				fileWrite << it->dateYear << endl;
				fileWrite << it->prodPrice;
			}
		}
		else
			fileWrite.seekp(0, ios::end);//Put file pointer to end of file
		fileWrite.close();
	}
	else
		return false;
	return true;
}