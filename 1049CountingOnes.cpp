#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int cnt = 0;
	int k = log10(N);
	for (int i = 0; i <= k; i++)
	{
		int T = 1;
		for (int j = 0; j < i; j++)
			T = T * 10;
		int re = N / (T*10);
		int len = T;
		cnt += re*len;
		int left = N% (T*10);
		if (left >= len)
		{
			int ap = min(left - len + 1, len);
			cnt += ap;
		}
	}
	cout << cnt;
	system("pause");
}