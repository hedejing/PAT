#include <iostream>
#include <algorithm>

const int MAX = 100000;
using namespace std;
long long int a[MAX];

int Find(long long int target, int begin, int end)
{
	if (begin == end)
	{
		if (a[begin] > target)
			return begin-1;
		else
			return begin;
	}

	int mid = (begin + end) / 2;
	if (target < a[mid])
		return Find(target, begin, mid);
	else if (target > a[mid])
		return Find(target, mid + 1, end);
	else
		return mid;
}

int main()
{
	int N, p;
	cin >> N >> p;
	for (int i = 0; i < N; i++)
		cin >> a[i];
	sort(a, a + N);
	int maxlen = 0;
	int pos;
	for (int i = 0; i < N; i++)
	{
		long long int target = a[i] * p;
		if (i == 0)
			pos = Find(target, 0, N - 1);
		else
			pos = Find(target, pos, N - 1);
		int j;
		for (j = pos + 1; j < N; j++)
			if (a[j] > p*a[i])
				break;
		pos = j - 1;
		int len = pos - i + 1;
		if (len > maxlen)
		{
			//cout << i << "-" << pos << endl;
			maxlen = len;
		}
	}
	cout << maxlen;
	system("pause");
}