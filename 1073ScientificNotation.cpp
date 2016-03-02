#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int main()
{
	string input;
	cin >> input;
	replace(input.begin(), input.end(), 'E', ' ');
	string digits;
	int exp;
	stringstream ss;
	ss << input;
	ss >> digits >> exp;
	string str;
	bool pos = false;
	if (digits[0] == '+')
		pos = true;
	if (!pos)
		cout << "-";
	for (char c : digits)
		if (c != '.'&&c!='+'&&c!='-')
			str.push_back(c);
	if (exp < 0)
	{
		for (int i = 0; i < -exp; i++)
			str = "0" + str;
		for (int i = 0; i < str.size(); i++)
		{
			if (i == 1)
				cout << ".";
			cout << str[i];
		}
	}
	else
	{
		if (exp > str.size() - 1)
		{
			string zeros(exp - str.size() + 1, '0');
			str.append(zeros);
			cout << str;
		}
		else
		{
			int dotpos = 1 + exp;
			for (int i = 0; i < str.size(); i++)
			{
				if (i == dotpos)
					cout << ".";
				cout << str[i];
			}
		}
	}
	system("pause");
}