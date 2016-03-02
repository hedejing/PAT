#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int main()
{
	string s;
	cin >> s;
	if (s.length() < 4)
	{
		string zeros(4 - s.length(), '0');
		s = zeros + s;
	}
	char c = s[0];
	bool same = true;
	for (int i = 1; i < 4; i++)
	{
		if (s[i] != c)
		{
			same = false;
			break;
		}
	}

	if (same)
		cout << s << " - " << s << " = " << "0000";
	else
	{
		while (true)
		{
			sort(s.begin(), s.end());
			string nde = s;
			reverse(s.begin(), s.end());

			stringstream ss;
			int a, b;
			ss << s << " " << nde;
			ss >> a >> b;
			int value = a - b;
			stringstream sss;
			string ns;
			sss << value;
			sss >> ns;
			if (ns.length() < 4)
			{
				string zeros(4 - ns.length(), '0');
				ns = zeros + ns;
			}
			cout << s << " - " << nde << " = " << ns << endl;
			if (value == 6174)
				break;
			s = ns;
			//stringstream sss;
			//sss << a - b;
			//sss >> s;
		}
	}
	system("pause");
}