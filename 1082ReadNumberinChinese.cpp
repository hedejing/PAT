#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	const string numbers[] = { "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu" };
	const string tens[] = { "Qian", "Bai", "Shi" };
	string input;
	vector<string> toprint;
	cin >> input;
	if (input == "0")
	{
		cout << "ling";
		return 0;
	}

	if (input[0] == '-')
	{
		toprint.push_back("Fu");
		input = input.substr(1, input.length() - 1);
	}
	if (input.length() == 9)
	{
		int digit = input[0] - '0';
		toprint.push_back(numbers[digit]);
		toprint.push_back("Yi");
		int i;
		for (i = 1; i < input.length(); i++)
			if (input[i] != '0')
				break;
		if (i > 1 && i != input.length())
			toprint.push_back("ling");
		input = input.substr(i, input.length() - 1);

	}
	reverse(input.begin(), input.end());
	if (input.length() >= 5 && input.length() <= 8)
	{
		int sz = input.length() - 4;
		string s1 = input.substr(4, sz);
		bool last_is_zero = false;
		for (int i = 3; i >= 0; i--)
		{
			if (i >= sz)
				continue;
			char ch = s1[i];
			if (ch == '0')
			{
				if (!last_is_zero)
				{
					bool printling = false;
					for (int j = i - 1; j >=0 ; j--)
						if (s1[j] != '0')
						{
							printling = true;
							break;
						}
					if (printling)
						toprint.push_back("ling");
					last_is_zero = true;
				}
				else
					continue;
			}
			else
			{
				int digit = ch - '0';
				toprint.push_back(numbers[digit]);
				if (i != 0)
					toprint.push_back(tens[3-i]);
				last_is_zero = false;
			}
		}
		toprint.push_back("Wan");
		int pos;
		for (pos = 3; pos >= 0; pos--)
			if (pos != '0')
				break;
		if (pos != 3 && pos != -1)
			toprint.push_back("ling");
		input = input.substr(0, pos + 1);
	}
	bool last_is_zero = false;
	for (int i = 3; i >= 0; i--)
	{
		if (i >= input.length())
			continue;

		char ch = input[i];
		if (ch == '0')
		{
			if (!last_is_zero)
			{
				bool printling = false;
				for (int j = i - 1; j >= 0; j--)
					if (input[j] != '0')
					{
						printling = true;
						break;
					}
				if (printling)
					toprint.push_back("ling");
				last_is_zero = true;
			}
			else
				continue;
		}
		else
		{
			int digit = ch - '0';
			toprint.push_back(numbers[digit]);
			if (i != 0)
				toprint.push_back(tens[3 - i]);
			last_is_zero = false;
		}
	}
	bool first = true;
	for (auto s : toprint)
	{
		if (!first)
			cout << " ";
		first = false;
		cout << s;
	}

	system("pause");
}