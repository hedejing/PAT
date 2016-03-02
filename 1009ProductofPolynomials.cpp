#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
	map<int, double> a, b;
	int K;
	cin >> K;
	while (K--)
	{
		int exp;
		double coe;
		cin >> exp >> coe;
		a[exp] = coe;
	}
	cin >> K;
	while (K--)
	{
		int exp;
		double coe;
		cin >> exp >> coe;
		b[exp] = coe;
	}
	map<int, double> r;
	for (auto ai : a)
		for (auto bi : b)
		{
			int sexp = ai.first + bi.first;
			double scoe = ai.second *bi.second;
			r[sexp] += scoe;
		}
	int cnt = 0;
	for (auto i : r)
		if (i.second != 0)
			cnt++;
	cout << cnt;
	for (auto i = r.rbegin(); i != r.rend(); i++)
		if (i->second != 0)
			printf(" %d %.1f", i->first, i->second);
	system("pause");
}
