#include <iostream>
#include <set>
using namespace std;

#define MAX_N 1001

int find(int i, int p[])
{
	return p[i] == i ? i : p[i] = find(p[i], p);
}

int check(int occ, const set<pair<int, int>> & edges, int N)
{
	int p[MAX_N];
	for (int i = 1; i <= N; i++)
		p[i] = i;
	
	for (auto e : edges)
	{
		if (e.first == occ || e.second == occ)
			continue;
		int rx = find(e.first, p);
		int ry = find(e.second, p);
		p[rx] = ry;
	}

	set<int> roots;
	for (int i = 1; i <= N; i++)
	{
		if (i == occ)
			continue;
		int r = find(i, p);
		roots.insert(r);
	}

	int result = roots.size() - 1;
	return result;
}


int main()
{
	int N, M, K;
	cin >> N >> M >> K;

	set<pair<int, int>> edges;
	while (M--)
	{
		int x, y;
		cin >> x >> y;
		edges.insert({ x,y });
	}
	while (K--)
	{
		int c;
		cin >> c;
		int res = check(c, edges, N);
		cout << res << endl;
	}
	system("pause");
}