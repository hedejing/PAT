#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int Digit(char c)
{
	int r;
	if (c >= '0' &&c <= '9')
		r = c - '0';
	else
		r = c - 'a' + 10;
	return r;
}

long long unsigned Get(long long unsigned radix, string given)
{
	long long unsigned value = 0;
	for (int i = 0; i < given.length(); i++)
	{
		value *= radix;
		value += Digit(given[i]);
	}
	return value;
}

string given, tryto;

bool Find(long long unsigned begin, long long unsigned end, long long unsigned target, long long unsigned &pos)
{
	long long unsigned mid = (begin + end) / 2;
	long long unsigned tryvalue = Get(mid, tryto);
	if (begin == end)
	{
		if (Get(begin, tryto) == target)
		{
			pos = begin;
			return true;
		}
		else
			return false;
	}
	if (begin > end)
		return false;
	if (tryvalue > target)
		return Find(begin, mid, target, pos);
	else if (tryvalue < target)
		return Find(mid+1, end, target, pos);
	else
	{
		pos = mid;
		return true;
	}
}

int main()
{
	string N1, N2;
	long long unsigned tag, radix;
	cin >> N1 >> N2 >> tag >> radix;
	given = tag == 1 ? N1 : N2;
	tryto = tag == 1 ? N2 : N1;
	long long unsigned value = Get(radix, given);
	int maxvalue = Digit(tryto[0]);
	for (auto c : tryto)
		maxvalue = max(maxvalue, Digit(c));
	if (tryto.length() == 1)
	{
		if (Get(maxvalue + 1, tryto) == value)
			cout << maxvalue + 1;
		else
			cout << "Impossible";
		system("pause");
		return 0;
	}

	long long unsigned rightradix;
	long long unsigned upper;
	if (Get(radix, tryto) >= value)
		upper = radix;
	else
		upper = value;
	if(Find(maxvalue + 1, upper, value, rightradix))
		cout << rightradix;
	else
		cout << "Impossible";
	system("pause");
}
