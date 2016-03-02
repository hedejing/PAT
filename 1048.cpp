#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int N, M;

#define MAX_N 1000
#define MAX_M 5

int d[MAX_N][1 << MAX_M];

int main()
{
	cin >> N >> M;
	long long int res;
	if (M == 3 || M == 5)
	{
		if (N % 2 != 0 || N<2)
			res = 0;
		else
		{
			int re;
			if (M == 3)
				re = 3;
			else
				re = 8;
			res = 1;
			for (int i = 0; i < N / 2; i++)
			{
				res *= re;
				res = res % 1000000007;
			}
		}
	}
	else
	{
		vector<int> d(N, 0);
		d[0] = 1;
		d[1] = 5;
		for (int i = 2; i < N; i++)
			d[i] = d[i - 1]  + 5 * d[i - 2] ;
		res = d[N - 1];
	}
	cout << res << endl;
}