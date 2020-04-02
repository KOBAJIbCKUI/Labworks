#include <iostream>
#include <iomanip>
#include <conio.h>

using namespace std;

int main()
{
	const double B[3][5] = { {8,2,3,4,5},{6,7,1,9,10},{11,12,13,14,15} }; //Initial array
	double V[2][4]; //Output array
	double min = B[0][0]; //Min element
	int rowIndex = 0; //Row with min element
	int colIndex = 0; //Column with min element
	cout << "This program makes from array B with size 3x5 array V with size 2x4" << endl;
	cout << "which contains elements from B" << endl;
	cout << "without row and column where the minimal element is placed" << endl;
	cout << "Array B " << endl << endl;
	
	for (int i = 0; i < 3; i++)//Showing array B
	{
		for (int j = 0; j < 5; j++)
		{
			cout << setw(3) << right << B[i][j] << ' ';
		}
		cout << endl << endl;
	}

	for (int i = 0; i < 3; i++)//Looking for min element
	{
		for (int j = 0; j < 5; j++)
		{
			if (min > B[i][j])
			{
				min = B[i][j];
				rowIndex = i;
				colIndex = j;
			}
		}
	}
	
	cout << "Min element is B[" << rowIndex << "][" << colIndex << "] = " << min << endl << endl;
	cout << "Array V " << endl << endl;

	for (int i = 0, k = 0; i < 3; i++)//Copying B to V
	{
		if (i == rowIndex)
			continue;
		for (int j = 0, l = 0; j < 5; j++)
		{
			if (j == colIndex)
				continue;
			V[k][l] = B[i][j];
			l++;
		}
		k++;
	}

	for (int i = 0; i < 2; i++)//Showing array V
	{
		for (int j = 0; j < 4; j++)
		{
			cout << setw(3) << right << V[i][j] << ' ';
		}
		cout << endl << endl;
	}
	
	_getch();
	return 0;
}