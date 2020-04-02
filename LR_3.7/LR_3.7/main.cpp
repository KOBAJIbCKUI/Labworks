#include <iostream>
#include <conio.h>
#include <cmath>

using namespace std;

int main() 
{
	double x1, x2; //Borders
	double a, b, c; //Coeffs
	double n; //Number of values
	double h; //Step
	cout << "This program will calculate and print n values of function" << endl;
	cout << "y = (| a * x ^ 2 + b * x + c | ) ^ 1 / 2" << endl;
	cout << "where x changes from x1 to x2 with step h" << endl;
	cout << "h = (x2 - x1)/(n - 1)" << endl;
	cout << "Input x1 ";
	cin >> x1;
	cout << "Input x2 ";
	cin >> x2;
	cout << "Input a ";
	cin >> a;
	cout << "Input b ";
	cin >> b;
	cout << "Input c ";
	cin >> c;
	cout << "Input n ";
	cin >> n;
	cout << "Result" << endl;
	h = (x2 - x1) / (n - 1); //Calculating step
	for(int i = 0;  i < n; i++)
	{
		cout << sqrt(abs(a * pow(x1, 2) + b * x1 + c)) << ' ';
		x1 += h;
		cout << endl;
	}
	cout << "Press any key" << endl;
	_getch();
	return 0;
}