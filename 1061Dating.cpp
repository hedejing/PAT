#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string days[] = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };

int main()
{
	string a, b, c, d;
	cin >> a >> b >> c >> d;
	bool first = true;
	int minsz = min(a.length(), b.length());
	for (int i = 0; i < minsz;i++)
	{
		char ch = a[i];
		if (first)
		{
			if (ch >= 'A' && ch <= 'G' && b[i] == ch)
			{
				cout << days[ch - 'A'] << " ";
				first = false;
			}
		}
		else
		{
			if (ch == b[i] && ((ch >= 'A' && ch <= 'N') || (ch >= '0' && ch <= '9')))
			{
				int hour;
				if (ch >= 'A' && ch <= 'N')
					cout << (int)(ch - 'A' + 10);
				else
					cout << "0" << (int)(ch - '0');
				cout << ":";
				break;
			}
		}
	}
	minsz = min(c.length(), d.length());
	for (int i = 0; i < minsz; i++)
	{
		if (c[i] == d[i] && ((c[i] >= 'a' && c[i] <= 'z' )|| (c[i] >= 'A' && c[i] <= 'Z')))
		{
			printf("%02d", i);
			break;
		}
	}
	system("pause");
}