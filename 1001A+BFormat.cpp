#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int main()
{
	long long int a, b;
	cin >> a >> b;
	long long int result;
	result = a + b;
	stringstream ss;
	ss << result;
	string s;
	ss >> s;
	string ns;
	int cnt = 0;
	bool neg = false;
	if (s[0] == '-')
	{
		neg = true;
		reverse(s.begin(), s.end());
		s.pop_back();
	}
	else
		reverse(s.begin(), s.end());

	for (char c : s)
	{
		ns.push_back(c);
		cnt++;
		if (cnt%3==0 && cnt!=s.length())
		{
			ns.push_back(',');
		}
	}
	if (neg)
		ns.push_back('-');
	reverse(ns.begin(), ns.end());
	cout << ns;
	system("pause");
}