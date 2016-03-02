#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_N 200
#define MAX_M 200
#define MAX_L 10000
int d[MAX_M][MAX_L];
int fav[MAX_M];
int stripe[MAX_L];

int main()
{
	int N;
	cin >> N;
	int M;
	cin >> M;
	for (int i = 0; i < M; i++)
		cin >> fav[i];
	int L;
	cin >> L;
	for (int i = 0; i < L; i++)
		cin >> stripe[i];
	for (int i = 0; i < M; i++)
		for (int j = 0; j < L; j++)
			d[i][j] = 0;

	int cnt = 0;
	for (int i = 0; i < L; i++)
	{
		if (stripe[i] == fav[0])
			cnt++;
		d[0][i] = cnt;
	}
	for (int i = 1; i < M; i++)
	{
		d[i][0] = d[i - 1][0];
		if (fav[i] == stripe[0])
			 d[i][0]++;
	}
	for (int i = 1; i < M; i++)
	{
		for (int j = 1; j < L; j++)
		{
			if (fav[i] == stripe[j])
				d[i][j] = d[i][j - 1] + 1;
			else
				d[i][j] = max(d[i - 1][j], d[i][j - 1]);
		}
	}
	int max_len = -1;
	for (int i = 0; i < M; i++)
	{
		if (d[i][L - 1] > max_len)
			max_len = d[i][L - 1];
	}
	cout << max_len;
	system("pause");
}