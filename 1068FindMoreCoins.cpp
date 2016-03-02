#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_N 10001
#define MAX_M 101

int d[MAX_M][MAX_N];
int coins[MAX_N];
int N, M;

int get(int i, int j)
{
	if (i < 0 || j > N)
		return 0;
	if (i == 0)
		return d[i][j] = 1;

	if (d[i][j] >= 0)
		return d[i][j];
	else
	{
		int r1 = get(i - coins[j], j + 1);
		int r2 = get(i, j + 1);
		if (r1 == 1 || r2 == 1)
			d[i][j] = 1;
		else
			d[i][j] = 0;
		return d[i][j];
	}
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> coins[i];
	sort(coins, coins + N);
	for (int i = 0; i <= M; i++)
		for (int j = 0; j <= N; j++)
			d[i][j] = -1;
	int r = get(M, 0);
	if (r == 0)
	{
		cout << "No Solution";
		system("pause");
		return 0;
	}
	bool first = true;
	for (int i = 0; i < N; i++)
	{
		if (d[M - coins[i]][i + 1] == 1)
		{
			M -= coins[i];
			if (!first)
				cout << " ";
			cout << coins[i];
			first = false;
			if (M == 0)
				break;
		}
	}
	system("pause");

}