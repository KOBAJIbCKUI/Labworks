#include <conio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct student
{
	int groupNumber;
	string surname;
	double averMark;
};

vector<student> Sorting(vector<student> Students)//Sorting students by average mark
{
	student studentBuffer;
	for (int i = 0; i < Students.size()-1; i++)
	{
		if (Students[i].averMark < Students[i + 1].averMark)
		{
			studentBuffer = Students[i];
			Students[i] = Students[i + 1];
			Students[i + 1] = studentBuffer;
			i = 0;
		}//Sorting by brute force
	}
	return Students;
}

void Sorting(student* Students, int numberOfStudents)//Sorting students by number of group
{
	student studentBuffer;
	for (int i = 0; i < numberOfStudents - 1; i++)
	{
		if (Students[i].groupNumber > Students[i + 1].groupNumber)
		{
			studentBuffer = Students[i + 1];
			Students[i + 1] = Students[i];
			Students[i] = studentBuffer;
			i = 0;
		}//Sorting by brute force
	}
}

int main()
{
	const int numberOfStudents = 10;
	cout << "This program makes a sheet of students' perfomance" << endl;
	cout << "and shows it divided into groups." << endl;
	cout << "The sheet is sorted from the highest average score for session to the lowest" << endl << endl;
	
	student* Students = new student[numberOfStudents];
	Students[0] = { 1, "Ivanov", 85.5 };
	Students[1] = { 3, "Petrov", 92.3 };
	Students[2] = { 2, "Vasilev", 74.1 };
	Students[3] = { 3, "Kuzmina", 96.6 };
	Students[4] = { 1, "Lahov", 83.2 };
	Students[5] = { 3, "Didik", 67.9 };
	Students[6] = { 2, "Schevchenko", 68.3 };
	Students[7] = { 4, "Michaylov", 98.1 };
	Students[8] = { 1, "Serov", 84.8 };
	Students[9] = { 5, "Karpova", 91.5 };
	cout << "Initial list:" << endl;
	for (int i = 0; i < numberOfStudents; i++)
	{
		cout << "Group number: " << Students[i].groupNumber;
		cout << " Surname: " << Students[i].surname;
		cout << " Average mark: " << Students[i].averMark << endl;
	}
	cout << endl;

	Sorting(Students, numberOfStudents);//Sorting by number of group

	int numberOfGroups = 0;
	int prevGroupNumber = -1;
	for (int i = 0; i < numberOfStudents; i++)//Finding out the number of groups
	{
		if (Students[i].groupNumber != prevGroupNumber)
		{
			numberOfGroups++;
			prevGroupNumber = Students[i].groupNumber;
		}
	}

	vector<student>* Groups = new vector<student>[numberOfGroups];//Making dynamical array of vectors
	for (int i = 0; i < numberOfStudents; i++)//Forming groups
	{
		Groups[Students[i].groupNumber - 1].push_back(Students[i]);
	}
	
	for (int i = 0; i < numberOfGroups; i++)//Sorting every vector by average mark
	{
		Groups[i] = Sorting(Groups[i]);
	}
	cout << "End sheet: " << endl;
	for (int i = 0; i < numberOfGroups; i++)//Showing end sheet
	{
		cout << "Group " << i + 1 << endl;
		for (int j = 0; j < Groups[i].size(); j++)
		{
			cout << "Surname: " << Groups[i][j].surname;
			cout << " Average mark: " << Groups[i][j].averMark << endl;
		}
	}
	_getch();
	return 0;
}