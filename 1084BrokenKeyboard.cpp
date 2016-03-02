#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <iterator>
using namespace std;

string upperCase(string input)
{
	string output(input);
	for (int i = 0; i < output.length(); i++)
	{
		if (output[i] >= 'a' && output[i] <= 'z')
			output[i] = output[i] + 'A' - 'a';
	}
	return output;
}

int main()
{
	string origin_str, typeout_str;
	cin >> origin_str >> typeout_str;
	origin_str = upperCase(origin_str);
	typeout_str = upperCase(typeout_str);
	set<char> occur;
	for (auto c : origin_str)
	{
		if (occur.find(c) == occur.end())
		{
			occur.insert(c);
			//check
			if (typeout_str.find(c) == string::npos)
				cout << c;
		}
	}
	system("pause");
}