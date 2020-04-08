#include <conio.h>
#include <iostream>
#include <stack> 
#include <cmath>
#include <string>

using namespace std;

int main()
{
	cout << "This program inputs sequences of zeros, ones and spaces," << endl;
	cout << "counts words and counts words that are multiple of 5" << endl;
	const string inputString = "01001010 0101010101010 01111001010 1001010010010101011 010101001 0 1 101 11"; 
	cout << "Input string is " << inputString << endl;
	const int One = 49;//One in ASCII
	string buffer; //Buffer for chars
	int counter = 0; //Counter for words and numbers multiple of 5
	char curChar; //Current char
	bool Space = true; //Is current char is space
	stack<string> Words; //Stack for words

	for (int i = 0; i <= inputString.length(); i++)//Count words and push to stack
	{
		curChar = inputString[i];
		if (!(curChar == ' ' || curChar == '\t' || curChar == '\0'))
		{
			buffer += curChar;
			Space = false;
		}
		else if (Space == false)
		{
			Space = true;
			counter++;
			Words.push(buffer);
			buffer.erase();
		}
		continue;
	}
	cout << "Number of words is " << counter << endl;
	counter = 0;

	//Convert word to numbers and find multiple of 5
	string curStringNumber; //Word to convert
	int curIntNumber; //Converted word 
	while (!Words.empty())
	{
		curIntNumber = 0;
		curStringNumber = Words.top();
		Words.pop();
		for (int i = curStringNumber.length()-1; i >= 0; i--)
		{
			if (curStringNumber[i] == One)
				curIntNumber += pow(2, curStringNumber.length() - (i+1));
		}
		if (curIntNumber != 0 && curIntNumber % 5 == 0)
			counter++;
	}
	cout << "Number of numbers multiple of 5 is " << counter;
	_getch();
	return 0;
}