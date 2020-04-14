#include <conio.h>
#include <iostream>
#include <string>
#include <list>
#include <iterator>

using namespace std;

int main()
{
	list<string> ElementsList;//Creating list
	string bufferString;//Buffer for element of list
	int bufferKey;//Input by user
	bool endOfProg = false;//End program
	cout << "This programm shapes list where you can put different values and strings" << endl;
	cout << "and can show this list in normal or reverse order" << endl;
	while (!endOfProg)
	{
		cout << endl;
		cout << "Main menu. Press key to choose option" << endl;
		cout << "1. Put element into list" << endl;
		cout << "2. Show list in normal order" << endl;
		cout << "3. Show list in reverse order" << endl;
		cout << "4. Clear list" << endl;
		cout << "5. Exit" << endl;
		cin >> bufferKey;

		switch (bufferKey)
		{
		case 1://Add element
		{
			cout << "Input value you want to put to list" << endl;
			cin >> bufferString;
			ElementsList.push_back(bufferString);
			cout << "Element successfully added to list" << endl;
			break;
		}//end case 1
		case 2://Show in normal order
		{
			if (!ElementsList.empty())
			{
				copy(ElementsList.begin(), ElementsList.end(), ostream_iterator<string>(cout, "\n"));//Show list in normal order
			}
			else
				cout << "List is empty" << endl;
			break;
		}//end case 2
		case 3://Show in reverse order
		{
			if (!ElementsList.empty())
			{
				for (list<string>::iterator it = ElementsList.end(); it != ElementsList.begin();)//Show list in reverse order
				{
					it--;
					cout << *it << endl;
				}
			}
			else
				cout << "List is empty" << endl;
			break;
		}//end case 3
		case 4://Clear list
		{
			if (!ElementsList.empty())
			{
				ElementsList.clear();
				cout << "List successfully cleared" << endl;
			}
			else
				cout << "List is empty" << endl;
			break;
		}//end case 4
		case 5://Exit
		{
			endOfProg = true;
			break;
		}//end case 5
		default :
		{
			cout << "Unknown option" << endl;
			continue;
		}//end default
		}//end switch
	}
	cout << "Press any key" << endl;
	_getch();
	return 0;
}