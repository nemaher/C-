#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>

using namespace std;

int main()
{
	ifstream file;
	ofstream outFile;

	string fileName; 
	cout << "Enter a file name to check if it is balanced.";
	cin >> fileName;
	file.open(fileName);

	string s = "";
	string leftOvers = " ";
	string temp = "";

	list<char> parenList = list<char>();
	list<char> curlyList = list<char>();
	list<char> straightList = list<char>();

	while (getline(file, temp))
	{
		s = temp + '\n';
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '(')
			{
				parenList.push_front(s[i]);
			}
			else if (s[i] == ')')
			{
				if (parenList.size() != 0)
				{
					parenList.pop_front();
				}
				else
				{
					leftOvers += s[i];
				}
			}
			else if (s[i] == '{')
			{
				curlyList.push_front(s[i]);
			}
			else if (s[i] == '}')
			{
				if (curlyList.size() != 0)
				{
					curlyList.pop_front();
				}
				else
				{
					leftOvers += s[i];
				}
			}
			else if (s[i] == '[')
			{
				straightList.push_front(s[i]);
			}
			else if (s[i] == ']')
			{
				if (straightList.size() != 0)
				{
					straightList.pop_front();
				}
				else
				{
					leftOvers += s[i];
				}
			}
		}

		cout << s;
	}

	if (parenList.size() > 0)
	{
		while (parenList.size() != 0)
		{
			leftOvers += parenList.front();
			parenList.pop_front();
		}
	}
	if (curlyList.size() > 0)
	{
		while (curlyList.size() != 0)
		{
			leftOvers += curlyList.front();
			curlyList.pop_front();
		}
	}
	if (straightList.size() > 0)
	{
		while (straightList.size() != 0)
		{
			leftOvers += straightList.front();
			straightList.pop_front();
		}
	}

	if (leftOvers.size() != 0)
	{
		cout << "Your code has to many " + leftOvers;
	}
	else
	{
		cout << "Your Code is Balanced";
	}





	int x;
	cin >> x;
}