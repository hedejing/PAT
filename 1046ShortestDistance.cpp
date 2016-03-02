#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 100001

int main()
{
	int N;
	cin >> N;
	int dist[MAX];
	int dfrom1[MAX];
	dfrom1[1] = 0;
	int total = 0;
	for (int i = 1; i <= N; i++)
	{
		cin >> dist[i];
		dfrom1[i + 1] = dfrom1[i] + dist[i];
		total += dist[i];
	}
	int M;
	cin >> M;
	while (M--)
	{
		int x, y;
		cin >> x >> y;
		if (x > y)
		{
			int temp = x;
			x = y;
			y = temp;
		}
		int d = dfrom1[y] - dfrom1[x];
		//cout << min(d1, total - d1) << endl;
		int r = min(d, total - d);
		printf("%d\n", r);
	}
	system("pause");
}