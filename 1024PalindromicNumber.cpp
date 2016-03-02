#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

struct BigNum {
	string s;

	BigNum(string _s)
		:s(_s) {}

	BigNum operator+(const BigNum &other) const {
		string sum;
		int sz = min(s.length(), other.s.length());
		int ap = 0;
		int i;
		for (i = 0; i < sz; i++)
		{
			char a = s[s.length() - 1 - i];
			char b = other.s[other.s.length() - 1 - i];
			int ab = a - '0' + b - '0' + ap;
			if (ab >= 10)
			{
				ap = 1;
				ab -= 10;
			}
			else
				ap = 0;
			char c = ab + '0';
			sum.push_back(c);
		}
		string longer = s.length() > other.s.length() ? s : other.s;
		for (; i < longer.size(); i++)
		{
			char a = longer[longer.size() - 1 - i];
			int aa = a - '0' + ap;
			if (aa >= 10)
			{
				ap = 1;
				aa -= 10;
			}
			else
				ap = 0;
			char c = aa + '0';
			sum.push_back(c);
		}
		if (ap == 1)
			sum.push_back('1');
		reverse(sum.begin(), sum.end());
		return BigNum(sum);
	}

	BigNum get_reverse() {
		string ns(s);
		reverse(ns.begin(), ns.end());
		return BigNum(ns);
	}

	bool isPali() {
		return _isPali(s, 0, s.length() - 1);
	}

	bool _isPali(string s, int begin, int end)
	{
		if (s[begin] == s[end])
		{
			begin++;
			end--;
			if (begin >= end)
				return true;
			else
				return _isPali(s, begin, end);
		}
		else
			return false;
	}
};

int main()
{
	string N;
	int K;
	cin >> N >> K;
	BigNum bn(N);
	int cnt = 0;
	while (true)
	{
		if (bn.isPali())
			break;
		cnt++;
		BigNum rbn = bn.get_reverse();
		bn = bn + rbn;
		if (cnt == K)
			break;
	}
	cout << bn.s << endl;
	cout << cnt << endl;
	system("pause");
}