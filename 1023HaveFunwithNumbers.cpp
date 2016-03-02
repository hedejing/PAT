#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
	string s;
	cin >> s;
	int sz = s.length();
	string ns(s);
	int ap = 0;
	for (int i = sz - 1; i >= 0; i--)
	{
		int d = s[i] - '0';
		int v = 2 * d;
		int nd = v % 10;
		ns[i] = nd + '0' + ap;
		if (v >= 10)
			ap = 1;
		else
			ap = 0;
	}
	if (ap == 1)
	{
		cout << "No" << endl << "1" + ns << endl;
		system("pause");
		return 0;
	}
	int occur[10];
	memset(occur, 0, sizeof(int) * 10);
	for (char c : s)
		occur[c - '0']++;

	int noccur[10];
	memset(noccur, 0, sizeof(int) * 10);
	for (char c : ns)
		noccur[c - '0']++;

	bool res = true;
	for (int i = 0; i < 10;i++)
		if (occur[i] != noccur[i])
		{
			res = false;
			break;
		}
	if (res)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	cout << ns;
	system("pause");
}