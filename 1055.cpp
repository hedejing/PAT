#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX 100
vector<int> tree[MAX+1];
int N, M;

int d[MAX+1][MAX+1];

void post(int pa, int node)
{
	for (int child : tree[node])
	{
		if (child == pa)
			continue;
		post(node, child);
		for (int m = M; m >= 1; m--)
			for (int m_child = 1; m_child < m; m_child++)
				d[node][m] = max(d[node][m], d[node][m - m_child] + d[child][m_child]);
	}
}

int main()
{
	cin >> N >> M;
	memset(d, 0, sizeof(d));
	for (int i = 1; i <= N; i++)
		cin >> d[i][1];
	N--;
	while (N--)
	{
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	post(-1, 1);
	cout << d[1][M] << endl;
}