#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

#define MAX_N 1000
#define MAX_M 10

int best[MAX_N][1<<MAX_M];
int N, M, Q;
int waste[MAX_N];

int check(int s)
{
	int cnt = 0;
	while (s)
	{
		if (s % 2 == 1)
			cnt++;
		s = s >> 1;
	}

	return cnt;
}

int get(int i, int j)
{
	if (i == N)
		return 0;
	if (best[i][j] >= 0)
		return best[i][j];
	else
	{
		if (check(j) == Q)
			best[i][j] = get(i + 1, j/2);
		else
			best[i][j] = max(get(i + 1, j/2), get(i + 1, j/2 + pow(2, M-2)) + waste[i]);
		return best[i][j];
	}
}

int main()
{
	cin >> N >> M >> Q;
	memset(best, -1, sizeof(best));   
	for (int i = 0; i < N; i++)
		cin >> waste[i];
	cout << get(0, 0) << endl;
}