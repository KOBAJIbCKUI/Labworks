#include <conio.h>
#include <iostream>
#include <cmath>

using namespace std;

//Function prototypes

double ro(int, double);//ro(x,S)

double f(int*, int, int*, int, double);//f(S)

int teta(int, int*, int);//teta(x)

int main()
{
	cout << "This program works with set D and with its subset D1." << endl;
	cout << "You can add numbers from D to D1" << endl;
	cout << "It calculates function f(S) which contains fuctions ro(x,S) and teta(x)." << endl;
	
	const int numberOfD = 10;//Number of elements in D
	int numberOfD1 = 0;//Number of elements in D1
	int buffer;//Input by user
	
	double S;//Input by user
	
	char exitQuestion;//Input by user
	
	bool Exit = true;//Exit flag
	bool validNumber;//Users number in buffer must exist in D and must not exist in D1
	bool endOfD1;//Stops to form subset D1
	
	//Memory allocating
	int* D = new int[numberOfD];
	int* D1;
	int* bufferSet;

	cout << "Set D contains:" << endl;
	
	for (int i = 0; i < numberOfD; i++)//Filling D
	{
		D[i] = i;
		cout << D[i] << endl;
	}

	while (Exit)//Cycle of calculating
	{
		endOfD1 = false;
		validNumber = false;
		D1 = new int;//Allocating memory for subset D1
		numberOfD1 = 0;
		while (!endOfD1)
		{
			cout << "Do you want to add elements from D to D1? (y/n)" << endl;
			cin >> exitQuestion;
			
			if (!(exitQuestion == 'y' || exitQuestion == 'Y'))
			{
				endOfD1 = true;
				continue;
			
			}

			cout << "Input integer number you want to put from D to D1" << endl;
			cin >> buffer;
			
			for (int i = 0; i < numberOfD && !validNumber; i++)//does number exist in D
			{
				if (D[i] == buffer)
				{
					validNumber = true;
				}
			}

			if (!validNumber)
			{
				cout << buffer << " doesn't exist in D" << endl;
				continue;
			}

			for (int i = 0; i < numberOfD1 && validNumber; i++)//Does number not exist in D1
			{
				if (D1[i] == buffer)
				{
					validNumber = false;
				}
			}

			if (!validNumber)
			{
				cout << buffer << " already exists in D1" << endl;
				continue;
			}
			
			//Expanding memory for D1

			bufferSet = new int[numberOfD1];//Allocating memory for buffer

			for (int i = 0; i < numberOfD1; i++)//Saving D1 to buffer
				bufferSet[i] = D1[i];

			delete[] D1;
			numberOfD1++;
			D1 = new int[numberOfD1];//Expanding

			for (int i = 0; i < numberOfD1 - 1; i++)//Saving buffer to expanded D1 
				D1[i] = bufferSet[i];

			delete[] bufferSet;
			D1[numberOfD1 - 1] = buffer;//Adding new number to D1
	
		}

		cout << "Subset D1 contains: " << endl;

		for (int i = 0; i < numberOfD1; i++)//Showing subset D1
		{
			cout << D1[i] << endl;
		}

		cout << "Input double S" << endl;
		cin >> S;

		cout << "Result of f(S) is: " << f(D, numberOfD, D1, numberOfD1, S) << endl;

		cout << "Do you want to calculate f(S) again? (y/n)" << endl;//Asking for exit
		cin >> exitQuestion;
			if (!(exitQuestion == 'y' || exitQuestion == 'Y'))
				Exit = false;
			delete[] D1;
	}
	cout << endl << "Press any key";
	_getch();
	delete D;
	return 0;
}

//Declaration of functions

double ro(int x, double S)//ro(x,S)
{
	return pow(x / S, 2);
}

int teta(int number, int* D1, int numberOfD1)//teta(x)
{
	for (int i = 0; i < numberOfD1; i++)
	{
		if (number == D1[i])
			return 1;
	}
	return 0;
}

double f(int* D, int numberOfD, int* D1, int numberOfD1, double S)//f(S)
{
	double sum1 = 0;
	double sum2 = 0;
	for (int i = 0; i < numberOfD; i++)
	{
		sum1 += D[i] * ro(D[i], S) * teta(i, D1, numberOfD1);
		sum2 += ro(D[i], S) * teta(i, D1, numberOfD1);
	}
	return sum1 / sum2;
}
