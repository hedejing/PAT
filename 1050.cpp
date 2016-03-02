#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define MAX 100000
vector<int> tree[MAX];

void dfs(int pa, int node, int level, int &len, int &leaf)
{
	if (tree[node].size()==1 && tree[node].front()==pa)
	{
		if (level > len)
		{
			len = level;
			leaf = node;
		}
		return;
	}
	for (int child : tree[node])
		if(child!=pa)
			dfs(node, child, level + 1, len, leaf);
}

int main()
{
	int N;
	cin >> N;
	N--;
	while (N--)
	{
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	int chose = 1;
	int len = -1, leaf = -1;
	dfs(-1, chose, 0, len, leaf);
	int alen = -1, aleaf = -1;
	dfs(-1, leaf, 0, alen, aleaf);
	cout << alen << endl;
}