#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <math.h>
using namespace std;

void prime_factors(map<long int, long int> & record, long int& target, const vector<long int> &primes, int cnt)
{
	for (int i = 0; i < cnt;i++)
	{
		int prime = primes[i];
		if (target < prime)
			return;
		long int cnt = 0;
		long int copy = target;
		while (copy%prime == 0)
		{
			copy /= prime;
			cnt++;
		}
		if (cnt >= 1)
		{
			record[prime] = cnt;
			target = copy;
			if (target == 1)
				return;
		}
	}
}

int main()
{
	long int T;
	set<long int> visit;
	cin >> T;
	long int target = sqrt(T + 0.5);
	vector<bool> vis(target+1, false);
	for (long int i = 2; i <= target; i++)
	{
		if (!vis[i])
		{
			for (long int j = i*i; j <= target; j += i)
				vis[j] = true;
		}
	}
	vector<long int> primes(target, 0);
	int cnt = 0;
	for (long int i = 2; i <= target; i++)
	{
		if (!vis[i])
			primes[cnt++] = i;
	}
	map<long int, long int> record;
	long int copy = T;
	prime_factors(record, T, primes, cnt);
	cout << copy << "=";
	bool first = true;

	if (record.size() == 0)
		cout << copy;
	else
	{
		if (T != 1)
			record[T] = 1;
		for (auto i : record)
		{
			if (!first)
				cout << "*";
			cout << i.first;
			if (i.second >= 2)
				cout << "^" << i.second;
			first = false;
		}
		
	}
	system("pause");
}