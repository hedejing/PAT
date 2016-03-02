#include <string>
#include <sstream>
#include <iostream>

using namespace std;

int main()
{
	string input;
	cin >> input;
	int sum = 0;
	for (char c : input)
	{
		stringstream ss;
		ss << c;
		int value;
		ss >> value;
		sum += value;
	}
	stringstream ss;
	ss << sum;
	string output;
	ss >> output;
	int cnt = 0;
	for (char c : output)
	{
		switch (c)
		{
		case '0':
			cout << "zero";
			break;
		case '1':
			cout << "one";
			break;
		case '2':
			cout << "two";
			break;
		case '3':
			cout << "three";
			break;
		case '4':
			cout << "four";
			break;
		case '5':
			cout << "five";
			break;
		case '6':
			cout << "six";
			break;
		case '7':
			cout << "seven";
			break;
		case '8':
			cout << "eight";
			break;
		case '9':
			cout << "nine";
			break;
		default:
			break;
		}
		cnt++;
		if (cnt < output.size())
			cout << " ";
	}
	system("pause");

}