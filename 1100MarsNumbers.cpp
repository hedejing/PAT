#include <iostream>
#include <string>
#include <sstream>
#include <map>
using namespace std;

int main()
{
	string fir[] = { "tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };
	string sec[] = { "tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };
	map<string, int> inv_fir, inv_sec;
	for (int i = 0; i < 13; i++)
	{
		inv_fir[fir[i]] = i;
		inv_sec[sec[i]] = i;
	}

	int N;
	cin >> N;
	cin.ignore();
	while (N--)
	{
		string s;
		getline(cin, s);
		if (s[0] >= '0' && s[0] <= '9')
		{
			stringstream ss;
			ss << s;
			int value;
			ss >> value;
			if (value <= 12)
			{
				cout << fir[value] << endl;
			}
			else
			{
				int second = value / 13;
				int first = value % 13;
				cout << sec[second];
				if (first > 0)
					cout << " " << fir[first] << endl;
				else
					cout << endl;
			}
		}
		else
		{
			stringstream ss;
			ss << s;
			string s1;
			ss >> s1;
			string s2;
			if (ss >> s2)
				cout << inv_sec[s1] * 13 + inv_fir[s2] << endl;
			else
			{
				if (inv_fir.find(s1) != inv_fir.end())
					cout << inv_fir[s1] << endl;
				else
					cout << inv_sec[s1]*13 << endl;
			}
		}
	}
	system("pause");
}