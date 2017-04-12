#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "List.cpp"

using namespace std;

int main()
{
	ifstream file;
	ofstream outFile;
	outFile.open("out.txt");
	file.open("in.txt");
	string s = "";
	string temp = "";

	while (getline(file, temp))
	{
		s = s + temp + '\n';
	}








	cout << s[0] << endl;
	outFile << s;

	List<char> lc = List<char>('c');
	lc.add('b');
	lc.add('a');

	lc.print();




	int x;
	cin >> x;
}
